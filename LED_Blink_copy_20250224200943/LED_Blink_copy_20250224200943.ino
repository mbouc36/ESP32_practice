byte ledPins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23}; // Each element is 1 byte
int ledCounts;

// Setup function runs once when you press the reset or power the board
void setup() {
  // init the pin as output
  ledCounts = sizeof(ledPins); //not standard C?
  for (int i = 0; i < ledCounts; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

// loops for inf time
void loop() {
  for (int i = 0; i < ledCounts; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = ledCounts - 1; i > -1; i--){
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

