#define PIN_ANALOG_IN 4
#define PIN_LED 12
#define CHAN 0
#define LIGHT_MIN 372
#define LIGHT_MAX 2048

void setup() {
  ledcAttachChannel(PIN_LED, 1000, 12, CHAN);
}

void loop(){
  int adcVal = analogRead(PIN_ANALOG_IN); //read adc value
  int pwmVal = map(constrain(adcVal, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0, 4095);
  ledcWrite(PIN_LED, pwmVal); //set pwm value
  delay(10);
}
