#include <SPI.h>
const byte CS = 8; //slave select
const byte CLK = 13;

void setup() {
  pinMode(CS, OUTPUT); //SS pin as an output
  Serial.begin(9600);
  SPI.begin();//SPI library
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0); //clock idles in low state
  digitalWrite(CS, LOW); 
  digitalWrite(CS, HIGH);//unknown pin state
  digitalWrite(CLK, LOW);//since mode 0
}
void loop() {
   digitalWrite(CS, LOW);
   int reading = SPI.transfer16(0xFF); //sending 16 bytes of data while also sending dummy bytes
   digitalWrite(CS, HIGH);
   reading << 3;
   reading >> 4;
   float MSB = reading * (4.096/4096);     
   Serial.println(MSB); 
   delay(1);
    
  
}
