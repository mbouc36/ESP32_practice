#define PIN_ANALOG_IN 4


void setup() {
  Serial.begin(115200);
}

void loop(){
  int adcVal = analogRead(PIN_ANALOG_IN);
  int dacVal = map(adcVal, 0, 4095, 0, 255); // converts range of 0-4095 to range of 0 to 255
  double voltage = adcVal /4095.0 * 3.3;
  dacWrite(DAC1, dacVal);
  Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  delay(200);
}