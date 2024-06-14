#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>

#include "home.h"
#include "wifi.h"
#include "wifi_info.h"

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  setup_wifi();

  // Initialize webserver URLs
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncResponseStream *response = get_homepage(request);
    request->send(response);
  });

  get_wifi_infos(server);

  // Start webserver
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}