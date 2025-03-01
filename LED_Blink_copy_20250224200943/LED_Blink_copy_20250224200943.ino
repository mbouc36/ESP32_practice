const byte ledPins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23}; //define LED pins
const byte chns[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // define the pwm channels
const int dutys[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     1023, 512, 256, 128, 64, 32, 16, 8, 4, 2,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
                     }; // define the pwm dutys

int ledCounts; //led counts
int delayTimes = 50; // flowing speed, the smaller, the faster

void setup() {
  ledCounts = sizeof(ledPins);
  for (int i = 0; i < ledCounts; i++){
    ledcAttachChannel(ledPins[i], 1000, 10, chns[i]); // attach each LED pin
  }
}

void loop() {
  // flowing one side to the other R to L
  for (int i = 0; i < 20; i++){
    // loop 0 - 19
    for (int j = 0; j < ledCounts; j++){ // loop through each LED 15-23
      ledcWrite(ledPins[j], dutys[i + j]);
    }
    delay(delayTimes);
  }

  // flowing opposite direction L to R
  for (int i = 0; i < 20; i++ ){
    for (int j = ledCounts - 1; j > -1; j--){
      ledcWrite(ledPins[j], dutys[i + (ledCounts -1 - j)]);
    }
    delay(delayTimes);
  }
}