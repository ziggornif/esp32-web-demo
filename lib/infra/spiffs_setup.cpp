#include "spiffs_setup.h"

int setup_spiffs() {
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return 1;
  }
  Serial.println("SPIFFS mounted");
  return 0;
}
