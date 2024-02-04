void loop(){

if (PS4.isConnected()) {           // This will call the function if it is true then it will run the code

  if(PS4.Button(PS4_BUTTON_CROSS){         // If Cross button is pressed this will run
   CrossButtonPress();
   Serial.println("Cross Button");
  }
  
  if(PS4.Button(PS4_BUTTON_CIRCLE){        // If Circle button is pressed this will run
   CircleButtonPress(); 
   Serial.prinln("Circle Button");
  }

   if(PS4.Button(PS4_BUTTON_TRIANGLE){     // If Triangle button is pressed this will run
   TriangleButtonPress();
   Serial.prinln("Triangle Button");
   }

   if(PS4.Button(PS4_BUTTON_SQUARE){       // If Square button is pressed this will run
   SqaureButtonPress();
   Serial.prinln("Square Button");
   }







}