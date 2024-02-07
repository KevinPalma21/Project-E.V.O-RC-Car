#include <PS4Controller.h>




void loop(){
 if (PS4.isConnected()) {
  int R2Value = PS4.R2Value()  // This will return a value depedning how hard the R2 value is being pressed.
  if (PS4.R2 > 0){
    int pWmValue = map(R2Value, 0, 255, 0, 255) // This Translates the pressure given to a value we will use for control 

    
    


  }

 }