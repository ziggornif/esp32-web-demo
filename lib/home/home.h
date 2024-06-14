#ifndef HOME_H
#define HOME_H

#include <ESPAsyncWebServer.h>

AsyncResponseStream *get_homepage(AsyncWebServerRequest *request);

#endif