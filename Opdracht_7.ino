// Include servo library
#include<Servo.h>
// Define servo
Servo Myservo;

const int echoPin=10;
const int trigPin=12;
const int servoPin=3;
long duration;
int distance;

void setup(){
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Myservo.attach(servoPin);
  Myservo.write(0);
}

void loop()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance <= 10)
    Myservo.write(180 / distance - 4);
  else
    Myservo.write(0);
  delay(100);
}
