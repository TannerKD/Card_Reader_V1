#include "mqttClient.h"

unsigned long lastMillis = 0;

void tMQTTPubSub(void *pvparameters) {
  TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	for ( ;; ) {
    // TODO: Implement task
    vTaskDelayUntil (& xLastWakeTime, pdMS_TO_TICKS (100)); // Sends every 1000ms
	}
}

void mqttCallback(String &topic, String &payload) {
    // Implement callback function
}

void mqttClient::wifiSetup() {
    // Reset WiFi connection
    WiFi.disconnect();
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        // TODO: Implement LCD waiting message
        delay(1000);
    }
    // TODO: Implement WiFi connected output
}

void mqttClient::mqttSetup() {
    // Establish client connection
    client.begin("broker.emqx.io", net);
    client.onMessage(mqttCallback);
    while (!client.connect(clientID, clientUser, clientPass)) {
        // TODO: Implement LCD waiting message
        delay(1000);
    }
    // TODO: Implement client connected message
    client.subscribe(topic);
}
