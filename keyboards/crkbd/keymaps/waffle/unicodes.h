#pragma once

enum unicodemap_names {
    SIDE, //ツ
    UPAR, //ᛏ
    HAS, //☭
    STAR, //★
    VIB //ॐ
};

 const uint32_t PROGMEM unicode_map[] = {
   [SIDE] = 0x30C4,
   [UPAR] = 0x16CF,
   [HAS] = 0x262D,
   [STAR] = 0x2605,
   [VIB] = 0x0950,
};
