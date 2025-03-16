String inputString = ""; // a String to hold incoming data
bool stringComplete = false; // whether the string complete

void setup(){
  Serial.begin(115200); //begin and set baude rate 
  Serial.println(String(\n"ESP32 initilization Completed! \n")) ;
}

void loop(){
  Serial.printf("Running time: %.1f s\n", millis() / 1000.0f);
  delay(1000);
}

String inputString = ""; //a String to hold incoming data bool stringComplete = false; // whether the string is complete
void setup() {
  Serial.begin(115200);
  Serial.println(String("\nESP32 initialization completed! \n")
}
void loop() {
  if (Serial.available()) {
    char inChar = Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  if (stringComplete) {
// judge whether data has been received
     // read one character

  inputString = "";
  stringComplete = false;
}
}