#include "RelayAdapter.h"

namespace output {

RelayAdapter::RelayAdapter(uint8_t pin) : pin(pin) {}

void RelayAdapter::begin() {
    pinMode(pin, OUTPUT);
}

void RelayAdapter::switchRelay(sensors::Lighting lighting) {
    switch (lighting) {
        case sensors::Lighting::DARK:
            digitalWrite(pin, HIGH);
            break;
        case sensors::Lighting::LIGHT:
            digitalWrite(pin, LOW);
            break;
        case sensors::Lighting::TRANSITION:
            break;
    }
}

}
