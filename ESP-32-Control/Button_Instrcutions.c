void loop(){

if (PS4.isConnected()) {
  
  if(PS4.Button(PS4_BUTTON_CROSS){
   CrossButtonPress();
   Serial.println("Cross Button");
  }
  
  if(PS4.Button(PS4_BUTTON_CIRCLE){
   CircleButtonPress();
   Serial.prinln("Circle Button");
  }

   if(PS4.Button(PS4_BUTTON_TRIANGLE){
   TriangleButtonPress();
   Serial.prinln("Triangle Button");
   }

   if(PS4.Button(PS4_BUTTON_SQUARE){
   SqaureButtonPress();
   Serial.prinln("Square Button");
   }







}