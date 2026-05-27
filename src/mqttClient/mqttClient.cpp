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
    WiFi.begin(mqttClient::ssid, mqttClient::pass);
    while (WiFi.status() != WL_CONNECTED) {
        // TODO: Implement LCD waiting message
        delay(1000);
    }
    // TODO: Implement WiFi connected output
}

void mqttClient::mqttSetup() {
    // Establish client connection
    client.begin("broker.emqx.io", mqttClient::net);
    client.onMessage(mqttCallback);
    while (!client.connect(mqttClient::clientID,mqttClient::clientUser,mqttClient::clientPass)) {
        // TODO: Implement LCD waiting message
        delay(1000);
    }
    // TODO: Implement client connected message
    client.subscribe(mqttClient::topic);
}
