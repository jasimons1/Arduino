// Deze code is met behulp van Elske tot stand gekomen

#include <stdlib.h> 

const int ledPin[] = {2, 3, 4};
unsigned long previousMillis = 0;
unsigned long currentMillis = millis();

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);

  // Wanneer de random functie aangesproken wordt komt er telkens een andere output uit   
  randomSeed(analogRead(A0));
}

void loop() {

  // Het laten knipperen van de oranje lamp wanneer er niet op de knop wordt gedrukt
  digitalWrite(ledPin[1], HIGH);
  delay(1000);
  digitalWrite(ledPin[1], LOW);
  delay(1000);

  // Controleert of er een input wordt ontvangen vanuit de Androidapplicatie
  if (Serial.available()) {

    // De code vanuit de Androidapplicatie wordt opgehaald 
    // Deze wordt in een variabele geplaatst    
    char mander = Serial.read();

    // Als er geregistreerd wordt dat er in de Androidapplicatie op de knop is gedrukt dan de functies doorlopen om de lampen aan te zetten
    if (mander == '1') {
      
      // Groene lamp willekeurig tussen de 8 en 15 seconden aanzetten zolang de millis() onder het willekeurig gekozen getal blijven
      digitalWrite(ledPin[0], HIGH);    
      int greenDuration = random(8000, 15000);
      previousMillis = millis();
      while (millis() - previousMillis < greenDuration) {
        
    }

      // Groene lamp uitzetten en de oranje lamp voor 3 seconden aanzetten
      digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], HIGH);
      previousMillis = millis();
      int orangeDuration = 3000;
      while (millis() - previousMillis < orangeDuration) {
       
      }

      // Oranje lamp uitzetten en de rode lamp tussen de 8 en 15 seconden aanzetten zolang de millis() onder het willekeurig gekozen getal blijven
      digitalWrite(ledPin[1], LOW);
      digitalWrite(ledPin[2], HIGH);
      int redDuration = random(8000, 15000);
      previousMillis = millis();
      while (millis() - previousMillis < redDuration) {
        
      }

      // Rode lamp uitzetten
      digitalWrite(ledPin[2], LOW);
    }
  }
}
