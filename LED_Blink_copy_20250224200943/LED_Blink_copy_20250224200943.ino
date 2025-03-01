// This code uses PWM to control the color of an RGB LED


const byte ledPins[] = {4, 2, 15}; // define red gree and blue pins
const byte chns[] = {0, 1, 2}; // define pwm channels
int red, green, blue;
void setup() {
  for (int i = 0; i < 3; i++ ){ // set the pwm channels, one for each led, 1kHz, 8 bit
    ledcAttachChannel(ledPins[i], 1000, 8, chns[i]);
  }
}

void loop() {
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColor(red, green, blue);
  delay(200);
}

void setColor(byte r, byte g, byte b){
  ledcWrite(ledPins[0], 255 - r); 
  ledcWrite(ledPins[1], 255 - g);
  ledcWrite(ledPins[2], 255 - b);
}