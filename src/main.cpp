#include <Arduino.h>
#include "AnalogReader.h"
#include "config.h"

sensors::AnalogReader reader(config::ANALOG_PIN, config::SENSOR_SAMPLE_COUNT, config::SENSOR_READ_INTERVAL_MS);

void setup() {
    Serial.begin(config::MONITOR_BAUD_RATE);

    reader.begin();
}

void loop() {
    int value = reader.read();
    Serial.println(value);
    
    delay(config::MONITOR_PRINT_INTERVAL_MS);
}
