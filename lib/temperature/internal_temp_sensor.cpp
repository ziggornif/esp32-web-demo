#include "internal_temp_sensor.h"

float read_sensor_temp() {
  float temperature = temperatureRead();
  return temperature;
}