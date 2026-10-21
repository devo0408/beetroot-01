#include "LightingResolver.h"

namespace sensors {

LightingResolver::LightingResolver(int thresholdDark, int thresholdLight)
    : thresholdDark(thresholdDark), thresholdLight(thresholdLight) {}

Lighting LightingResolver::resolve(int value) const {
    if (value < thresholdDark) {
        return Lighting::DARK;
    }
    if (value > thresholdLight) {
        return Lighting::LIGHT;
    }
    return Lighting::TRANSITION;
}

}
