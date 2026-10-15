#include <Arduino.h>
#include "BlinkMode.h"

const int RED_LED = 15;
const int BLUE_LED = 16;

const int EXTERNAL_BUTTON = 21;
const int BOOT_BUTTON = 0;

BlinkMode currentMode = BlinkMode::SYNC;

int lastExternalButtonState = HIGH;
int lastBootButtonState = HIGH;

const unsigned long DEBOUNCE_DELAY = 50;

void checkButtons();
void blinkSynchronously();
void blinkAlternately();

void setup() {
    Serial.begin(115200);

    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    pinMode(EXTERNAL_BUTTON, INPUT_PULLUP);
    pinMode(BOOT_BUTTON, INPUT);

    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    Serial.println("Program started");
    Serial.println("Mode 1: Synchronous blinking");
}

void loop() {
    checkButtons();

    if (currentMode == BlinkMode::SYNC) {
        blinkSynchronously();
    } else {
        blinkAlternately();
    }
}

void checkButtons() {
    int externalState = digitalRead(EXTERNAL_BUTTON);
    int bootState = digitalRead(BOOT_BUTTON);

    if (externalState == LOW && lastExternalButtonState == HIGH) {
        currentMode = BlinkMode::SYNC;
        Serial.println("Mode 1: Synchronous blinking");
    }

    if (bootState == LOW && lastBootButtonState == HIGH) {
        currentMode = BlinkMode::ALTERNATING;
        Serial.println("Mode 2: Alternating blinking");
    }

    lastExternalButtonState = externalState;
    lastBootButtonState = bootState;

    delay(DEBOUNCE_DELAY);
}

void blinkSynchronously() {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    delay(200);

    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    delay(200);
}

void blinkAlternately() {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay(1000);

    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
}