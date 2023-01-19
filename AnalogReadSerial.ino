/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
int static INPUT_PIN = A0;   // Also at D14
int static PWM_PIN = 10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(PWM_PIN,OUTPUT);
  pinMode(INPUT_PIN,INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(INPUT_PIN);
  int dutyCycle = sensorValue/4; 
  Serial.println(dutyCycle); // print out the value you read:
  delay(1);// delay in between reads for stability
  analogWrite(PWM_PIN,dutyCycle);//starts pwm
}
