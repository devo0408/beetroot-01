#pragma once

#include <Arduino.h>

class AnalogReader {
public:
    AnalogReader(uint8_t pin, size_t sampleCount, uint32_t readIntervalMs);

    void begin();
    int read() const;

private:
    uint8_t pin;
    size_t sampleCount;
    uint32_t readIntervalMs;
};
