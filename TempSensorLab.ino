#include <Wire.h> 
#include <LiquidCrystal.h>



float temp; 
float tempF;
int analoginput = A0; 

float scale(float val, float inMin, float inMax, float outMin, float outMax);

void setup()
{
  Serial.begin(9600);
//  lcd.begin(16,2);
//  lcd.init(); // initialize the lcd
//  lcd.backlight();
}

void loop()
{

  float scale(float val, float inMin, float inMax, float outMin, float outMax);
    Serial.println(scale(5, 0, 10, 20, 100));
    
    delay(2000);

   
//  analogReference(EXTERNAL); //check external pin 4.096v
//  delay(20);
//  temp = analogRead(analoginput);
//  temp = ((temp / 1024) * 4.096) * 1000;
//  
//  tempF = ((temp * 1.8) + 32);
//  //Print temp to serial monitor
//  Serial.print(" %, Temp: ");
//  Serial.print(temp);
//  Serial.println(" Celsius");
// 
//  lcd.setCursor(0,0);
//  lcd.print("Temp: "); 
//  lcd.print(tempF);
//  lcd.println("Fahrenheit");
//  delay(2000);


}

float scale(float val, float inMin, float inMax, float outMin, float outMax){
  float Num = outMin + (((val - inMin)*(outMax - outMin)) / (inMax - inMin));  
  return Num;
}
