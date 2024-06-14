#include "wifi.h"

// Connect Wifi, restart if not connecting
// https://techoverflow.net/2021/01/21/how-to-fix-esp32-not-connecting-to-the-wifi-network/
void setup_wifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  uint32_t notConnectedCounter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Wifi connecting...");
    notConnectedCounter++;
    if (notConnectedCounter > 150) {  // Reset board if not connected after 15s
      Serial.println("Resetting due to Wifi not connecting...");
      ESP.restart();
    }
  }
  Serial.print("Wifi connected, IP address: ");
  Serial.println(WiFi.localIP());
}