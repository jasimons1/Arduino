const int boost = 10;
const int redPin = 8;
const int bluePin = 7;
const int greenPin = 6;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  
  // Loop door alle waarden van rood
  for (int redValue = 0; redValue <= 255; redValue++) {
    analogWrite(redPin, redValue);
    
    // Snellere
    redValue = redValue + boost;
    
    // Loop door alle waarden van groen
    for (int greenValue = 0; greenValue <= 255; greenValue++) {
       analogWrite(greenPin, greenValue);
       greenValue = greenValue + boost;
      
      // Loop door alle waarden van blauw
      for (int blueValue = 0; blueValue <= 255; blueValue++) {       
        analogWrite(bluePin, blueValue);
        blueValue = blueValue + boost;
      }
    }
  }
  delay(10);
}
