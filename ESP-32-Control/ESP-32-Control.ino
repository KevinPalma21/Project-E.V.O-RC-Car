#include <PS4Controller.h>
#include <WiFi.h>

#define PwM_Channel 17  // Rx is recieving 16 nd Tx is trasnimitting 17
#define PwM_Freq 5000 // This will allow motor for steady motion and less noise
#define PwM_Reso 8   // Controller is 8 bits so it will send 8 bits a time




void Esp32_Instruction();

void setup() {
  Serial.begin(115200);

  ledcSetup(PwM_Channel,PwM_Freq, PwM_Reso );
  ledcAttachPin(16, 17)

  PS4.begin("48:e7:29:9b:ae:30");
  Serial.println("Ready.");

  Serial.println("WiFi MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {

  if (PS4.isConnected()) {
    Serial.println("Connected!");
    Serial.println(WiFi.macAddress());
     Esp32_Instruction();
  }
  else {
    Serial.println("Not Connected!");
    Serial.println(WiFi.macAddress());
  }

  delay(3000);
}