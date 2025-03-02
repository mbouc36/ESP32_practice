#define PIN_BUZZER 13
#define PIN_BUTTON 4
#define CHN        0 //define PWM channel

void setup() {
  pinMode(PIN_BUTTON, INPUT);

  //PWM config
  ledcAttachChannel(PIN_BUZZER, 1, 10, CHN); //attach led pin to PWM channel
  ledcWriteTone(PIN_BUZZER, 2000); // sound at 2kHz for 0.3s, this function generates a square wave with duty cycle 50%
  delay(300);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW){
    alert();
  } else{
    ledcWriteTone(PIN_BUZZER, 0);
  } 
}

void alert(){
  float sinVal; //variable to store sine value
  int toneVal; // variable to store sound frequency
  for (int x = 0; x < 360; x += 10){ //x from 0 -> 360 degrees
    sinVal = sin(x * (PI / 100));
    toneVal = 2000 + sinVal * 500;
    ledcWriteTone(PIN_BUZZER, toneVal);
    delay(10);
  }
}