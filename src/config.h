#pragma once

#include <Arduino.h>

namespace config {

// Monitor configuration
constexpr unsigned long MONITOR_BAUD_RATE = 115200;
constexpr unsigned long MONITOR_PRINT_INTERVAL_MS = 500;

// GPIO configuration
constexpr uint8_t ANALOG_PIN = 6;

// Sensor configuration
constexpr unsigned long SENSOR_READ_INTERVAL_MS = 100;
constexpr size_t SENSOR_SAMPLE_COUNT = 10;

} 
