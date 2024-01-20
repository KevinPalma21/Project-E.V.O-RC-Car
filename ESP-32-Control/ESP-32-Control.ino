#include <PS4Controller.h>
#include <BluetoothSerial.h>

void setup() {

  Serial.begin(115200); //This is the default baud rate this allows for faster data transfer

  if(!PS4.begin("Mac Address of ESP 32")){ // This if statement will only execute if True so when it fails to connect it will return True and run the code
   Serial.println("Ps4 Controller not paired"); // This is will allow the microcontroller and the computer to communicate (serial) and print the following response
   while(1); // This will make it go into a infinite loop which will make the program stop or in other words get stuck here if the controller doesn't connnect
}
 Serial.println("Ps4 controller Connected")