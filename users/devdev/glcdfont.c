// This is the 'classic' fixed-space bitmap font for Adafruit_GFX since 1.0.
// See gfxfont.h for newer custom bitmap font info.

#include "progmem.h"

#ifndef CUSTOM_FONT
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0,
    0xF0, 0xF8, 0xF8, 0x18, 0x00, 0xC0,
    0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xC0, 0xE0, 0xE0,
    0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
    0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0,
    0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x80,
    0x00, 0x00, 0x00, 0xE0, 0xE0, 0xC0,
    0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00,
    0x00, 0xE0, 0xE0, 0xC0, 0xC0, 0xE0,
    0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
    0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0xFC, 0xFE,
    0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x1F, 0x07, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x81, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x81,
    0xC3, 0xC3, 0xC3, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0x81, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x81, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0x9D, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
    0x1C, 0x9D, 0xDF, 0xDF, 0xDF, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x0F, 0x1F,
    0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F,
    0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F,
    0x3F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7C, 0x78, 0x78, 0x38, 0x1C,
    0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x03, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x07, 0x07, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x07, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
    0x07, 0x00, 0x00, 0x00, 0x01, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x03, 0x01, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#else 
    
// use https://joric.github.io/qle/ to generate these. 
// You can copy the image into the logo section, then copy the byte array out of the font one .
const unsigned char  font[] PROGMEM= {
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7C, 0xFC,
    0xFC, 0xF8, 0xF0, 0x00, 0x20, 0xF0,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x3C,
    0xA8, 0xE0, 0xE0, 0xE0, 0xF0, 0x78,
    0x7C, 0x7C, 0x7C, 0x3C, 0x1C, 0x00,
    0x00, 0x00, 0xF8, 0xFC, 0x8C, 0x04,
    0x04, 0x0C, 0x08, 0x10, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x60, 0xC0, 0x80,
    0x80, 0xE0, 0xF0, 0xF8, 0x7C, 0x1C,
    0x0C, 0x0C, 0x0C, 0x9C, 0xF8, 0x00,
    0x00, 0x00, 0xF8, 0xFC, 0x8C, 0x04,
    0x04, 0x0C, 0x08, 0x10, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x20, 0x70,
    0x21, 0x3F, 0x0F, 0x1F, 0x3D, 0x3D,
    0x3C, 0xBC, 0xBC, 0xFC, 0x7E, 0x7E,
    0xF3, 0xF1, 0xE0, 0xC0, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xC0, 0x20,
    0x00, 0x00, 0x10, 0x38, 0xE0, 0xFF,
    0xFF, 0xFF, 0xFF, 0xC0, 0x03, 0x02,
    0x02, 0x07, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x03, 0x07, 0x8F,
    0xCF, 0x7E, 0x7E, 0x3F, 0x3D, 0x3D,
    0x3C, 0xBC, 0xBC, 0xF8, 0xF0, 0xFC,
    0x84, 0x0E, 0x04, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x70, 0x20, 0x20, 0xE0, 0x81, 0xFF,
    0xFF, 0xFF, 0x7F, 0x03, 0x0E, 0x04,
    0x00, 0x00, 0x02, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x03, 0x07, 0x8F,
    0xCF, 0x7E, 0x7E, 0x3F, 0x3D, 0x3D,
    0x3C, 0xBC, 0xBC, 0xF8, 0xF0, 0xFC,
    0x84, 0x0E, 0x04, 0x00, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x08, 0x10, 0x30,
    0x20, 0x20, 0x31, 0x3F, 0x1F, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x1C, 0x18,
    0x18, 0x18, 0x1C, 0x1F, 0x0F, 0x07,
    0x03, 0x00, 0x00, 0x01, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x0F, 0x04, 0x00, 0x0F, 0x1F,
    0x3F, 0x3F, 0x3E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1C, 0x1E, 0x1F,
    0x1F, 0x1F, 0x0F, 0x07, 0x03, 0x03,
    0x03, 0x0A, 0x1e, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x0F, 0x04, 0x00, 0x0f, 0x1F,
    0x3F, 0x3F, 0x3f, 0x00, 0x00, 0x00,
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
#endif