#include <AFMotor.h>
#include <Servo.h>

Servo servo1;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  servo1.attach(9);
  servo1.write(0);
}

int i;

void loop() {
  if ( Serial.available()) {
    int input = serReadInt();
    if (input < 0 || input > 47) {
      Serial.println("Bad Angle. Resetting...");
      input = 12;
    }
    Serial.println("Got ");
    Serial.println(input, DEC);
    servo1.write(input);
  }
  delay(20);
}

int serReadInt()
{
 int i, serAva;                           // i is a counter, serAva hold number of serial available
 char inputBytes [7];                 // Array hold input bytes
 char * inputBytesPtr = &inputBytes[0];  // Pointer to the first element of the array
     
 if (Serial.available()>0)            // Check to see if there are any serial input
 {
   delay(5);                              // Delay for terminal to finish transmitted
                                              // 5mS work great for 9600 baud (increase this number for slower baud)
   serAva = Serial.available();  // Read number of input bytes
   for (i=0; i<serAva; i++)       // Load input bytes into array
     inputBytes[i] = Serial.read();
   inputBytes[i] =  '\0';             // Put NULL character at the end
   return atoi(inputBytesPtr);    // Call atoi function and return result
 }
 else
   return -1;                           // Return -1 if there is no input
}



