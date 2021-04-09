#pragma once

#include "quantum.h"

#define LAYOUT_ortho_3x3( \
      k00, k01, k02, \
      k10, k11, k12, \
      k20, k21, k22  \
) { \
    { k00, k01, k02 }, \
    { k10, k11, k12 }, \
    { k20, k21, k22 } \
}
