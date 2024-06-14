#include "wifi_info.h"

void get_wifi_infos(AsyncWebServer &server) {
  server.on("/api/wifi-info", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncResponseStream *response =
        request->beginResponseStream("application/json");
    DynamicJsonDocument json(1024);
    json["status"] = "ok";
    json["ssid"] = WiFi.SSID();
    json["ip"] = WiFi.localIP().toString();
    float temperature = read_sensor_temp();
    json["boardTemperature"] = String(temperature, 2) + " °C";
    serializeJson(json, *response);
    request->send(response);
  });
}