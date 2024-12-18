/*pin connection
Sensor to Arduino
trig pin to pin 9 
echo pin on pin 10
gnd pin on gnd
vcc pin on +5v
*/
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

Serial.print("Distance: "); // Prints string "Distance" on the LCD
Serial.print(distanceCm); // Prints the distance value from the sensor
Serial.print("  cm");
delay(10);

Serial.print("Distance: ");
Serial.print(distanceInch);
Serial.print("inch");
delay(10);
Serial.println();
}