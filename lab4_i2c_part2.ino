#include <Wire.h>
#include "SoftwareSerial.h"


void setup(){
Serial.begin(9600);
Wire.begin(); 
Wire.beginTransmission(0x9A/2); //talk to mcp3221
Wire.setClock(10000); //setting clock low
Wire.endTransmission(); //stop
}

void loop(){
  Wire.requestFrom(0x9A/2, 6); 
  int reading = Wire.read();  
  reading << 3;
  reading >> 4;
  Serial.println(reading);
  delay(1);
  
}
