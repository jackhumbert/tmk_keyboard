"""Compile all keyboards.

This will compile everything in parallel, for testing purposes.
"""
from pathlib import Path

from milc import cli

from qmk.constants import QMK_FIRMWARE
from qmk.commands import _find_make
import qmk.keyboard


def _determine_default_folder(keyboard_name):
    conf = qmk.keyboard.config_h(keyboard_name)
    print(f"""\
{keyboard_name}:
{conf}
""")
    return keyboard_name


@cli.argument('-j', '--parallel', type=int, default=1, help="Set the number of parallel make jobs to run.")
@cli.argument('-c', '--clean', arg_only=True, action='store_true', help="Remove object files before compiling.")
@cli.subcommand('Compile QMK Firmware for all keyboards.', hidden=False if cli.config.user.developer else True)
def buildall(cli):
    """Compile QMK Firmware against all keyboards.
    """

    make_cmd = _find_make()
    if cli.args.clean:
        cli.run([make_cmd, 'clean'], capture_output=False, text=False)

    builddir = Path(QMK_FIRMWARE) / '.build'
    makefile = builddir / 'parallel_kb_builds.mk'

    builddir.mkdir(parents=True, exist_ok=True)
    with open(makefile, "w") as f:
        for keyboard_name in qmk.keyboard.list_keyboards():
            keyboard_safe = keyboard_name.replace('/', '_')
            f.write(
                f"""\
all: {keyboard_safe}_binary
{keyboard_safe}_binary:
	@rm -f "{QMK_FIRMWARE}/.build/failed.log.{keyboard_safe}" || true
	+@$(MAKE) -C "{QMK_FIRMWARE}" -f "{QMK_FIRMWARE}/build_keyboard.mk" KEYBOARD="{keyboard_name}" KEYMAP="default" REQUIRE_PLATFORM_KEY= COLOR=true SILENT=false \\
		>>"{QMK_FIRMWARE}/.build/build.log.{keyboard_safe}" 2>&1 \\
		|| cp "{QMK_FIRMWARE}/.build/build.log.{keyboard_safe}" "{QMK_FIRMWARE}/.build/failed.log.{keyboard_safe}"
	@{{ grep '\[ERRORS\]' "{QMK_FIRMWARE}/.build/build.log.{keyboard_safe}" >/dev/null 2>&1 && printf "Build %-64s \e[1;31m[ERRORS]\e[0m\\n" "{keyboard_safe}:default" ; }} \\
		|| {{ grep '\[WARNINGS\]' "{QMK_FIRMWARE}/.build/build.log.{keyboard_safe}" >/dev/null 2>&1 && printf "Build %-64s \e[1;33m[WARNINGS]\e[0m\\n" "{keyboard_safe}:default" ; }} \\
		|| printf "Build %-64s \e[1;32m[OK]\e[0m\\n" "{keyboard_safe}:default"
	@rm -f "{QMK_FIRMWARE}/.build/build.log.{keyboard_safe}" || true

"""
            )

    cli.run([make_cmd, '-j', str(cli.args.parallel), '-f', makefile, 'all'], capture_output=False, text=False)
