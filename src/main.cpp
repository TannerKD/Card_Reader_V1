#include <Arduino.h>
#include "pins.h"
#include "mqttClient.h"
#include "cardReader.h"

mqttClient client;
cardReader nfcTagReader;

void setup() {
    pin_setup();
    nfcTagReader.setup();
    client.mqttClient::wifiSetup();
    client.mqttClient::mqttSetup();
}

void loop() {
    // Serial
    Serial.begin(9600);
    // Queue Initialization

    // Setup Functions

    // RTOS Task Creation
    xTaskCreate(tPulseLED, "Pulse LED", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(tCardRead, "Card Read", 4096, NULL, 2, NULL);
    xTaskCreate(tMQTTPubSub, "MQTT Publisher/Subscriber", 4096, NULL, 2, NULL);
}
