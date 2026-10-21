#pragma once

#include <Arduino.h>

namespace config {

// Monitor configuration
constexpr unsigned long MONITOR_BAUD_RATE = 115200;
constexpr unsigned long MONITOR_PRINT_INTERVAL_MS = 500;

// GPIO configuration
constexpr uint8_t ANALOG_PIN = 6;
constexpr uint8_t RELAY_PIN = 5;

// Sensor configuration
constexpr unsigned long SENSOR_READ_INTERVAL_MS = 100;
constexpr size_t SENSOR_SAMPLE_COUNT = 10;

// Lighting configuration
constexpr int THRESHOLD_DARK = 1000;
constexpr int THRESHOLD_LIGHT = 3000;

} 
