#ifndef HOME_H
#define HOME_H

#include <ESPAsyncWebServer.h>

#include "SPIFFS.h"

void get_homepage(AsyncWebServer& server);

#endif