#include "home.h"

AsyncResponseStream *get_homepage(AsyncWebServerRequest *request) {
  AsyncResponseStream *response = request->beginResponseStream("text/html");
  response->printf(
      "<!DOCTYPE html><html><head><title>Webpage at %s</title></head><body>",
      request->url().c_str());
  response->print("<h1>Hello ");
  response->print(request->client()->remoteIP());
  response->print("</h1>");
  response->print("</body></html>");
  return response;
}