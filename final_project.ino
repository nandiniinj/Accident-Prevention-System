// Define the pin numbers
const int headLampF1=SCL;
const int headLampF2=SDA;

const int ldrSensor=A0;

int ldrValue=0;
int motorPin1 = 6;
int motorPin2 = 7;
int motorPin3 = 4;
int motorPin4 = 5;
#define trigPin 13
#define echoPin 12
int duration, distance;
int redPin = 10;
int bluePin = 11;
int greenPin = 12;



void setup() {
  
pinMode(headLampF1, OUTPUT);
pinMode(headLampF2, OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(trigPin, OUTPUT); // the trigger is output, sends signal
pinMode(echoPin, INPUT); //the echo is input, receives signal
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
Serial.begin(100);
  // start the monitor, allows the arduino to read the distance number from the ultrasonic
    // Set the pin modes of the above IO pins to OUTPUT

}
void ldr(void)
{
  ldrValue=analogRead(ldrSensor);
  ldrValue=map(ldrValue,0,1023,255,0);
}

void loop() {
  ldr();
  if(ldrValue > 100) { 
    digitalWrite(headLampF1, HIGH);
    digitalWrite(headLampF2, LOW);
  }
  else { 
    digitalWrite(headLampF1, LOW);
    digitalWrite(headLampF2, HIGH);
  }
  digitalWrite(trigPin, HIGH);
_delay_ms(500);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1; // duration is divided by 2 because it has to travel to the object and back, the 29.1 number is the conversion factor for converting the speed of sound to cm
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
  


  
  if (distance <= 20){
  //stop
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  	digitalWrite(motorPin3, LOW);
  	digitalWrite(motorPin4, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
	digitalWrite(8, LOW);
    delay (1000);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  	digitalWrite(motorPin3, LOW);
  	digitalWrite(motorPin4, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
	digitalWrite(8, LOW);
    delay (1000);
  }
  else{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  	digitalWrite(motorPin3, HIGH);
  	digitalWrite(motorPin4, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
	digitalWrite(8, HIGH);
}
}