#include <PS4Controller.h>
#include <WiFi.h>


void Esp32_Instruction();

void setup() {
  Serial.begin(115200);

  // Replace the "1a:2b:3c:01:01:01" with the MAC address
  // the controller wants to pair to
  // Note: MAC address must be unicast
  PS4.begin("48:e7:29:9e:6b:10");
  Serial.println("Ready.");

  Serial.println("WiFi MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {

  if (PS4.isConnected()) {
    Serial.println("Connected!");
    Serial.println(WiFi.macAddress());
  }
  else {
    Serial.println("Not Connected!");
    Serial.println(WiFi.macAddress());
  }

  delay(3000);
}