// This is the 'classic' fixed-space bitmap font for Adafruit_GFX since 1.0.
// See gfxfont.h for newer custom bitmap font info.

#ifndef FONT5X7_H
#define FONT5X7_H

#ifdef __AVR__
 #include <avr/io.h>
 #include <avr/pgmspace.h>
#elif defined(ESP8266)
 #include <pgmspace.h>
#else
 #define PROGMEM
#endif

// Standard ASCII 5x7 font
const unsigned char font[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 0x00,
0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 0x00,
0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 0x00,
0x18, 0x3C, 0x7E, 0x3C, 0x18, 0x00,
0x1C, 0x57, 0x7D, 0x57, 0x1C, 0x00,
0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 0x00,
0x00, 0x18, 0x3C, 0x18, 0x00, 0x00,
0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00,
0x00, 0x18, 0x24, 0x18, 0x00, 0x00,
0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 0x00,
0x30, 0x48, 0x3A, 0x06, 0x0E, 0x00,
0x26, 0x29, 0x79, 0x29, 0x26, 0x00,
0x40, 0x7F, 0x05, 0x05, 0x07, 0x00,
0x40, 0x7F, 0x05, 0x25, 0x3F, 0x00,
0x5A, 0x3C, 0xE7, 0x3C, 0x5A, 0x00,
0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,
0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00,
0x00, 0x66, 0x89, 0x95, 0x6A, 0x00,
0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
0x08, 0x04, 0x7E, 0x04, 0x08, 0x00,
0x10, 0x20, 0x7E, 0x20, 0x10, 0x00,
0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,
0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
0x1E, 0x10, 0x10, 0x10, 0x10, 0x00,
0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x00,
0x30, 0x38, 0x3E, 0x38, 0x30, 0x00,
0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x5F, 0x00, 0x00, 0x00,
0x00, 0x07, 0x00, 0x07, 0x00, 0x00,
0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00,
0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00,
0x23, 0x13, 0x08, 0x64, 0x62, 0x00,
0x36, 0x49, 0x56, 0x20, 0x50, 0x00,
0x00, 0x08, 0x07, 0x03, 0x00, 0x00,
0x00, 0x1C, 0x22, 0x41, 0x00, 0x00,
0x00, 0x41, 0x22, 0x1C, 0x00, 0x00,
0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x00,
0x08, 0x08, 0x3E, 0x08, 0x08, 0x00,
0x00, 0x80, 0x70, 0x30, 0x00, 0x00,
0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
0x20, 0x10, 0x08, 0x04, 0x02, 0x00,
0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00,
0x00, 0x42, 0x7F, 0x40, 0x00, 0x00,
0x72, 0x49, 0x49, 0x49, 0x46, 0x00,
0x21, 0x41, 0x49, 0x4D, 0x33, 0x00,
0x18, 0x14, 0x12, 0x7F, 0x10, 0x00,
0x27, 0x45, 0x45, 0x45, 0x39, 0x00,
0x3C, 0x4A, 0x49, 0x49, 0x31, 0x00,
0x41, 0x21, 0x11, 0x09, 0x07, 0x00,
0x36, 0x49, 0x49, 0x49, 0x36, 0x00,
0x46, 0x49, 0x49, 0x29, 0x1E, 0x00,
0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
0x00, 0x40, 0x34, 0x00, 0x00, 0x00,
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,
0x14, 0x14, 0x14, 0x14, 0x14, 0x00,
0x00, 0x41, 0x22, 0x14, 0x08, 0x00,
0x02, 0x01, 0x59, 0x09, 0x06, 0x00,
0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x00,
0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00,
0x7F, 0x49, 0x49, 0x49, 0x36, 0x00,
0x3E, 0x41, 0x41, 0x41, 0x22, 0x00,
0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00,
0x7F, 0x49, 0x49, 0x49, 0x41, 0x00,
0x7F, 0x09, 0x09, 0x09, 0x01, 0x00,
0x3E, 0x41, 0x41, 0x51, 0x73, 0x00,
0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00,
0x00, 0x41, 0x7F, 0x41, 0x00, 0x00,
0x20, 0x40, 0x41, 0x3F, 0x01, 0x00,
0x7F, 0x08, 0x14, 0x22, 0x41, 0x00,
0x7F, 0x40, 0x40, 0x40, 0x40, 0x00,
0x7F, 0x02, 0x1C, 0x02, 0x7F, 0x00,
0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00,
0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00,
0x7F, 0x09, 0x09, 0x09, 0x06, 0x00,
0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00,
0x7F, 0x09, 0x19, 0x29, 0x46, 0x00,
0x26, 0x49, 0x49, 0x49, 0x32, 0x00,
0x03, 0x01, 0x7F, 0x01, 0x03, 0x00,
0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00,
0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00,
0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00,
0x63, 0x14, 0x08, 0x14, 0x63, 0x00,
0x03, 0x04, 0x78, 0x04, 0x03, 0x00,
0x61, 0x59, 0x49, 0x4D, 0x43, 0x00,
0x00, 0x7F, 0x41, 0x41, 0x41, 0x00,
0x02, 0x04, 0x08, 0x10, 0x20, 0x00,
0x00, 0x41, 0x41, 0x41, 0x7F, 0x00,
0x04, 0x02, 0x01, 0x02, 0x04, 0x00,
0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
0x00, 0x03, 0x07, 0x08, 0x00, 0x00,
0x20, 0x54, 0x54, 0x78, 0x40, 0x00,
0x7F, 0x28, 0x44, 0x44, 0x38, 0x00,
0x38, 0x44, 0x44, 0x44, 0x28, 0x00,
0x38, 0x44, 0x44, 0x28, 0x7F, 0x00,
0x38, 0x54, 0x54, 0x54, 0x18, 0x00,
0x00, 0x08, 0x7E, 0x09, 0x02, 0x00,
0x18, 0x24, 0x24, 0x1C, 0x78, 0x00,
0x7F, 0x08, 0x04, 0x04, 0x78, 0x00,
0x00, 0x44, 0x7D, 0x40, 0x00, 0x00,
0x20, 0x40, 0x40, 0x3D, 0x00, 0x00,
0x7F, 0x10, 0x28, 0x44, 0x00, 0x00,
0x00, 0x41, 0x7F, 0x40, 0x00, 0x00,
0x7C, 0x04, 0x78, 0x04, 0x78, 0x00,
0x7C, 0x08, 0x04, 0x04, 0x78, 0x00,
0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
0x7C, 0x18, 0x24, 0x24, 0x18, 0x00,
0x18, 0x24, 0x24, 0x18, 0x7C, 0x00,
0x7C, 0x08, 0x04, 0x04, 0x08, 0x00,
0x48, 0x54, 0x54, 0x54, 0x24, 0x00,
0x04, 0x04, 0x3F, 0x44, 0x24, 0x00,
0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00,
0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,
0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00,
0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
0x4C, 0x90, 0x90, 0x90, 0x7C, 0x00,
0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,
0x00, 0x08, 0x36, 0x41, 0x00, 0x00,
0x00, 0x00, 0x77, 0x00, 0x00, 0x00,
0x00, 0x41, 0x36, 0x08, 0x00, 0x00,
0x02, 0x01, 0x02, 0x04, 0x02, 0x00,
0x3C, 0x26, 0x23, 0x26, 0x3C, 0x00,
0x80, 0x00, 0x00, 0xFF, 0x00, 0xFC,
0xFC, 0x00, 0xF0, 0xC0, 0xE0, 0x30,
0xB0, 0xD8, 0xD8, 0xEC, 0xEC, 0xEC,
0xCC, 0xCC, 0xF6, 0x76, 0x33, 0x33,
0x33, 0x33, 0xF6, 0xE6, 0xCC, 0xCC,
0xEC, 0xEC, 0xEC, 0xD8, 0xD8, 0xB2,
0x36, 0xE6, 0xEE, 0x66, 0x66, 0x62,
0x30, 0x98, 0xCC, 0xE6, 0xF6, 0x76,
0xB2, 0xB3, 0x76, 0xF6, 0xEC, 0xEC,
0xEC, 0x64, 0x64, 0xEC, 0xEC, 0xCC,
0x98, 0x30, 0xF0, 0xC1, 0x01, 0x01,
0x79, 0x01, 0x01, 0x79, 0x01, 0x01,
0x79, 0x01, 0x01, 0x79, 0x01, 0x01,
0x79, 0x01, 0x01, 0x79, 0x01, 0x01,
0x79, 0x01, 0x01, 0x01, 0x01, 0x01,
0xF9, 0xC9, 0x85, 0x49, 0x79, 0x01,
0x81, 0x41, 0x21, 0x21, 0x21, 0x21,
0x21, 0x21, 0x21, 0x21, 0x21, 0x21,
0xA1, 0x21, 0x21, 0x79, 0x49, 0x85,
0x49, 0x79, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0xFF, 0xFE, 0x00,
0xE0, 0xF0, 0xF0, 0xF0, 0xE0, 0xEC,
0xEE, 0xF7, 0xF3, 0x70, 0x20, 0x00,
0x7C, 0x7C, 0x7C, 0x7E, 0x00, 0x7E,
0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x00,
0x00, 0x80, 0xC0, 0xE0, 0x7E, 0x5B,
0x4F, 0x5B, 0xFE, 0xC0, 0x00, 0x00,
0xC0, 0x00, 0xDC, 0xD7, 0xDE, 0xDE,
0xDE, 0xD7, 0xDC, 0x00, 0xC0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0x00, 0x80, 0xFF, 0x78, 0x9F,
0xE7, 0xF7, 0x7B, 0x3B, 0x38, 0x3F,
0x3F, 0x9F, 0x81, 0xE0, 0xFC, 0xF8,
0xF9, 0x79, 0x79, 0x38, 0x3C, 0x3F,
0x3F, 0x3C, 0x38, 0x79, 0x79, 0xF9,
0xFC, 0xFC, 0xE0, 0x81, 0x9F, 0x3F,
0x3F, 0x38, 0x3C, 0x7E, 0x07, 0xFB,
0xFB, 0xFB, 0xFB, 0xF9, 0xFC, 0xDF,
0x8F, 0x0F, 0x0F, 0xFE, 0xFE, 0xFE,
0xFE, 0xFF, 0xFF, 0x7E, 0xF0, 0xEF,
0xDF, 0xDC, 0xDD, 0x39, 0xFB, 0xF7,
0x8F, 0x3D, 0xF9, 0xD1, 0x91, 0x91,
0x91, 0x91, 0x91, 0x91, 0x91, 0x91,
0x91, 0x91, 0x91, 0x91, 0x91, 0x91,
0x91, 0x91, 0x91, 0x91, 0x91, 0x91,
0x91, 0x98, 0x88, 0x84, 0x82, 0x81,
0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C,
0x04, 0x04, 0x04, 0x06, 0x0F, 0x09,
0x10, 0x09, 0x0F, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x18, 0x3C,
0x7F, 0x00, 0x00, 0x03, 0x03, 0x00,
0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x3F, 0x1E, 0x0C, 0x00,
0x1F, 0x1F, 0x1F, 0x3F, 0x00, 0x3F,
0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x00,
0x30, 0x7B, 0x7F, 0x78, 0x30, 0x20,
0x20, 0x30, 0x78, 0x7F, 0x3B, 0x00,
0x03, 0x00, 0x0F, 0x7F, 0x0F, 0x0F,
0x0F, 0x7F, 0x0F, 0x00, 0x03, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xF0, 0x3F, 0x8F, 0xF0, 0xF3,
0x3F, 0x3F, 0x9C, 0x80, 0xC3, 0xFF,
0xFF, 0xFF, 0x1F, 0x07, 0xE1, 0xF8,
0xFC, 0xFE, 0x1E, 0x0F, 0xCF, 0xCF,
0xCF, 0xCF, 0x1F, 0x3E, 0xFE, 0xFC,
0xF8, 0xE1, 0x07, 0x1F, 0xFF, 0xFF,
0xFF, 0xC1, 0x80, 0xBC, 0x3C, 0xFF,
0xFF, 0xFF, 0x8F, 0x0F, 0x8F, 0xFF,
0xFF, 0xF7, 0xE3, 0xE3, 0x63, 0xFF,
0xFF, 0xF9, 0xF8, 0xF8, 0xF1, 0xFF,
0xFF, 0xFF, 0xE1, 0x1E, 0xFF, 0xFF,
0xE0, 0x0E, 0xFF, 0xF8, 0x98, 0x98,
0x98, 0x98, 0x98, 0x98, 0x98, 0x98,
0x98, 0x98, 0x98, 0x98, 0x98, 0x98,
0x98, 0x98, 0x98, 0x98, 0x98, 0x98,
0x98, 0x98, 0x98, 0x98, 0x98, 0x98,
0x18, 0x18, 0x3C, 0x24, 0x42, 0x24,
0x3C, 0x00, 0x7E, 0x42, 0x42, 0x42,
0x42, 0x42, 0x42, 0x42, 0x42, 0x7E,
0x00, 0x3C, 0x24, 0x42, 0x24, 0x3C,
0x18, 0x18, 0x18, 0x18, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

};
#endif // FONT5X7_H
