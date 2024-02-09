#include <PS4Controller.h>
#include <WiFi.h>


 void Esp32_Instruction() {

  if (PS4.isConnected()) {           // Will call this function if it is True

    int R2Value = PS4.R2Value();     //This will return a value depending on the amount of pressure that is given

    if (R2Value > 0) {

      int pWmValue = map(R2Value, 0, 255, 0, 255);    //Based on the values that are given back it will be able to assign that value to power outputted

      // ledcWrite(channel, pWmValue);     // From previous line it will get the pWm value and actually output that given power

         Serial.println(R2Value);          // This will just print out the power that is being outputted to terminal
    }

    // else {
    //   ledcWrite(channel, 0);  // It will make the power zero if nothing is detected
    // }
  }
 }

