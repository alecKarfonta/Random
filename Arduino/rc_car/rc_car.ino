#include <Servo.h>
#include <AFMotor.h>


char incomingByte = 0;   // for incoming serial data from the bluetooth chip
Servo steeringMotor;
AF_DCMotor driveMotor(3, MOTOR12_8KHZ);

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        steeringMotor.attach(9);
        steeringMotor.write(90);
        driveMotor.setSpeed(255);
}

void loop() {
        int steeringPosition = 0;
        // send data only when you receive data:
        if (Serial.available() > 0) {
                
                // read the incoming byte:
                incomingByte = Serial.read() - '0';
                Serial.println(incomingByte);
                
                
                if ( incomingByte == '1' ) {
                     steeringMotor.write(30);
                     Serial.println("left");
                }
                
                if ( incomingByte == '4' ) {
                     steeringMotor.write(160);
                     Serial.println("right");
                }
                
                if ( incomingByte == 'G' ) {
                   driveMotor.run(FORWARD);
                   delay(2000);
                   driveMotor.run(RELEASE);
                   Serial.println( "got w" );
                }
                
                if ( incomingByte == 'C' ) {
                   driveMotor.run(BACKWARD);
                   delay(2000);
                   driveMotor.run(RELEASE); 
                   Serial.println( "got s" );
                }
        }
        
}
