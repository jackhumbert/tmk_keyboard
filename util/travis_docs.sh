#!/bin/bash

source util/travis_push.sh

if [[ "$TRAVIS_COMMIT_MESSAGE" != *"[skip docs]"* ]] ; then 
	if git diff --name-only ${TRAVIS_COMMIT_RANGE} | grep -e '^quantum/' -e '^tmk_core/' -e '^docs/internals_.*'; then
		echo "Generating internal docs..."
		rm -rf doxygen
		doxygen Doxyfile
		moxygen -q -a -g -o docs/internals_%s.md doxygen/xml
		git add docs/internals_*
		git commit -m'autogenerated internal docs for ${TRAVIS_COMMIT_RANGE}' || true
	fi
fi
