#include <Arduino.h>
#include "AnalogReader.h"
#include "LightingResolver.h"
#include "RelayAdapter.h"
#include "config.h"

sensors::AnalogReader reader(config::ANALOG_PIN, config::SENSOR_SAMPLE_COUNT, config::SENSOR_READ_INTERVAL_MS);
sensors::LightingResolver resolver(config::THRESHOLD_DARK, config::THRESHOLD_LIGHT);
output::RelayAdapter relay(config::RELAY_PIN);

void setup() {
    Serial.begin(config::MONITOR_BAUD_RATE);

    reader.begin();
    relay.begin();
}

void loop() {
    int value = reader.read();
    sensors::Lighting lighting = resolver.resolve(value);

    Serial.print(value);
    Serial.print(" ");
    Serial.println(static_cast<int8_t>(lighting));

    relay.switchRelay(lighting);
    
    delay(config::MONITOR_PRINT_INTERVAL_MS);
}
