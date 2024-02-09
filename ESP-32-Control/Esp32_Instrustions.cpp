#include <PS4Controller.h>
#include <WiFi.h>


 void Esp32_Instruction() {

  if (PS4.isConnected()) {
    // Correctly calling the method to get the R2 button value and assign it to an integer variable
    int R2Value = PS4.R2Value();

    // Checking if R2Value is greater than or equal to 0
    if (R2Value >= 0) {
      // Mapping the R2Value to a PWM value
      int pWmValue = map(R2Value, 0, 255, 0, 255);

      // If you need to write to a PWM channel, make sure to uncomment and correct this line
      // ledcWrite(channel, pWmValue);

      // Printing the mapped PWM value
      Serial.println(pWmValue);
    }
    // Optional: You can handle the case where R2 is not pressed as needed
    // else {
    //   ledcWrite(channel, 0);  // Setting power to zero if no pressure is detected
    // }
  }
 }

