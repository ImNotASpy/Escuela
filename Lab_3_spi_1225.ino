#include <SPI.h>
const int CS = 8; //slave select
void setup() {
  pinMode(CS, OUTPUT); //SS pin as an output
  Serial.begin(9600);
  SPI.begin();//SPI library
  SPI.setBitOrder(MSBFIRST);
  //this register starts at 0
  digitalWrite(CS, LOW);//Start talk
  SPI.transfer(0x40); //talk to the MCP23008 which has address 00 using SPI 
  SPI.transfer(0x00); //register ic
  SPI.transfer(0x00); //which io
  digitalWrite(CS, HIGH);//SS pin HIGH
}
void loop() {
  for(int i = 0; i <= 100; i++) { //start led counting
    digitalWrite(CS, LOW);//start ss 
    SPI.transfer(0x40); //talk  
    SPI.transfer(0x09);//register leds       
    SPI.transfer(i); 
    digitalWrite(CS, HIGH);//stop SS
    delay(50);   
  } 
}
