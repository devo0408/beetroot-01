#pragma once

#include <stdint.h>

namespace sensors {

enum class Lighting : int8_t {
    DARK = -1,
    LIGHT = 1,
    TRANSITION = 0
};

}
