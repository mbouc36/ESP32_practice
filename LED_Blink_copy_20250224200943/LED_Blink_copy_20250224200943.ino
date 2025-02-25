#define PIN_LED 2
#define CHN 0 // define the pwm channel
#define FRQ 1000 //define PWM frequencey
#define PWM_BIT 8 // define the pwm precision 

void setup(){
  ledcAttachChannel(PIN_LED, FRQ, PWM_BIT, CHN); //attach LED pin to pwm channel
}

void loop() {

  // make light fade in
  for (int i = 0; i < 255; i++){
    ledcWrite(PIN_LED, i);
    delay(10);
  }

  // make light fade out
  for (int i = 255; i > -1 ; i--){
    ledcWrite(PIN_LED, i);
    delay(10);
  }
}

