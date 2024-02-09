#include <PS4Controller.h>

void loop(){
 if (PS4.isConnected()) {
  
  int R2Value = PS4.R2Value()  // This will return a value depedning how hard the R2 value is being pressed.
 
  if (PS4.R2 > 0){
    int pWmValue = map(R2Value, 0, 255, 0, 255); // This Translates the pressure given to a value we will use for control 
    ledcWrtie(channel, pWmValue); // This is the amount of power based on the pressure out that was read from previous line
  }
  else {
    ledcWrite(channel, 0);       // If no pressure is detected the power will be by default set to zero
  }

 }

 /* if (PS4.Connected()){
    if (PS4.L2 > 0 ){
      
      int L1Value = PS4.L2Value()   // This will return a value depending on the amount of pressure that is given

      int pWm2Value = map(L2Value, 255, 0, 255, 0);    // Based on the values that are given back it will be able to assign that value to power outputted
      ledcWrite(channel, pWm2Value);
    }
    else{
      ledcWrite(channel, 0);

    }

 /*   }


  }

  

 }
