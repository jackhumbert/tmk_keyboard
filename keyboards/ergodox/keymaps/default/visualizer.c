/*
Copyright 2017 Fred Sundvik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Currently we are assuming that both the backlight and LCD are enabled
// But it's entirely possible to write a custom visualizer that use only
// one of them
#ifndef LCD_BACKLIGHT_ENABLE
#error This visualizer needs that LCD backlight is enabled
#endif

#ifndef LCD_ENABLE
#error This visualizer needs that LCD is enabled
#endif

#include "visualizer.h"
#include "system/serial_link.h"

// To generate an image array like this
// Ensure the image is 128 x 32 or smaller
// Convert the bitmap to a C array using a program like http://www.riuson.com/lcd-image-converter/
// Ensure the the conversion process produces a monochrome format array - 1 bit/pixel, left to right, top to bottom
// Update array in the source code with the C array produced by the conversion program

// The image below is generated from lcd_logo.png
static const uint8_t image_data_lcd_logo[512] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xf8, 0xfe, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x06, 0x29, 0x41, 0x24, 0x52, 0x24, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x09, 0x55, 0x42, 0xaa, 0xaa, 0xaa, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x09, 0x55, 0x82, 0x28, 0xaa, 0xae, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x09, 0x55, 0x43, 0x28, 0xaa, 0xaa, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x0a, 0x55, 0x42, 0x28, 0xaa, 0xaa, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0x38, 0x38, 0x05, 0x45, 0x42, 0x28, 0x89, 0x4a, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x18, 0x38, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1c, 0x38, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0e, 0x38, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0xff, 0x80, 0x04, 0x45, 0x14, 0xa4, 0x92, 0x83, 0x52, 0x22, 0x22, 0x36, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x00, 0x0a, 0xaa, 0xaa, 0xaa, 0xba, 0x84, 0x55, 0x55, 0x57, 0x45, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x00, 0x08, 0xaa, 0xaa, 0xaa, 0x92, 0xb2, 0x55, 0x55, 0x42, 0x65, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x00, 0x08, 0xaa, 0xaa, 0xaa, 0x92, 0x81, 0x56, 0x65, 0x42, 0x45, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x00, 0x0a, 0xaa, 0xaa, 0xaa, 0x92, 0x81, 0x54, 0x45, 0x42, 0x45, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x00, 0x04, 0x48, 0xa2, 0x4a, 0x89, 0x06, 0x24, 0x42, 0x41, 0x36, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint32_t logo_background_color = LCD_COLOR(0x00, 0x00, 0xFF);
static const uint32_t initial_color = LCD_COLOR(0, 0, 0);

typedef enum {
    LCD_STATE_INITIAL,
    LCD_STATE_LAYER_BITMAP,
    LCD_STATE_BITMAP_AND_LEDS,
} lcd_state_t;

static lcd_state_t lcd_state = LCD_STATE_INITIAL;

bool display_logo(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)state;
    (void)animation;
    (void)state;
    // Read the uGFX documentation for information how to use the displays
    // http://wiki.ugfx.org/index.php/Main_Page
    gdispClear(White);

    // You can use static variables for things that can't be found in the animation
    // or state structs, here we use the image

    //gdispGBlitArea is a tricky function to use since it supports blitting part of the image
    // if you have full screen image, then just use 128 and 32 for both source and target dimensions
    gdispGBlitArea(GDISP, 0, 0, 128, 32, 0, 0, 128, (pixel_t*)image_data_lcd_logo);

    // Always remember to flush the display
    gdispFlush();
    return false;
}

// Feel free to modify the animations below, or even add new ones if needed

// Don't worry, if the startup animation is long, you can use the keyboard like normal
// during that time
static keyframe_animation_t startup_animation = {
    .num_frames = 3,
    .loop = false,
    .frame_lengths = {0, gfxMillisecondsToTicks(10000), 0},
    .frame_functions = {
            display_logo,
            keyframe_animate_backlight_color,
            enable_visualization
    },
};

// The LCD animation alternates between the layer name display and a
// bitmap that displays all active layers
static keyframe_animation_t lcd_layer_bitmap_animation = {
    .num_frames = 2,
    .loop = true,
    .frame_lengths = {
        gfxMillisecondsToTicks(2000),
        gfxMillisecondsToTicks(2000)
    },
    .frame_functions = {
        keyframe_display_layer_text,
        keyframe_display_layer_bitmap
    },
};

static keyframe_animation_t lcd_layer_bitmap_leds_animation = {
    .num_frames = 3,
    .loop = true,
    .frame_lengths = {
        gfxMillisecondsToTicks(2000),
        gfxMillisecondsToTicks(2000),
        gfxMillisecondsToTicks(2000)
    },
    .frame_functions = {
        keyframe_display_layer_text,
        keyframe_display_led_states,
        keyframe_display_layer_bitmap,
    },
};

static keyframe_animation_t suspend_animation = {
    .num_frames = 3,
    .loop = false,
    .frame_lengths = {0, gfxMillisecondsToTicks(1000), 0},
    .frame_functions = {
            keyframe_display_layer_text,
            keyframe_animate_backlight_color,
            keyframe_disable_lcd_and_backlight,
    },
};

static keyframe_animation_t resume_animation = {
    .num_frames = 4,
    .loop = false,
    .frame_lengths = {0, 0, gfxMillisecondsToTicks(10000), 0},
    .frame_functions = {
            keyframe_enable_lcd_and_backlight,
            display_logo,
            keyframe_animate_backlight_color,
            enable_visualization,
    },
};

// The color animation animates the LCD color when you change layers
static keyframe_animation_t color_animation = {
    .num_frames = 2,
    .loop = false,
    // Note that there's a 200 ms no-operation frame,
    // this prevents the color from changing when activating the layer
    // momentarily
    .frame_lengths = {gfxMillisecondsToTicks(200), gfxMillisecondsToTicks(500)},
    .frame_functions = {keyframe_no_operation, keyframe_animate_backlight_color},
};

void initialize_user_visualizer(visualizer_state_t* state) {
    // The brightness will be dynamically adjustable in the future
    // But for now, change it here.
    lcd_backlight_brightness(130);
    state->current_lcd_color = initial_color;
    state->target_lcd_color = logo_background_color;
    lcd_state = LCD_STATE_INITIAL;
    start_keyframe_animation(&startup_animation);
}

void update_user_visualizer_state(visualizer_state_t* state, visualizer_keyboard_status_t* prev_status) {
    // Add more tests, change the colors and layer texts here
    // Usually you want to check the high bits (higher layers first)
    // because that's the order layers are processed for keypresses
    // You can for check for example:
    // state->status.layer
    // state->status.default_layer
    // state->status.leds (see led.h for available statuses)

    if (state->status.layer & 0x4) {
        state->target_lcd_color = LCD_COLOR(0, 0xB0, 0xFF);
        state->layer_text = "Media & Mouse";
    }
    else if (state->status.layer & 0x2) {
        state->target_lcd_color = LCD_COLOR(0x80, 0xB0, 0xFF);
        state->layer_text = "Symbol";
    }
    else {
        state->target_lcd_color = LCD_COLOR(0x40, 0xB0, 0xFF);
        state->layer_text = "Default";
    }

    if (lcd_state == LCD_STATE_INITIAL || state->status.layer != prev_status->layer) {
        start_keyframe_animation(&color_animation);
    }

    if (state->status.leds) {
        if (lcd_state != LCD_STATE_BITMAP_AND_LEDS ||
                state->status.leds != prev_status->leds ||
                state->status.layer != prev_status->layer ||
                state->status.default_layer != prev_status->default_layer) {

            // NOTE: that it doesn't matter if the animation isn't playing, stop will do nothing in that case
            stop_keyframe_animation(&lcd_layer_bitmap_animation);

            lcd_state = LCD_STATE_BITMAP_AND_LEDS;
            // For information:
            // The logic in this function makes sure that this doesn't happen, but if you call start on an
            // animation that is already playing it will be restarted.
            start_keyframe_animation(&lcd_layer_bitmap_leds_animation);
        }
    } else {
        if (lcd_state != LCD_STATE_LAYER_BITMAP ||
                state->status.layer != prev_status->layer ||
                state->status.default_layer != prev_status->default_layer) {

            stop_keyframe_animation(&lcd_layer_bitmap_leds_animation);

            lcd_state = LCD_STATE_LAYER_BITMAP;
            start_keyframe_animation(&lcd_layer_bitmap_animation);
        }
    }
    // You can also stop existing animations, and start your custom ones here
    // remember that you should normally have only one animation for the LCD
    // and one for the background. But you can also combine them if you want.
}

void user_visualizer_suspend(visualizer_state_t* state) {
    state->layer_text = "Suspending...";
    uint8_t hue = LCD_HUE(state->current_lcd_color);
    uint8_t sat = LCD_SAT(state->current_lcd_color);
    state->target_lcd_color = LCD_COLOR(hue, sat, 0);
    start_keyframe_animation(&suspend_animation);
}

void user_visualizer_resume(visualizer_state_t* state) {
    state->current_lcd_color = initial_color;
    state->target_lcd_color = logo_background_color;
    lcd_state = LCD_STATE_INITIAL;
    start_keyframe_animation(&resume_animation);
}
