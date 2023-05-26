// Pin assignments
const int buttonPin = 2;    // Button pin
const int relay1Pin = 9;    // Relay 1 control pin
const int relay2Pin = 10;    // Relay 2 control pin


const unsigned long relayInterval = 1700;
const int numPins = 13;  // Total number of digital pins
const int excludedPins[] = {2, 9, 10};  // Pins to exclude

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  // Set relay 2 pin as output
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, LOW);
  for (int i = 0; i < numPins; i++) {
    pinMode(A0 + i, OUTPUT);
    digitalWrite(A0 + i, HIGH);
  }
  for (int i = 0; i < numPins; i++) {
    if (!isExcludedPin(i)) {
      pinMode(i, OUTPUT);
      digitalWrite(i, HIGH);
    }
  }
  delay(2000);
}

void loop() {
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);

  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, HIGH);
    delay(relayInterval);
    digitalWrite(relay1Pin, HIGH);
    delay(2500);
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, LOW);
    delay(relayInterval);

  }


}

bool isExcludedPin(int pin) {
  for (int i = 0; i < sizeof(excludedPins) / sizeof(excludedPins[0]); i++) {
    if (pin == excludedPins[i]) {
      return true;
    }
  }
  return false;
}
