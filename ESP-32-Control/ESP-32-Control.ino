#include <PS4Controller.h>
#include <WiFi.h>
#include "LCDInstruction.h"

#define PwM_Channel 1  // Rx0 is recieving 16 or 3 nd Tx is trasnimitting 17 or 1
#define PwM_Freq 1000 // This will allow motor for steady motion and less noise
#define PwM_Reso 8   // Controller is 8 bits so it will send 8 bits a time


void Esp32_Instruction();

void setup() {
  Serial.begin(115200);

  lcdSetup();
  lcdInstruction(PS4.isConnected());

  ledcSetup(PwM_Channel,PwM_Freq, PwM_Reso );    // This will give the channel we want these properties
  ledcAttachPin(3, 1);                         // This will send the TX channel to the RX channnel which will give it the necessary output

  PS4.begin("48:e7:29:9b:ae:30");                // This is the macadress of Esp32 which the PS4 contoller connects too
  Serial.println("Ready.");

  Serial.println("WiFi MAC: ");
  Serial.println(WiFi.macAddress());
  
}

void loop() {

  static bool lastConnectionStatus = false;
  bool currentConnectionStatus = PS4.isConnected();

  if (currentConnectionStatus != lastConnectionStatus){
    lcdInstruction(currentConnectionStatus);
    lastConnectionStatus = currentConnectionStatus;

  }

  if (PS4.isConnected()) {
    Serial.println("Connected!");
    Serial.println(WiFi.macAddress());
    Esp32_Instruction();
  }
  else {
    Serial.println("Not Connected!");
    Serial.println(WiFi.macAddress());
  }

  delay(1000);
}