#include <Arduino.h>
#include "pins.h"

void pin_setup() {
    pinMode(Pins::LED_INTERNAL, OUTPUT);
}

// Toggles the heartbeat pin every 500ms
void tPulseLED(void *pvParameters) {
    TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	for ( ;; ) {
        if (digitalRead(Pins::LED_INTERNAL))
            digitalWrite(Pins::LED_INTERNAL, LOW);
        else
            digitalWrite(Pins::LED_INTERNAL, HIGH);
	    vTaskDelayUntil (& xLastWakeTime, pdMS_TO_TICKS (500));
	}
}
