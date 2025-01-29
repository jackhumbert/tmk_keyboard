import contextlib
from argcomplete.completers import FilesCompleter

from milc import cli

import qmk.path
from qmk.info import get_modules
from qmk.keyboard import keyboard_completer, keyboard_folder
from qmk.commands import dump_lines
from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE
from qmk.community_modules import MODULE_API_LIST, MODULE_API_VERSION, load_module_jsons


@contextlib.contextmanager
def _render_api_guard(lines, api):
    if api.guard:
        lines.append(f'#if {api.guard}')
    yield
    if api.guard:
        lines.append(f'#endif  // {api.guard}')


def _render_api_header(api):
    lines = []
    if api.header:
        lines.append('')
        with _render_api_guard(lines, api):
            lines.append(f'#include <{api.header}>')
    return lines


def _render_keycodes(module_jsons):
    lines = []
    lines.append('')
    lines.append('enum {')
    first = True
    for module_json in module_jsons:
        keycodes = module_json.get('keycodes', [])
        for keycode in keycodes:
            key = keycode.get('key', None)
            if first:
                lines.append(f'    {key} = QK_COMMUNITY_MODULE,')
                first = False
            else:
                lines.append(f'    {key},')
    lines.append('    LAST_COMMUNITY_MODULE_KEY')
    lines.append('};')
    lines.append('_Static_assert((int)LAST_COMMUNITY_MODULE_KEY <= (int)(QK_COMMUNITY_MODULE_MAX+1), "Too many community module keycodes");')
    return lines


def _render_api_declarations(api, module, user_kb=True):
    lines = []
    lines.append('')
    with _render_api_guard(lines, api):
        if user_kb:
            lines.append(f'{api.ret_type} {api.name}_{module}_user({api.args});')
            lines.append(f'{api.ret_type} {api.name}_{module}_kb({api.args});')
        lines.append(f'{api.ret_type} {api.name}_{module}({api.args});')
    return lines


def _render_api_implementations(api, module):
    lines = []
    lines.append('')
    with _render_api_guard(lines, api):
        # _user
        lines.append(f'__attribute__((weak)) {api.ret_type} {api.name}_{module}_user({api.args}) {{')
        if api.ret_type == 'bool':
            lines.append('    return true;')
        else:
            pass
        lines.append('}')
        lines.append('')

        # _kb
        lines.append(f'__attribute__((weak)) {api.ret_type} {api.name}_{module}_kb({api.args}) {{')
        if api.ret_type == 'bool':
            lines.append(f'    if(!{api.name}_{module}_user({api.call_params})) {{ return false; }}')
            lines.append('    return true;')
        else:
            lines.append(f'    {api.name}_{module}_user({api.call_params});')
        lines.append('}')
        lines.append('')

        # module (non-suffixed)
        lines.append(f'__attribute__((weak)) {api.ret_type} {api.name}_{module}({api.args}) {{')
        if api.ret_type == 'bool':
            lines.append(f'    if(!{api.name}_{module}_kb({api.call_params})) {{ return false; }}')
            lines.append('    return true;')
        else:
            lines.append(f'    {api.name}_{module}_kb({api.call_params});')
        lines.append('}')
    return lines


def _render_core_implementation(api, modules):
    lines = []
    lines.append('')
    with _render_api_guard(lines, api):
        lines.append(f'{api.ret_type} {api.name}_modules({api.args}) {{')
        if api.ret_type == 'bool':
            lines.append('    return true')
        for module in modules:
            if api.ret_type == 'bool':
                lines.append(f'        && {api.name}_{module}({api.call_params})')
            else:
                lines.append(f'    {api.name}_{module}({api.call_params});')
        if api.ret_type == 'bool':
            lines.append('    ;')
        lines.append('}')
    return lines


@cli.argument('-o', '--output', arg_only=True, type=qmk.path.normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', arg_only=True, type=keyboard_folder, completer=keyboard_completer, help='Keyboard to generate community_modules.h for.')
@cli.argument('filename', nargs='?', type=qmk.path.FileType('r'), arg_only=True, completer=FilesCompleter('.json'), help='Configurator JSON file')
@cli.subcommand('Creates a community_modules.h from a keymap.json file.')
def generate_community_modules_h(cli):
    """Creates a community_modules.h from a keymap.json file
    """
    if cli.args.output and cli.args.output.name == '-':
        cli.args.output = None

    lines = [
        GPL2_HEADER_C_LIKE,
        GENERATED_HEADER_C_LIKE,
        '#pragma once',
        '#include <stdint.h>',
        '#include <stdbool.h>',
        '#include <keycodes.h>',
        '',
        f'#define COMMUNITY_MODULES_API_VERSION {MODULE_API_VERSION}',
        f'#define ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(x) _Static_assert((x) <= COMMUNITY_MODULES_API_VERSION, "Community module requires higher version of QMK modules API -- needs: " #x ", current: {MODULE_API_VERSION}.")',
        '',
        'typedef struct keyrecord_t keyrecord_t; // forward declaration so we don\'t need to include quantum.h',
        '',
    ]

    modules = get_modules(cli.args.keyboard, cli.args.filename)
    module_jsons = load_module_jsons(modules)
    if len(modules) > 0:
        lines.extend(_render_keycodes(module_jsons))

        for api in MODULE_API_LIST:
            lines.extend(_render_api_header(api))

        for module in modules:
            lines.append('')
            lines.append(f'// From module: {module}')
            for api in MODULE_API_LIST:
                lines.extend(_render_api_declarations(api, module))
        lines.append('')

        lines.append('// Core wrapper')
        for api in MODULE_API_LIST:
            lines.extend(_render_api_declarations(api, 'modules', user_kb=False))

    dump_lines(cli.args.output, lines, cli.args.quiet, remove_repeated_newlines=True)


@cli.argument('-o', '--output', arg_only=True, type=qmk.path.normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', arg_only=True, type=keyboard_folder, completer=keyboard_completer, help='Keyboard to generate community_modules.c for.')
@cli.argument('filename', nargs='?', type=qmk.path.FileType('r'), arg_only=True, completer=FilesCompleter('.json'), help='Configurator JSON file')
@cli.subcommand('Creates a community_modules.c from a keymap.json file.')
def generate_community_modules_c(cli):
    """Creates a community_modules.c from a keymap.json file
    """
    if cli.args.output and cli.args.output.name == '-':
        cli.args.output = None

    lines = [
        GPL2_HEADER_C_LIKE,
        GENERATED_HEADER_C_LIKE,
        '',
        '#include "community_modules.h"',
    ]

    modules = get_modules(cli.args.keyboard, cli.args.filename)
    if len(modules) > 0:

        for module in modules:
            for api in MODULE_API_LIST:
                lines.extend(_render_api_implementations(api, module))

        for api in MODULE_API_LIST:
            lines.extend(_render_core_implementation(api, modules))

    dump_lines(cli.args.output, lines, cli.args.quiet, remove_repeated_newlines=True)
