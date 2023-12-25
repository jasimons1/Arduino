#include<Servo.h>
Servo myServo;

void setup()
{
  Serial.begin(9600);
  myServo.attach(2);
  myServo.write(0);
}

void loop()
{
  turnServo();
}

void turnServo()
{
  
  // Het moment waarop beide knoppen worden ingedrukt
  if (digitalRead(5) == LOW && digitalRead(7) == LOW) {
    
    // Draai naar 120 graden binnen 1 seconde
    for (int position = 1; position <= 120; position++) {
      delay(1000/120);
      myServo.write(position);
    }

    // Een vertraging van 2 seconden
    delay(2000);

    // Draai terug naar 0 graden binnen 1 seconde
    for (int position = 120; position >= 0; position--) {
      delay(1000/120);
      myServo.write(position);
    }
    
  // Het moment waarop de knop op pin 7 wordt ingedrukt
  } else if (digitalRead(7) == LOW) {
    
    // Draai naar 120 graden binnen 0,5 seconde
    for (int position = 1; position <= 120; position++) {
      delay(500/120);
      myServo.write(position);
    }

    // Draai terug naar 0 graden binnen 0,5 seconde
    for (int position = 120; position >= 0; position--) {
      delay(500/120);
      myServo.write(position);
    }
    
  // Het moment waarop de knop op pin 5 wordt ingedrukt
  } else if (digitalRead(5) == LOW) {
    
    // Draai naar 120 graden binnen 1 seconde
    for (int position = 1; position <= 120; position++) {
      delay(1000/120);
      myServo.write(position);
    }

    // Draai terug naar 0 graden binnen 1 seconde
    for (int position = 120; position >= 0; position--) {
      delay(1000/120);
      myServo.write(position);
    }
    
  // Stop de servo op het moment dat er geen knop wordt ingedrukt
  } else {
    myServo.write(0);
  }
}
