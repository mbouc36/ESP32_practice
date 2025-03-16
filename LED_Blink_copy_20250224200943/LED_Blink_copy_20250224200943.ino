#define PIN_ANALOG_IN 4
#define PIN_LED 25
#define CHAN 0

void setup() {
  ledcAttachChannel(PIN_LED, 1000, 12, CHAN);
}

void loop(){
  int adcVal = analogRead(PIN_ANALOG_IN); //read adc value
  int pwmVal = adcVal;                    //adcVal re-map to pwmVal
  ledcWrite(PIN_LED, pwmVal);
  delay(10);
}
