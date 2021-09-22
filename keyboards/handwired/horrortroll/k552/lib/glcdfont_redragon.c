// This is the 'classic' fixed-space bitmap font for Adafruit_GFX since 1.0.
// See gfxfont.h for newer custom bitmap font info.

// Modified to show the Redragon logo instead of the qmk logo
#include "progmem.h"

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
    0x2A, 0x1C, 0x77, 0x1C, 0x2A, 0x00,
    0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
    0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
    0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,
    0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
    0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00,
    0x00, 0x66, 0x89, 0x95, 0x6A, 0x00,
    0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
    0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
    0x08, 0x04, 0x3E, 0x04, 0x08, 0x00,
    0x08, 0x10, 0x3E, 0x10, 0x08, 0x00,
    0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,
    0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
    0x1E, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x00,
    0x30, 0x38, 0x3E, 0x38, 0x30, 0x00,
    0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x06, 0x00, 0x00,
    0x24, 0x7E, 0x24, 0x7E, 0x24, 0x00,
    0x04, 0x2A, 0x7F, 0x2A, 0x10, 0x00,
    0x4C, 0x2C, 0x10, 0x68, 0x64, 0x00,
    0x54, 0x2A, 0x54, 0x2A, 0x00, 0x00,
    0x00, 0x04, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x3C, 0x42, 0x00, 0x00, 0x00,
    0x00, 0x42, 0x3C, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x0E, 0x04, 0x00, 0x00,
    0x00, 0x10, 0x38, 0x10, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x60, 0x18, 0x06, 0x00, 0x00,
    0x3C, 0x42, 0x5A, 0x42, 0x3C, 0x00,
    0x00, 0x04, 0x7E, 0x00, 0x00, 0x00,
    0x64, 0x52, 0x4A, 0x64, 0x00, 0x00,
    0x22, 0x4A, 0x4A, 0x34, 0x00, 0x00,
    0x0E, 0x08, 0x08, 0x7E, 0x00, 0x00,
    0x6E, 0x4A, 0x4A, 0x7A, 0x00, 0x00,
    0x3C, 0x52, 0x52, 0x24, 0x00, 0x00,
    0x06, 0x72, 0x0A, 0x06, 0x00, 0x00,
    0x34, 0x4A, 0x4A, 0x34, 0x00, 0x00,
    0x24, 0x4A, 0x4A, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x48, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x48, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x28, 0x44, 0x00, 0x00,
    0x50, 0x50, 0x50, 0x50, 0x00, 0x00,
    0x00, 0x44, 0x28, 0x10, 0x00, 0x00,
    0x04, 0x72, 0x12, 0x0C, 0x00, 0x00,
    0x3E, 0x41, 0x5D, 0x55, 0x1E, 0x00,
    0x7C, 0x12, 0x12, 0x7C, 0x00, 0x00,
    0x7E, 0x52, 0x52, 0x2C, 0x00, 0x00,
    0x3C, 0x42, 0x42, 0x24, 0x00, 0x00,
    0x7E, 0x42, 0x42, 0x3C, 0x00, 0x00,
    0x7E, 0x4A, 0x4A, 0x42, 0x00, 0x00,
    0x7E, 0x0A, 0x0A, 0x02, 0x00, 0x00,
    0x3C, 0x42, 0x52, 0x74, 0x00, 0x00,
    0x7E, 0x08, 0x08, 0x7E, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x42, 0x3E, 0x00, 0x00,
    0x7E, 0x10, 0x28, 0x46, 0x00, 0x00,
    0x7E, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x7E, 0x04, 0x08, 0x04, 0x7E, 0x00,
    0x7E, 0x04, 0x08, 0x7E, 0x00, 0x00,
    0x7E, 0x42, 0x42, 0x7E, 0x00, 0x00,
    0x7E, 0x12, 0x12, 0x0C, 0x00, 0x00,
    0x7E, 0x52, 0x62, 0x7E, 0x00, 0x00,
    0x7E, 0x12, 0x12, 0x6C, 0x00, 0x00,
    0x24, 0x4A, 0x4A, 0x32, 0x00, 0x00,
    0x02, 0x02, 0x7E, 0x02, 0x02, 0x00,
    0x7E, 0x40, 0x40, 0x7E, 0x00, 0x00,
    0x3E, 0x40, 0x40, 0x3E, 0x00, 0x00,
    0x7E, 0x20, 0x10, 0x20, 0x7E, 0x00,
    0x76, 0x08, 0x08, 0x76, 0x00, 0x00,
    0x6E, 0x48, 0x48, 0x7E, 0x00, 0x00,
    0x66, 0x52, 0x4A, 0x66, 0x00, 0x00,
    0x00, 0x7E, 0x42, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x18, 0x60, 0x00, 0x00,
    0x00, 0x42, 0x7E, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x01, 0x02, 0x00, 0x00,
    0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x02, 0x04, 0x00, 0x00, 0x00,
    0x74, 0x54, 0x54, 0x78, 0x00, 0x00,
    0x7E, 0x48, 0x48, 0x30, 0x00, 0x00,
    0x38, 0x44, 0x44, 0x28, 0x00, 0x00,
    0x30, 0x48, 0x48, 0x7E, 0x00, 0x00,
    0x38, 0x54, 0x54, 0x58, 0x00, 0x00,
    0x00, 0x08, 0x7C, 0x0A, 0x00, 0x00,
    0x18, 0xA4, 0xA4, 0x78, 0x00, 0x00,
    0x7E, 0x08, 0x08, 0x70, 0x00, 0x00,
    0x00, 0x00, 0x7A, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x7A, 0x00, 0x00, 0x00,
    0x7E, 0x10, 0x10, 0x68, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x00, 0x00, 0x00,
    0x7C, 0x08, 0x10, 0x08, 0x7C, 0x00,
    0x7C, 0x08, 0x10, 0x7C, 0x00, 0x00,
    0x38, 0x44, 0x44, 0x38, 0x00, 0x00,
    0xF8, 0x24, 0x24, 0x18, 0x00, 0x00,
    0x18, 0x24, 0x24, 0xF8, 0x00, 0x00,
    0x00, 0x78, 0x04, 0x04, 0x00, 0x00,
    0x48, 0x54, 0x54, 0x24, 0x00, 0x00,
    0x00, 0x04, 0x3E, 0x44, 0x00, 0x00,
    0x7C, 0x40, 0x40, 0x7C, 0x00, 0x00,
    0x3C, 0x40, 0x40, 0x3C, 0x00, 0x00,
    0x7C, 0x20, 0x10, 0x20, 0x7C, 0x00,
    0x6C, 0x10, 0x10, 0x6C, 0x00, 0x00,
    0x1C, 0xA0, 0xA0, 0x7C, 0x00, 0x00,
    0x44, 0x64, 0x54, 0x4C, 0x00, 0x00,
    0x00, 0x3C, 0x42, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7E, 0x00, 0x00, 0x00,
    0x00, 0x42, 0x3C, 0x00, 0x00, 0x00,
    0x10, 0x08, 0x10, 0x08, 0x00, 0x00,
    0x3C, 0x26, 0x23, 0x26, 0x3C, 0x00,
    0x10, 0x38, 0x10, 0x10, 0x1C, 0x00,
    0x0C, 0x7A, 0x41, 0x7A, 0x0C, 0x00,
    0x18, 0x2F, 0x41, 0x2F, 0x18, 0x00,
    0x22, 0x72, 0x22, 0x27, 0x22, 0x00,
    0x08, 0x1C, 0x08, 0x08, 0x08, 0x00,
    0x08, 0x08, 0x38, 0x20, 0x28, 0x28,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x2A, 0x2A, 0x2A, 0x00, 0x00,
    0x4E, 0x46, 0x4A, 0x50, 0x2F, 0x00,
    0x3E, 0x45, 0x55, 0x51, 0x3E, 0x00,
    0x48, 0x50, 0x7E, 0x50, 0x48, 0x00,
    0x3E, 0x49, 0x71, 0x49, 0x3E, 0x00,
    0x10, 0x22, 0x4F, 0x20, 0x10, 0x00,
    0x0E, 0x06, 0x0A, 0x10, 0x20, 0x00,
    0x20, 0x10, 0x0A, 0x06, 0x0E, 0x00,
    0x08, 0x08, 0x08, 0x1C, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
