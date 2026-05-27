#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

class mqttClient {
public:
    void mqttCallback(String &topic, String &payload);
    void wifiConnect();
    void mqttSetup();

private:
    const char* ssid= "MYWIRE-WPA-88-2GHZ";
    const char* pass = "Emooph7ieyaet4";
    WiFiClient net;
    MQTTClient client;
};


#endif