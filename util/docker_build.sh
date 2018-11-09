#!/bin/bash

USAGE="Usage: $0 [keyboard[:keymap[:target]]]"

# Check preconditions
if [[ $* =~ "--help" ]]; then
    echo "$USAGE"
    exit 0
elif [[ $# -gt 1 ]]; then
    echo "$USAGE" >&2
    exit 1
elif ! command -v docker &>/dev/null; then
    echo "Error: docker not found" >&2
    echo "See https://docs.docker.com/install/#supported-platforms for installation instructions" >&2
    exit 2
fi

# Determine arguments
if [[ $# -eq 0 ]]; then
    read -rp "keyboard=" keyboard
    [[ -n $keyboard ]] && read -rp "keymap=" keymap
    [[ -n $keymap   ]] && read -rp "target=" target
else
    IFS=':' read -r keyboard keymap target x <<< "$1"
    if [[ -n $x ]]; then
        echo "$USAGE" >&2
        exit 1
    fi
fi
if [[ -n $target ]]; then
    if [[ $(uname) == "Linux" ]] || docker-machine active &>/dev/null; then
        usb_args="--privileged -v /dev/bus/usb:/dev/bus/usb"
    else
        echo "Error: target requires docker-machine to work on your platform" >&2
        echo "See http://gw.tnode.com/docker/docker-machine-with-usb-support-on-windows-macos" >&2
        exit 3
    fi
fi
dir=$(pwd -W 2>/dev/null) || dir=$PWD  # Use Windows path if on Windows

# Run container and build firmware
docker run --rm $usb_args -v "$dir":/qmk_firmware qmkfm/qmk_firmware \
    make "$keyboard${keymap:+:$keymap}${target:+:$target}"
