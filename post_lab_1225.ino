#include <Wire.h>

void setup(){
Wire.begin(); 
Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(0x92/2);
  Wire.write(0x00);
  Wire.endTransmission(); //stop 
  
  Wire.requestFrom(0x92/2, 2); //sent bytes to address
    while(Wire.available()){
      int temp1 = Wire.read(); //read byte as int
      int temp2 = Wire.read(); //read byte as int

      int i = temp1 << 1;
      int j = temp2 >> 7;
      int temp = i|j;
      
      int Realtemp = ((temp * 0.5) * 9/5) + 32;
      Serial.print(Realtemp);
    }
    delay(500);
}
