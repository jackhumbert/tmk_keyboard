#pragma once

#define ENCODER_RESOLUTION 4    // dependent on rotary encoder

#define TAP_CODE_DELAY 10       // delay between key press and release on `tapcode(kc)`

#define TAPPING_TERM 200        // tap dance tap-window

#define ONESHOT_TAP_TOGGLE 5    // taps to toggle a one-shot layer/key persistence

#ifdef AUDIO_ENABLE
    #undef  TEMPO_DEFAULT       // set a custom tempo
    #define TEMPO_DEFAULT 255   // smaller is faster; max = 255

    #define T__NOTE(note) MUSICAL_NOTE(note, 2) // 32nd-note
    #define TD_NOTE(note) MUSICAL_NOTE(note, 3) // 48th-note
    #define X__NOTE(note) MUSICAL_NOTE(note, 1) // 64th-note

    // Mario songs

    #undef  MARIO_THEME
    #define MARIO_THEME         E__NOTE(_E5),   E__NOTE(_REST), Q__NOTE(_E5),   \
                                Q__NOTE(_REST), Q__NOTE(_E5),   Q__NOTE(_REST), \
                                Q__NOTE(_C5),   Q__NOTE(_E5),   Q__NOTE(_REST), \
                                H__NOTE(_G5),   S__NOTE(_REST), H__NOTE(_REST), HD_NOTE(_G4)

    #define MARIO_CAVE_1        E__NOTE(_C5),  E__NOTE(_REST), E__NOTE(_C5),  E__NOTE(_REST), \
                                E__NOTE(_A4),  E__NOTE(_REST), E__NOTE(_A4),  E__NOTE(_REST), \
                                E__NOTE(_AS4), E__NOTE(_REST), E__NOTE(_AS4), E__NOTE(_REST),
    #define MARIO_CAVE_2        E__NOTE(_F4),  E__NOTE(_REST), E__NOTE(_F4),  E__NOTE(_REST), \
                                E__NOTE(_D4),  E__NOTE(_REST), E__NOTE(_D4),  E__NOTE(_REST), \
                                E__NOTE(_DS4), E__NOTE(_REST), E__NOTE(_DS4), E__NOTE(_REST)

    #define MARIO_PIPE          X__NOTE(_E7), X__NOTE(_A6), X__NOTE(_D6), X__NOTE(_G5), \
                                X__NOTE(_E7), X__NOTE(_A6), X__NOTE(_D6), X__NOTE(_G5), T__NOTE(_AS3), T__NOTE(_AS2), \
                                T__NOTE(_REST), \
                                X__NOTE(_E7), X__NOTE(_A6), X__NOTE(_D6), X__NOTE(_G5), \
                                X__NOTE(_E7), X__NOTE(_A6), X__NOTE(_D6), X__NOTE(_G5), T__NOTE(_AS3), T__NOTE(_AS2), \
                                T__NOTE(_REST), \
                                X__NOTE(_E7), X__NOTE(_A6), X__NOTE(_D6), X__NOTE(_G5), \
                                X__NOTE(_E7), X__NOTE(_A6), X__NOTE(_D6), X__NOTE(_G5), T__NOTE(_AS3), T__NOTE(_AS2)

    #define MARIO_ONEUP         ED_NOTE(_E7), ED_NOTE(_G7), ED_NOTE(_E8), \
                                ED_NOTE(_C8), ED_NOTE(_D8), H__NOTE(_G8)

    #define MARIO_VINE          // todo

    #define MARIO_COIN          E__NOTE(_B6), H__NOTE(_E7), QD_NOTE(_E7)

    #define MARIO_KICK          S__NOTE(_AS5), E__NOTE(_REST), S__NOTE(_F6)

    #define MARIO_STOMP         // todo

    #define MARIO_GAMEOVER      // todo

    #define MARIO_POWERUP       S__NOTE(_C6),  T__NOTE(_G5),  T__NOTE(_C6),  T__NOTE(_E6),  \
                                T__NOTE(_G6),  T__NOTE(_C7),  T__NOTE(_G6),  S__NOTE(_GS5), \
                                T__NOTE(_C6),  T__NOTE(_DS6), T__NOTE(_GS6), T__NOTE(_DS6), \
                                T__NOTE(_GS6), T__NOTE(_C7),  T__NOTE(_DS7), T__NOTE(_GS7), \
                                T__NOTE(_DS7), S__NOTE(_AS5), T__NOTE(_D6),  T__NOTE(_F6),  \
                                T__NOTE(_AS6), T__NOTE(_F6),  T__NOTE(_AS6), T__NOTE(_D7),  \
                                T__NOTE(_F7), T__NOTE(_AS7), T__NOTE(_F7)

    #define MARIO_POWERUP_BLOCK // todo

    #define MARIO_FIREBALL      T__NOTE(_G4), T__NOTE(_G5), T__NOTE(_G6), T__NOTE(_G7)

    #define MARIO_BUMP          W__NOTE(_G5),  W__NOTE(_FS5), W__NOTE(_F5),  W__NOTE(_E5), \
                                W__NOTE(_DS5), W__NOTE(_D5),  W__NOTE(_CS5), W__NOTE(_C5), \
                                S__NOTE(_CS5), W__NOTE(_D5),  W__NOTE(_DS5), W__NOTE(_E5)

    #define MARIO_DAMAGE        // todo

    #define NOTE_A5SEMI         905.79f
    #define NOTE_AS5SEMI        959.65f
    #define NOTE_B5SEMI         1016.71f

                                // todo - fix
    #define MARIO_DEATH         TD_NOTE(_AS5), T__NOTE(_A5SEMI), TD_NOTE(_B5), T__NOTE(_AS5SEMI), \
                                TD_NOTE(_C6), T__NOTE(_B5SEMI), X__NOTE(_GS5), TD_NOTE(_G5)

                                // todo - fix
    #define MARIO_JUMP_SMALL    T__NOTE(_A6), \
                                TD_NOTE(_A5), X__NOTE(_AS5), X__NOTE(_B5),                \
                                X__NOTE(_C6), X__NOTE(_CS6), X__NOTE(_D6), X__NOTE(_DS6), \
                                X__NOTE(_E6),                X__NOTE(_F6), X__NOTE(_FS6), \
                                X__NOTE(_G6), X__NOTE(_GS6), X__NOTE(_A6), X__NOTE(_AS6), \
                                T__NOTE(_B6)

    #define MARIO_JUMP_BIG      // todo

    // real songs

    #define PINK_PANTHER        Q__NOTE(_CS5), QD_NOTE(_D5), Q__NOTE(_REST), Q__NOTE(_DS5), W__NOTE(_E5)

    #define STILL_DRE           QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_CS6), Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_AS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_GS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_GS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_GS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_GS6),  \
                                QD_NOTE(_C6),  Q__NOTE(_F6), QD_NOTE(_GS6),
    // sound effects

    #define COIN                E__NOTE(_A5), HD_NOTE(_E6)
    #define BUZZ                H__NOTE(_C3), H__NOTE(_C3)

    #define PICK_UP             H__NOTE(_C4), HD_NOTE(_G4)
    #define PUT_DOWN            H__NOTE(_G4), HD_NOTE(_C4)

    // override default songs
    #define STARTUP_SONG        SONG(PINK_PANTHER)
    #define GOODBYE_SONG        SONG(MARIO_DEATH)
#endif
