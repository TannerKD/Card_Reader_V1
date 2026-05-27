#include "mqttClient.h"

unsigned long lastMillis = 0;

void mqttCallback(String &topic, String &payload) {
    // Callback function
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
