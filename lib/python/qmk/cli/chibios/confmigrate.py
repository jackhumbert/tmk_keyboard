"""This script automates the copying of the default keymap into your own keymap.
"""
import re
import sys
import os

from qmk.constants import QMK_FIRMWARE
from qmk.path import normpath
from milc import cli


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


file_header = """\
/* Copyright 2020 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This file was auto-generated by:
 *    `qmk chibios-confmigrate -i {0} -r {1}`
 */

#pragma once
"""


def collect_defines(filepath):
    with open(filepath, 'r') as f:
        content = f.read()
        define_search = re.compile(r'(?m)^#\s*define\s+(?:.*\\\r?\n)*.*$', re.MULTILINE)
        value_search = re.compile(r'^#\s*define\s+(?P<name>[a-zA-Z0-9_]+(\([^\)]*\))?)\s*(?P<value>.*)', re.DOTALL)
        define_matches = define_search.findall(content)

        defines = {"keys": [], "dict": {}}
        for define_match in define_matches:
            value_match = value_search.search(define_match)
            defines["keys"].append(value_match.group("name"))
            defines["dict"][value_match.group("name")] = value_match.group("value")
        return defines


def check_diffs(input_defs, reference_defs):
    not_present_in_input = []
    not_present_in_reference = []
    to_override = []

    for key in reference_defs["keys"]:
        if key not in input_defs["dict"]:
            not_present_in_input.append(key)
            continue

    for key in input_defs["keys"]:
        if key not in input_defs["dict"]:
            not_present_in_input.append(key)
            continue

    for key in input_defs["keys"]:
        if key in reference_defs["keys"] and input_defs["dict"][key] != reference_defs["dict"][key]:
            to_override.append((key, input_defs["dict"][key]))

    return (to_override, not_present_in_input, not_present_in_reference)


def migrate_chconf_h(to_override, outfile):
    print(file_header.format(cli.args.input.relative_to(QMK_FIRMWARE), cli.args.reference.relative_to(QMK_FIRMWARE)), file=outfile)

    for override in to_override:
        print("#define %s %s" % (override[0], override[1]), file=outfile)
        print("", file=outfile)

    print("#include_next <chconf.h>\n", file=outfile)


def migrate_halconf_h(to_override, outfile):
    print(file_header.format(cli.args.input.relative_to(QMK_FIRMWARE), cli.args.reference.relative_to(QMK_FIRMWARE)), file=outfile)

    for override in to_override:
        print("#define %s %s" % (override[0], override[1]), file=outfile)
        print("", file=outfile)

    print("#include_next <halconf.h>\n", file=outfile)


def migrate_mcuconf_h(to_override, outfile):
    print(file_header.format(cli.args.input.relative_to(QMK_FIRMWARE), cli.args.reference.relative_to(QMK_FIRMWARE)), file=outfile)

    print("#include_next <mcuconf.h>\n", file=outfile)

    for override in to_override:
        print("#undef %s" % (override[0]), file=outfile)
        print("#define %s %s" % (override[0], override[1]), file=outfile)
        print("", file=outfile)


@cli.argument('-i', '--input', type=normpath, arg_only=True, help='Specify input config file.')
@cli.argument('-r', '--reference', type=normpath, arg_only=True, help='Specify the reference file to compare against')
@cli.argument('-o', '--overwrite', arg_only=True, action='store_true', help='Overwrites the input file during migration.')
@cli.argument('-d', '--delete', arg_only=True, action='store_true', help='If the file has no overrides, migration will delete the input file.')
@cli.subcommand('Generates a migrated ChibiOS configuration file, as a result of comparing the input against a reference')
def chibios_confmigrate(cli):
    """Generates a usable ChibiOS replacement configuration file, based on a fully-defined conf and a reference config.
    """

    input_defs = collect_defines(cli.args.input)
    reference_defs = collect_defines(cli.args.reference)

    (to_override, not_present_in_input, not_present_in_reference) = check_diffs(input_defs, reference_defs)

    if len(not_present_in_input) > 0:
        eprint("Keys not in input, but present inside reference (potential manual migration required):")
        for key in not_present_in_input:
            eprint("   %s" % (key))

    if len(not_present_in_reference) > 0:
        eprint("Keys not in reference, but present inside input (potential manual migration required):")
        for key in not_present_in_reference:
            eprint("   %s" % (key))

    if len(to_override) == 0:
        eprint('No overrides found! If there were no missing keys above, it should be safe to delete the input file.')
        if cli.args.delete:
            os.remove(cli.args.input)
    else:
        eprint('Overrides found:')
        for override in to_override:
            eprint("%40s: %s -> %s" % (override[0], reference_defs["dict"][override[0]].encode('unicode_escape').decode("utf-8"), override[1].encode('unicode_escape').decode("utf-8")))

        eprint('--------------------------------------')

        if "CHCONF_H" in input_defs["dict"] or "_CHCONF_H_" in input_defs["dict"]:
            migrate_chconf_h(to_override, outfile=sys.stdout)
            if cli.args.overwrite:
                with open(cli.args.input, "w") as out_file:
                    migrate_chconf_h(to_override, outfile=out_file)

        elif "HALCONF_H" in input_defs["dict"] or "_HALCONF_H_" in input_defs["dict"]:
            migrate_halconf_h(to_override, outfile=sys.stdout)
            if cli.args.overwrite:
                with open(cli.args.input, "w") as out_file:
                    migrate_halconf_h(to_override, outfile=out_file)

        elif "MCUCONF_H" in input_defs["dict"] or "_MCUCONF_H_" in input_defs["dict"]:
            migrate_mcuconf_h(to_override, outfile=sys.stdout)
            if cli.args.overwrite:
                with open(cli.args.input, "w") as out_file:
                    migrate_mcuconf_h(to_override, outfile=out_file)
