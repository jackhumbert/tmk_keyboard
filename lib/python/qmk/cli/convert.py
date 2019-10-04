"""Convert raw KLE to JSON

"""
import json
import os
from pathlib import Path
from argparse import FileType
from decimal import Decimal
from collections import OrderedDict

from milc import cli
from kle2xy import KLE2xy

from qmk.converter import kle2qmk

class CustomJSONEncoder(json.JSONEncoder):
    def default(self, obj):
        try:
            if isinstance(obj, Decimal):
                if obj % 2 in (Decimal(0), Decimal(1)):
                    return int(obj)
                return float(obj)
        except TypeError:
            pass
        return JSONEncoder.default(self, obj)

@cli.argument('filename', nargs='*', help='The KLE raw txt to convert')
@cli.argument('-f', '--force', action='store_true', help='Flag to overwrite current info.json')
@cli.subcommand('Convert a KLE layout to a configurator JSON')
def convert(cli):
    """Convert a KLE layout to QMK's layout format.
    """
    if cli.args.filename:

        # If filename is a path
        if cli.args.filename[0][0] == "/" or cli.args.filename[0][0] == "./":
            file_path = Path(cli.args.filename[0])

        # Otherwise assume it is a file name
        else:
            file_path = Path(os.environ['ORIG_CWD'], cli.args.filename[0])
            
        # Check for valid file_path for more graceful failure
        if file_path.exists() == False:
            return cli.log.error('File {fg_cyan}%s{style_reset_all} was not found.', str(file_path))

        out_path = file_path.parent
        raw_code = file_path.open().read()

        # Check if info.json exists, allow overwrite with force
        if Path(out_path,"info.json").exists() and cli.args.force == False:
            return cli.log.error('File {fg_cyan}%s/info.json{style_reset_all} already exists, use -f or --force to overwrite.', str(out_path))
            
        try:
            # Convert KLE raw to x/y coordinates (using kle2xy package from skullydazed)
            kle = KLE2xy(raw_code)
        except Exception as e:
            cli.log.error('Could not parse KLE raw data: %s', raw_code)
            cli.log.exception(e)
            return cli.log.error('Could not parse KLE raw data.')  # FIXME: This should be better

        keyboard = OrderedDict(
            keyboard_name=kle.name,
            url='',
            maintainer='qmk',
            width=kle.columns,
            height=kle.rows,
            layouts={'LAYOUT': {
                'layout': 'LAYOUT_JSON_HERE'
            }},
        )

        # Initialize keyboard with json encoded from ordered dict
        keyboard = json.dumps(keyboard, indent=4, separators=(', ', ': '), sort_keys=False, cls=CustomJSONEncoder)
        # Initialize layout with kle2qmk from converter module
        layout = json.dumps(kle2qmk(kle), separators=(', ', ':'), cls=CustomJSONEncoder)
        # Replace layout in keyboard json
        keyboard = keyboard.replace('"LAYOUT_JSON_HERE"', layout)

        # Write our info.json
        file = open(str(out_path) + "/info.json","w")
        file.write(keyboard)
        file.close()
        cli.log.info('Wrote keymap to {fg_cyan}%s/info.json', str(out_path))

    else:
        cli.log.error('You must supply a KLE raw export.')
        return False

