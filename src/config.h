#pragma once

#include <Arduino.h>

// Monitor configuration

// GPIO configuration
constexpr uint8_t ANALOG_PIN = 6;

// Sensor configuration
constexpr unsigned long SENSOR_READ_INTERVAL_MS = 100;
constexpr size_t SENSOR_SAMPLE_COUNT = 10;