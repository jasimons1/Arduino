void setup() {
  pinMode(5, OUTPUT); // aansluiting op pin 5
  pinMode(6, OUTPUT); // aansluiting op pin 6
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  for(int i = 5; i <= 12; i++) {  // Loopje door pin 5 t/m 12
    digitalWrite(i, HIGH);        // Lampje fel aan
    delay(100);                   // 100ms delay
    digitalWrite(i - 1, LOW);     // 
  }
  
  for(int i = 12; i >= 5; i--) {  //  
    digitalWrite(i, HIGH);        //
    delay(100);                   //
    digitalWrite(i + 1, LOW);     //
  }
}
