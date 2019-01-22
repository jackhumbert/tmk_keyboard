/* Copyright 2018 Jason Williams (Wilba)
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

#include "quantum.h"
#include "via_support.h"


#ifdef RAW_ENABLE
void raw_hid_receive( uint8_t *data, uint8_t length ) {
	uint8_t *command_id = &(data[0]);
	uint8_t *command_data = &(data[1]);
	switch ( *command_id ) {
		case id_get_protocol_version:
			command_data[0] = PROTOCOL_VERSION >> 8;
			command_data[1] = PROTOCOL_VERSION & 0xFF;
			break;
		case id_get_keyboard_value:
			if ( command_data[0] == id_uptime ) {
				uint32_t value = timer_read32();
				command_data[1] = (value >> 24 ) & 0xFF;
				command_data[2] = (value >> 16 ) & 0xFF;
				command_data[3] = (value >> 8 ) & 0xFF;
				command_data[4] = value & 0xFF;
			} else {
				*command_id = id_unhandled;
			}
			break;
#ifdef DYNAMIC_KEYMAP_ENABLE
		case id_dynamic_keymap_get_keycode:
      {
        uint16_t keycode = dynamic_keymap_get_keycode( command_data[0], command_data[1], command_data[2] );
        command_data[3] = keycode >> 8;
        command_data[4] = keycode & 0xFF;
        break;
      }
		case id_dynamic_keymap_set_keycode:
			dynamic_keymap_set_keycode( command_data[0], command_data[1], command_data[2], ( command_data[3] << 8 ) | command_data[4] );
			break;
		case id_dynamic_keymap_reset:
			dynamic_keymap_reset();
			break;
		case id_dynamic_keymap_macro_get_count:
			command_data[0] = dynamic_keymap_macro_get_count();
			break;
		case id_dynamic_keymap_macro_get_buffer_size:
			{
        uint16_t size = dynamic_keymap_macro_get_buffer_size();
        command_data[0] = size >> 8;
        command_data[1] = size & 0xFF;
        break;
      }
		case id_dynamic_keymap_macro_get_buffer:
      {
        uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
        uint16_t size = command_data[2]; // size <= 28
        dynamic_keymap_macro_get_buffer( offset, size, &command_data[3] );
        break;
      }
		case id_dynamic_keymap_macro_set_buffer:
      {
        uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
        uint16_t size = command_data[2]; // size <= 28
        dynamic_keymap_macro_set_buffer( offset, size, &command_data[3] );
        break;
      }
		case id_dynamic_keymap_macro_reset:
			dynamic_keymap_macro_reset();
			break;
		case id_dynamic_keymap_get_layer_count:
			command_data[0] = dynamic_keymap_get_layer_count();
			break;
		case id_dynamic_keymap_get_buffer:
      {
        uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
        uint16_t size = command_data[2]; // size <= 28
        dynamic_keymap_get_buffer( offset, size, &command_data[3] );
        break;
      }
		case id_dynamic_keymap_set_buffer:
      {
        uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
        uint16_t size = command_data[2]; // size <= 28
        dynamic_keymap_set_buffer( offset, size, &command_data[3] );
        break;
      }
#endif // DYNAMIC_KEYMAP_ENABLE
		case id_eeprom_reset:
			eeprom_reset();
			break;
		case id_bootloader_jump:
			// Need to send data back before the jump
			// Informs host that the command is handled
			raw_hid_send( data, length );
			// Give host time to read it
			wait_ms(100);
			bootloader_jump();
			break;
		default:
			// Unhandled message.
			*command_id = id_unhandled;
			break;
	}

	// Return same buffer with values changed
	raw_hid_send( data, length );

}
#endif // RAW_ENABLE

void via_init(void) {
	// If the EEPROM has the magic, the data is good.
	// OK to load from EEPROM.
	if (eeprom_is_valid()) {
		//backlight_config_load();
	} else {
		// If the EEPROM has not been saved before, or is out of date,
		// save the default values to the EEPROM. Default values
		// come from construction of the zeal_backlight_config instance.
		//backlight_config_save();
#ifdef DYNAMIC_KEYMAP_ENABLE
		// This resets the keymaps in EEPROM to what is in flash.
		dynamic_keymap_reset();
		// This resets the macros in EEPROM to nothing.
		dynamic_keymap_macro_reset();
#endif
		// Save the magic number last, in case saving was interrupted
		eeprom_set_valid(true);
	}
}

bool process_via(uint16_t keycode, keyrecord_t *record) {

#ifdef DYNAMIC_KEYMAP_ENABLE
	// Handle macros
	if (record->event.pressed) {
		if ( keycode >= VIA_MACRO00 && keycode <= VIA_MACRO15 ) {
			uint8_t id = keycode - VIA_MACRO00;
			dynamic_keymap_macro_send(id);
			return false;
		}
	}
#endif //DYNAMIC_KEYMAP_ENABLE

	return true;
}
