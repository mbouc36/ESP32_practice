// This code uses PWM to control the color of an RGB LED for a Gradient Color


const byte ledPins[] = {4, 2, 15}; // define red gree and blue pins
const byte chns[] = {0, 1, 2}; // define pwm channels
int red, green, blue;
void setup() {
  for (int i = 0; i < 3; i++ ){ // set the pwm channels, one for each led, 1kHz, 8 bit
    ledcAttachChannel(ledPins[i], 1000, 8, chns[i]);
  }
}

void loop() {
  for (int i = 0; i < 256; i++){
    setColor(wheel(i));
    delay(20);
  }

}

void setColor(long rgb){
  ledcWrite(ledPins[0], 255 - (rgb >> 16) & 0xFF); 
  ledcWrite(ledPins[1], 255 - (rgb >> 8) & 0xFF);
  ledcWrite(ledPins[2], 255 - (rgb >> 0) & 0xFF);
}

long wheel(int pos){
  long WheelPos = pos % 0xff;
  if (WheelPos < 85) {
    return ((255 - WheelPos * 3) << 16 | ((WheelPos * 3) << 8)); // red to green
  } else if (WheelPos < 170){
    WheelPos -= 85;
    return (((255 - WheelPos * 3) << 8) | (WheelPos * 3)); // green to blue
  }else{
    WheelPos -= 170;
    return ((WheelPos * 3) << 16 | (255 - WheelPos * 3)); // blue to red
  }
  
}