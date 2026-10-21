#pragma once

#include <Arduino.h>
#include "Lighting.h"

namespace output {

class RelayAdapter {
public:
    explicit RelayAdapter(uint8_t pin);

    void begin();
    void switchRelay(sensors::Lighting lighting);

private:
    uint8_t pin;
};

}
