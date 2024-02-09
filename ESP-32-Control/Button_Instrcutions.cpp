#include <PS4Controller.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  PS4.begin("48:e7:29:9e:6b:10");
  Serial.println("Ready.");

  Serial.println("WiFi MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {

  if (PS4.isConnected()) {

    int R2Value = PS4.R2Value()  // This will return a value depedning how hard the R2 value is being pressed.

    if (PS4.R2Value >= 0) {
      int pWmValue = map(R2Value, 0, 255, 0, 255);  // This Translates the pressure given to a value we will use for control
      //ledcWrtie(channel, pWmValue);
      serial.println(pWnValue);  // This is the amount of power based on the pressure out that was read from previous line
    }
    //else {
      //ledcWrite(channel, 0);  // If no pressure is detected the power will be by default set to zero
    //}
  }
}
