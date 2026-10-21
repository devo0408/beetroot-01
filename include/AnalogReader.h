#pragma once

#include <Arduino.h>

namespace sensors {

class AnalogReader {
public:
    static constexpr uint8_t ADC_RESOLUTION_BITS = 12;
    static constexpr int ADC_MIN = 0;
    static constexpr int ADC_MAX = (1 << ADC_RESOLUTION_BITS) - 1; // 4095

    AnalogReader(uint8_t pin, size_t sampleCount, uint32_t readIntervalMs);

    void begin();
    int read() const;

private:
    uint8_t pin;
    size_t sampleCount;
    uint32_t readIntervalMs;
};

} // namespace sensors
