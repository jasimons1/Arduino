// Deze code is tot stand gekomen met hulp van Eloi

#include <IRremote.h>

const int ledPin[] = {5, 6, 7, 8};
const int irPin = 13;

// De verschillende snelheden (in ms) waarop geknipperd kan worden
const int blinkInterval[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};

// De laatste keer dat de LED aan of uit is gegaan
unsigned long finalTime[] = {0, 0, 0, 0};

// De beginstatus van de LEDS
int ledStartState[] = {LOW, LOW, LOW, LOW};

// De snelheid waarop de LED moet knipperen
int blinkTime[] = {0, 0, 0, 0};

// Bijhouden welke LEDS zijn aangegaan
int ledControl[] = {0, 0, 0, 0};

// De laatste LED die is aangesproken
int ledSelection = -1;

IRrecv irrecv(irPin);
decode_results results;

void setup() {
  
    Serial.begin(9600);
    
    // Zet alle LEDs op OUTPUT
    for (int pin: ledPin) {     
        pinMode(pin, OUTPUT);
    }
    irrecv.enableIRIn();

    // De twee standaard LEDs die bij het opstarten gaan knipperen (met een snelheid van 300ms)
    update(0, 3);
    update(1, 3);
}

void loop() {
  
    // Op het moment dat er geen LED is geselecteerd 
    if (ledSelection == -1) {
      
        // Haal de waarde van IrSensor op en geef de geselecteerde waarde van de IrRemote terug
        ledSelection = turnOnLed(irData());
    } else {
      
        // Op het moment dat er een LED is geselecteerd
        if (ledSelection >= 0) {
          
            // De knippersnelheid van de geselecteerde LED bepalen
            blinkSpeed(ledSelection);
        }
    }
    
    // Bepaal voor alle LEDs of deze aan of uit gezet mogen worden
    for (int i = 0;  i < 4; i++) {     
        blink(i);
    }
}

int irData() {
  
    // Op het moment dat er een signaal binnenkomt
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        irrecv.resume();
        
        // Wanneer de waarde niet gelijk is aan 0
        if (results.value != 0) {
          
            // Geef de data terug
            return (results.value);
        }
    }
}

// hexNumber koppelen aan een knop van de IrRemote
int turnOnLed(int hexNumber) {
    switch (hexNumber) {
        case 0xFF30CF:
            return (0);
            break;

        case 0xFF18E7:
            return (1);
            break;

        case 0xFF7A85:
            return (2);
            break;

        case 0xFF10EF:
            return (3);
            break;

    }

    // Als de input niet bestaat wordt er niks gestuurd
    return -1;
}

void blinkSpeed(int ledNumber) {

    // Haal de inkomende waarde van de IrSensor op
    int hexNumber = irData();

    // Voer de update functie uit op het moment dat de waarde van de IrSensor bekend is en
    // geef de geselecteerde LED de juiste knippersnelheid mee
    switch (hexNumber) {
        case 0xFF30CF:
            update(ledNumber, 1);
            break;

        case 0xFF18E7:
            update(ledNumber, 2);
            break;

        case 0xFF7A85:
            update(ledNumber, 3);
            break;

        case 0xFF10EF:
            update(ledNumber, 4);
            break;

        case 0xFF38C7:
            update(ledNumber, 5);
            break;

        case 0xFF5AA5:
            update(ledNumber, 6);
            break;

        case 0xFF42BD:
            update(ledNumber, 7);
            break;

        case 0xFF4AB5:
            update(ledNumber, 8);
            break;

        case 0xFF52AD:
            update(ledNumber, 9);
            break;
    }
}


void blink(int led) {
    unsigned long currentTime = millis();

    // Zet een LED aan of uit wanneer deze gelijk aan, of hoger is dan, 1 binnen de ledControl
    // en er meer tijd is verstreken dan in de aangegeven blinkTime
    if (currentTime - finalTime[led] >= blinkTime[led] && ledControl[led] >= 1) {
      
        // Maak van het laatste moment dat de LED is aan- of uitgegaan het huidige moment
        finalTime[led] = currentTime;
        
        // Zet de status van de LED op HIGH of op LOW
        ledStartState[led] = (ledStartState[led] == LOW) ? HIGH : LOW;
        
        // Zet de LED aan of uit
        digitalWrite(ledPin[led], ledStartState[led]);
    }
}

void update(int led, int timing) {
  
    // Zet de geselecteerde LED weer op -1
    ledSelection = -1;

    // Op het moment dat de LED nog niet in de blink functie staat
    if (ledControl[led] == 0) {
      
        // Houdt de ledCount bij binnen de for loop
        int ledCount = 0;
        
        // Op het moment dat een LED de waarde 2 (LED die het langste aan is) heeft binnen de ledControl, 
        // zet dan de LED uit en verwijder deze uit de blink functie
        for (int i: ledControl) {         
            if (i == 2) {
                ledStartState[ledCount] = LOW;
                ledControl[ledCount] = 0;
                digitalWrite(ledPin[ledCount], LOW);
            }
            
            // Op het moment dat een LED de waarde 1 (LED die het minst lang aan is) heeft wordt deze omgezet naar waarde 2 (LED die het langste aan is)
            if (i == 1) {
                ledControl[ledCount] = 2;
            }
            ledCount++;
        }
        
        // Zet de status van de huidig geselecteerde LED op HIGH
        ledStartState[led] = HIGH;
        
        // Zet de ledControl op waarde 1 (LED die het minst lang aan is)
        ledControl[led] = 1;
        
        // Zet de huidig geselecteerde LED op HIGH
        digitalWrite(ledPin[led], HIGH);
    }
    
    // Update de knippersnelheid
    blinkTime[led] = blinkInterval[timing];
    blink(led);
}
