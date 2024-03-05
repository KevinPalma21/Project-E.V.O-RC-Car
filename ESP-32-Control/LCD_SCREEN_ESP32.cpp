#include "LCDInstruction.h"
#include <WiFi.h>

//GxEPD2_BW<GxEPD2_213_B73, GxEPD2_213_B73::HEIGHT> display(GxEPD2_213_B73(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));
GxEPD2_BW<GxEPD2_213_B74, MAX_HEIGHT(GxEPD2_213_B74)> display(GxEPD2_213_B74(/*CS=*/5, /*DC=*/17, /*RST=*/16, /*BUSY=*/4));


void lcdSetup() {
  display.init();
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
}

void lcdInstruction(bool isPs4Connected) {
  display.fillScreen(GxEPD_BLACK);
  display.setCursor(0, 20);

  if (isPs4Connected){
    display.print("Connected!");
    Serial.println("Its working");
  } else {
    display.print("Not Connected");
    Serial.println("Its working");
  }

  display.setCursor(0, 40);
  display.print(WiFi.macAddress());
  display.display();
}