#include <Arduino.h>

constexpr uint8_t LDR_PIN = 4;

constexpr uint16_t ADC_MAX = 4095;
constexpr uint16_t U_REF_MV = 3100;
constexpr uint32_t READ_INTERVAL_MS = 100;

uint32_t lastReadMs = 0;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
}

void loop() {
  const uint32_t now = millis();
  if (now - lastReadMs < READ_INTERVAL_MS) {
    return;
  }
  lastReadMs = now;

  const uint16_t raw = analogRead(LDR_PIN);
  const float calculatedMv = (float)raw * U_REF_MV / ADC_MAX;
  const uint32_t measuredMv = analogReadMilliVolts(LDR_PIN);

  Serial.printf("RAW: %u, Calc: %.1f mV, Measured: %u mV\n",
                raw, calculatedMv, (unsigned)measuredMv);
}
