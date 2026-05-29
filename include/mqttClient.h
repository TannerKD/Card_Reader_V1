#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <WiFi.h>
#include <MQTT.h>
#include <string>

void mqttCallback(String &topic, String &payload);
void tMQTTPubSub(void *pvparameters);

class mqttClient {
public:
    void wifiSetup();
    void mqttSetup();

private:
    const char* ssid = "MYWIRE-WPA-88-2GHZ";
    const char* pass = "Emooph7ieyaet4";
    const char* clientID = "esp-12312312";
    const char* clientUser = "public";
    const char* clientPass = "public";
    const char* topic = "/hello";
    WiFiClient net;
    MQTTClient client;
};


#endif