#include <PS4Controller.h>
#include <WiFi.h>

bool breaking = false;
bool isCaron = false;
bool lastState = false;

 void Esp32_Instruction() {

  if (PS4.isConnected()) {           // Will call this function if it is True

    int R2Value = PS4.R2Value();     //This will return a value depending on the amount of pressure that is given

    if (R2Value > 0) {

      int pWmValue = map(R2Value, 0, 255, 0, 255);    //Based on the values that are given back it will be able to assign that value to power outputted

       ledcWrite(1, pWmValue);     // From previous line it will get the pWm value and actually output that given power

         Serial.println(R2Value);          // This will just print out the power that is being outputted to terminal
    }
    else {
      ledcWrite(1, 0);  // It will make the power zero if nothing is detected
     }
  }


  if (PS4.isConnected()) {           // Will call this function if it is True

    int RStick = PS4.RStickX();     //This will return a value depending on the amount of pressure that is given

    if (RStick != 0) {

      int angleValue = map(RStick, -127, 127, -1, 1);    //Based on the values that are given back it will be able to assign that value to power outputted

        ledcWrite(1, angleValue);     // From previous line it will get the pWm value and actually output that given power

        Serial.println(RStick);          // This will just print out the power that is being outputted to terminal
    } 
    else {
      ledcWrite(1, 0);  // It will make the power zero if nothing is detected
    }
  }

   // This will make the L2 value to go backwards in the RC car

  if (PS4.isConnected()) {           // Will call this function if it is True
    
    int L2Value = PS4.L2Value();     //This will return a value depending on the amount of pressure that is given

    if (L2Value > 0) {

      int pWmValue = map(L2Value, 0, 255, 0, 255);    //Based on the values that are given back it will be able to assign that value to power outputted

       ledcWrite(17, pWmValue);     // From previous line it will get the pWm value and actually output that given power

         Serial.println(L2Value);          // This will just print out the power that is being outputted to terminal
    }
    else {
      ledcWrite(17, 0);  // It will make the power zero if nothing is detected
     
     }
  }


  
  if (PS4.isConnected()){     // Call this function if it is true
     
   if (PS4.L1()){             // Function is called when this button is pressed

    breaking = true;           // Set function equal to True for if statment to use later on also breaks are activated
    
    Serial.print(" Car is breaking");  
    Serial.println(breaking ? "True" : "False");


   }

   else {

    breaking = false;         // Set function equal to false also breaks are not activated

   }
  }
 
  if (PS4.isConnected()) {
    bool currentState = PS4.Options(); // Get the current state of the Options button

    // Check if the Options button was pressed since the last check
    if (currentState && !lastState) {
        isCaron = !isCaron; // Toggle the on/off state of the car

        // Print the new state of the car to the serial monitor
        Serial.print("Car is currently on: ");
        Serial.println(isCaron ? "True" : "False");
    }

    // Update the lastState variable to the current state for the next loop iteration
    lastState = currentState;
}
 }


