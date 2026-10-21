#include "AnalogReader.h"

#include <vector>

AnalogReader::AnalogReader(uint8_t pin, size_t sampleCount, uint32_t readIntervalMs)
    : pin(pin), sampleCount(sampleCount), readIntervalMs(readIntervalMs) {}

void AnalogReader::begin() {
    pinMode(pin, INPUT);
}

int AnalogReader::read() const {
    std::vector<int> samples;
    samples.reserve(sampleCount);

    for (size_t i = 0; i < sampleCount; i++) {
        samples.push_back(analogRead(pin));
        if (i < sampleCount - 1) {
            delay(readIntervalMs);
        }
    }

    long sum = 0;
    for (int sample : samples) {
        sum += sample;
    }

    return sum / sampleCount;
}
