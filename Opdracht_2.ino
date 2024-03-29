const unsigned int buttonPin = 2;
const unsigned int ledPin = 11;

int buttonState = 0;
int oldButtonState = LOW;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != oldButtonState &&
      buttonState == HIGH)
  {
    ledState = (ledState == LOW ? HIGH : LOW);
    digitalWrite(ledPin, ledState);
    delay(50);
  }
  oldButtonState = buttonState;
}
