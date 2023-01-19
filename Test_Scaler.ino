#include <math.h>
#include <stdio.h>


float scale(float val, float inMin, float inMax, float outMin, float outMax);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

float scale(float val, float inMin, float inMax, float outMin, float outMax);
    Serial.println(scale(5, 0, 10, 20, 100));
    
    delay(2000);
}

float scale(float val, float inMin, float inMax, float outMin, float outMax){
  float Num = outMin + (((val = inMin) * (outMax - outMin)) / (inMax - inMin));  
  return Num;
}
