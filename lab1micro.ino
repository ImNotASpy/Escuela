int analoginput = A0; 
float external;
float def;
float internal; 


void setup(){
  Serial.begin(9600);
  pinMode(analoginput,INPUT);
}
void loop(){

analogReference(EXTERNAL); //check external pin 4.096v
delay(20);
external = analogRead(analoginput);
external = ((external / 1024) * 4.096) * 1000;


analogReference(INTERNAL2V5); //internal ref pin 3.5v
delay(20);
internal = analogRead(analoginput);
internal = ((internal / 1024) * 2.5) * 1000;


analogReference(VDD); //default pin 5v
delay(20);
def = analogRead(analoginput);
def = ((def / 1024) * 5) * 1000;

//Serial.println("External Internal Default");
Serial.print(external); Serial.print("  ");
Serial.print(internal); Serial.print("  ");
Serial.print(def); Serial.print("\n");

delay(200);
}
