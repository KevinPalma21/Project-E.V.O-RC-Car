#include <PS4Controller.h>




void loop(){
 if (PS4.isconnected()) {
  if (PS4.R1()){
    ledcWrite(channel,128)



  }

 }