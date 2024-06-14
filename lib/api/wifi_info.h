#ifndef WIFI_INFO_H
#define WIFI_INFO_H

#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>

#include "internal_temp_sensor.h"

void get_wifi_infos(AsyncWebServer& server);

#endif