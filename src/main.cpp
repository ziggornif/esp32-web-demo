#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>

#include "home.h"
#include "spiffs_setup.h"
#include "wifi_info.h"
#include "wifi_setup.h"

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  int wrcode = setup_wifi();
  if (wrcode == 1) {
    ESP.restart();
  }

  int srcode = setup_spiffs();
  if (srcode == 1) {
    ESP.restart();
  }

  get_homepage(server);
  get_wifi_infos(server);

  // Start webserver
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}