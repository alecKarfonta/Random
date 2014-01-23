#include <AFMotor.h>


char incomingByte = 0;   // for incoming serial data from the bluetooth chip
AF_DCMotor motor1(3, MOTOR12_64KHZ);
AF_DCMotor motor2(1, MOTOR12_64KHZ);

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        motor1.setSpeed(255);
        motor2.setSpeed(255);
}

void loop() {
        int steeringPosition = 0;
        // send data only when you receive data:
        if (Serial.available() > 0) {
                
                // read the incoming byte:
                incomingByte = Serial.read() - '0';
                Serial.println(incomingByte);
                
                
                if ( incomingByte == '1' ) {
                     motor1.run(FORWARD);
                     motor2.run(BACKWARD);
                     Serial.println("left");
                }
                
                if ( incomingByte == '4' ) {
                     motor2.run(FORWARD);
                     motor1.run(BACKWARD);
                     Serial.println("right");
                }
                
                if ( incomingByte == 'G' ) {
                   motor1.run(FORWARD);
                   motor2.run(FORWARD);
                   Serial.println( "got w" );
                }
                
                if ( incomingByte == 'C' ) {
                   motor1.run(BACKWARD);
                   motor2.run(BACKWARD); 
                   Serial.println( "got s" );
                }
                
                if ( incomingByte == 'A' ) {
                   motor1.run(RELEASE);
                   motor2.run(RELEASE); 
                   Serial.println( "got q" );
                }
                
                
        }
        
}
