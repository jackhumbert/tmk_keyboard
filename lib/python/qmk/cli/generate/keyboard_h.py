"""Used by the make system to generate keyboard.h from info.json.
"""
from milc import cli

from qmk.decorators import automagic_keyboard, automagic_keymap
from qmk.info import info_json
from qmk.keyboard import keyboard_completer, keyboard_folder
from qmk.path import is_keyboard, normpath


def would_populate_layout_h(keyboard):
    """Detect if a given keyboard is doing data driven layouts
    """
    # Build the info.json file
    kb_info_json = info_json(keyboard)

    for layout_name in kb_info_json['layouts']:
        if kb_info_json['layouts'][layout_name]['c_macro']:
            continue

        if 'matrix' not in kb_info_json['layouts'][layout_name]['layout'][0]:
            cli.log.debug('%s/%s: No matrix data!', keyboard, layout_name)
            continue

        return True

    return False


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', type=keyboard_folder, completer=keyboard_completer, help='Keyboard to generate keyboard.h for.')
@cli.subcommand('Used by the make system to generate keyboard.h from info.json', hidden=True)
@automagic_keyboard
@automagic_keymap
def generate_keyboard_h(cli):
    """Generates the keyboard.h file.
    """
    # Determine our keyboard(s)
    if not cli.config.generate_keyboard_h.keyboard:
        cli.log.error('Missing parameter: --keyboard')
        cli.subcommands['info'].print_help()
        return False

    if not is_keyboard(cli.config.generate_keyboard_h.keyboard):
        cli.log.error('Invalid keyboard: "%s"', cli.config.generate_keyboard_h.keyboard)
        return False

    has_layout_h = would_populate_layout_h(cli.config.generate_keyboard_h.keyboard)

    # Build the layouts.h file.
    keyboard_h_lines = ['/* This file was generated by `qmk generate-keyboard-h`. Do not edit or copy.' ' */', '', '#pragma once', '#include "quantum.h"']

    if not has_layout_h:
        keyboard_h_lines.append('#pragma error("<keyboard>.h is only optional for data driven keyboards - kb.h == bad times")')

    # Show the results
    keyboard_h = '\n'.join(keyboard_h_lines) + '\n'

    if cli.args.output:
        cli.args.output.parent.mkdir(parents=True, exist_ok=True)
        if cli.args.output.exists():
            cli.args.output.replace(cli.args.output.parent / (cli.args.output.name + '.bak'))
        cli.args.output.write_text(keyboard_h)

        if not cli.args.quiet:
            cli.log.info('Wrote keyboard_h to %s.', cli.args.output)

    else:
        print(keyboard_h)
