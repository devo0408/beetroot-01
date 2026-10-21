#include <Arduino.h>
#include "AnalogReader.h"
#include "config.h"

#define ANALOG_PIN 6

AnalogReader reader(ANALOG_PIN, SENSOR_SAMPLE_COUNT, SENSOR_READ_INTERVAL_MS);

void setup() {
    Serial.begin(115200);

    reader.begin();
}

void loop() {
    int value = reader.read();
    Serial.println(value);
    delay(500); 
}
