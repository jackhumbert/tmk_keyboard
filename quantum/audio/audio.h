/* Copyright 2016 Jack Humbert
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

#pragma once

#include <stdint.h>
#include <stdbool.h>
#if defined(__AVR__)
#    include <avr/io.h>
#endif
#include "musical_notes.h"
#include "song_list.h"
#include "voices.h"
#include "quantum.h"
#include <math.h>
#if defined(AUDIO_DRIVER_DAC)
#    include "audio_chibios_dac.h"
#endif

typedef union {
    uint8_t raw;
    struct {
        bool    enable : 1;
        bool    clicky_enable : 1;
        uint8_t level : 6;
    };
} audio_config_t;

// implementation in the audio_avr/arm_* drivers
void audio_initialize_hardware(void);
void audio_start_hardware(void);
void audio_stop_hardware(void);

void audio_init(void);
void audio_startup(void);
)
void audio_toggle(void);
void audio_on(void);
void audio_off(void);
bool is_audio_on(void);

void play_note(float freq, int vol);
void stop_note(float freq);
void play_notes(float (*np)[][2], uint16_t n_count, bool n_repeat);
void stop_all_notes(void);

bool is_playing_note(void);
bool is_playing_notes(void);

uint8_t audio_get_number_of_active_voices(void);
float audio_get_frequency(uint8_t voice_index);

float audio_get_single_voice_frequency(uint8_t voice);

void  pwm_audio_timer_task(float *freq, float *freq_alt);

void audio_advance_note(uint32_t step, float end);


// Vibrato rate functions

// #define VIBRATO_ENABLE

// Enable vibrato strength/amplitude - slows down ISR too much (TODO: from/for/on avr only?)
// #define VIBRATO_STRENGTH_ENABLE

#ifdef VIBRATO_ENABLE

void set_vibrato_rate(float rate);
void increase_vibrato_rate(float change);
void decrease_vibrato_rate(float change);

#    ifdef VIBRATO_STRENGTH_ENABLE

void set_vibrato_strength(float strength);
void increase_vibrato_strength(float change);
void decrease_vibrato_strength(float change);

#    endif

#endif

// Polyphony functions

void set_polyphony_rate(float rate);
void enable_polyphony(void);
void disable_polyphony(void);
void increase_polyphony_rate(float change);
void decrease_polyphony_rate(float change);

// Timbre function

void set_timbre(float timbre);

// Tempo functions

void set_tempo(uint8_t tempo);
void increase_tempo(uint8_t tempo_change);
void decrease_tempo(uint8_t tempo_change);

#define SCALE \
    (int8_t[]) { 0 + (12 * 0), 2 + (12 * 0), 4 + (12 * 0), 5 + (12 * 0), 7 + (12 * 0), 9 + (12 * 0), 11 + (12 * 0), 0 + (12 * 1), 2 + (12 * 1), 4 + (12 * 1), 5 + (12 * 1), 7 + (12 * 1), 9 + (12 * 1), 11 + (12 * 1), 0 + (12 * 2), 2 + (12 * 2), 4 + (12 * 2), 5 + (12 * 2), 7 + (12 * 2), 9 + (12 * 2), 11 + (12 * 2), 0 + (12 * 3), 2 + (12 * 3), 4 + (12 * 3), 5 + (12 * 3), 7 + (12 * 3), 9 + (12 * 3), 11 + (12 * 3), 0 + (12 * 4), 2 + (12 * 4), 4 + (12 * 4), 5 + (12 * 4), 7 + (12 * 4), 9 + (12 * 4), 11 + (12 * 4), }

// These macros are used to allow play_notes to play an array of indeterminate
// length. This works around the limitation of C's sizeof operation on pointers.
// The global float array for the song must be used here.
#define NOTE_ARRAY_SIZE(x) ((int16_t)(sizeof(x) / (sizeof(x[0]))))
#define PLAY_SONG(note_array) play_notes(&note_array, NOTE_ARRAY_SIZE((note_array)), false)
#define PLAY_LOOP(note_array) play_notes(&note_array, NOTE_ARRAY_SIZE((note_array)), true)
