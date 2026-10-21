#pragma once

#include "Lighting.h"

namespace sensors {

class LightingResolver {
public:
    LightingResolver(int thresholdDark, int thresholdLight);

    Lighting resolve(int value) const;

private:
    int thresholdDark;
    int thresholdLight;
};

}
