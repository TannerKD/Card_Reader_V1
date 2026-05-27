#include <Arduino.h>
#include "pins.h"
#include "mqttClient.h"

void setup() {
    pin_setup();
}

void loop() {
    // Serial
    Serial.begin(9600);
    // Queue Initialization

    // Setup Functions

    // RTOS Task Creation
    xTaskCreate(tPulseLED, "Pulse LED", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
}
