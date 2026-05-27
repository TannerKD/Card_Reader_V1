#include <WiFi.h>
#include <MQTT.h>
#include <string>
#include "mqttClient.h"

unsigned long lastMillis = 0;

void mqttClient::wifiConnect() {
    WiFi.disconnect();
    WiFi.begin(mqttClient::ssid, mqttClient::pass);
    // implement LCD output here.
}

