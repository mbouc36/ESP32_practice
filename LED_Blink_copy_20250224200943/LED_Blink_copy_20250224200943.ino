String inputString = ""; // a String to hold incoming data
bool stringComplete = false; // whether the string complete

void setup(){
  Serial.begin(115200); //begin and set baude rate 
  Serial.println(String("\nESP32 initilization Completed! \n")
                        + String("Please input some characters, \n")
                        + String("select \"Newline\" below and click send button \n"));
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
    Serial.printf("inputString: %s \n", inputString);
    inputString = "";
    stringComplete = false;
}
}