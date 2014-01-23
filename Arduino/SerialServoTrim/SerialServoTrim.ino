#include <SoftwareServo.h>

SoftwareServo servo1;
SoftwareServo servo2;

void setup()
{
  pinMode(13,OUTPUT);
  servo1.attach(9);
  servo1.setMaximumPulse(2200);
  Serial.begin(9600);
  Serial.print("Ready\n");
}

void loop()
{
  if ( Serial.available()) {
    char ch = Serial.read();
    Serial.print("Got\n");
    switch(ch) {
      case 'a':
        servo1.attach(9);
        Serial.print("On\n");
        break;
      case 'g':
        //servo1.write(90);
        Serial.print("TURN!");
        digitalWrite(13,HIGH);
        break;
      case 'S':
        servo1.write(0);
        Serial.print("Stop\n");
        digitalWrite(13,LOW);
        Serial.print("Off");
        break;
    }
  }
  SoftwareServo::refresh();
}
