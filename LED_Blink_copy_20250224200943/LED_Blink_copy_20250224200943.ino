
void setup(){
  Serial.begin(115200); //begin and set baude rate 
  Serial.println("ESP32 initilization Completed!");
}

void loop(){
  Serial.printf("Running time: %.1f s\n", millis() / 1000.0f);
  delay(1000);
}