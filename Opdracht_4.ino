float temperature;
int tempPin = 0;

void setup() {
   Serial.begin(9600);
}

void loop() {
  
   // Lees de temperatuurwaarde uit de analoge pin uit
   temperature = analogRead(tempPin);
  
   // Zet de temperatuurwaarde om in graden Celcius
   temperature = temperature * 0.48828125; 
  
   Serial.print("TEMPERATUUR = ");
   Serial.print(temperature); 
   Serial.print("*C");
   Serial.println();
  
   // Zet een vertraging van 1 seconde op het uitlezen van de temperatuur
   delay(1000); 
}
