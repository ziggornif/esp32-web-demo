#include "home.h"

void get_homepage(AsyncWebServer &server) {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });
}