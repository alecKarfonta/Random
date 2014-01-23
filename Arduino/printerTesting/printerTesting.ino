#include <AFMotor.h>


AF_Stepper motor(48, 2);
int incomingByte = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  motor.setSpeed(20);  // 10 rpm   

  while (!Serial) {
    ;
  }
  
  Serial.println("Serial Inititialized");
}

void loop() {
     // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                Serial.println(incomingByte, DEC);
                // up
                if (incomingByte == 119) {
                  motor.step(100, FORWARD, SINGLE); 
                }
                // down
                if (incomingByte == 115) {
                  motor.step(100, BACKWARD, SINGLE); 
                }
        }
}
