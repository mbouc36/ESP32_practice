#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <String.h>


BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
uint8_t txValue = 0;
long lastMsg = 0;
String rxload="Test\n";

// UUID = Universal Unique Identifiers , 128bit unique identifier
// Service UUID define a group or related functions, in this case the service running on the ESP32
#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" 
// Characterisitc UUIDS define specefic data point within the service 
// Rx -> receive data from client
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
// Tx -> transmit (send) data to client 
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"


class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer){
    deviceConnected = true;
  };
  void onDisconnect(BLEServer* pServer){
    deviceConnected = false;
  }
};


class MyCallbacks: public BLECharacteristicCallbacks { 
  // overrides the BLECharacteristicCallbacks onWrite fxn
  // onWrite is triggered whenever a BLE client writes data to ESP32
  void onWrite(BLECharacteristic *pCharacteristic) {
      String rxValue = pCharacteristic->getValue().c_str(); //read received data
      if (rxValue.length() > 0) { //check if there is data present
        rxload=""; //clears global varaible which stroes string
        for (int i = 0; i < rxValue.length(); i++){
          rxload +=(char)rxValue[i]; // loop through receievd data and converts it into a char
        }
      } 
    }
};


void setupBLE(String BLEName){
  const char *ble_name=BLEName.c_str(); //converts arduino string to C string
  BLEDevice::init(ble_name);
  BLEServer *pServer = BLEDevice::createServer(); //creates server
  pServer->setCallbacks(new MyServerCallbacks()); //assigns MyServerCallbacks to handle server related events
  BLEService *pService = pServer->createService(SERVICE_UUID); // Creates a service with a unique service UUID
  // Creates Tx characteristic, use property notify which means the ESP32 sends an update to the client when data changes 
  pCharacteristic=pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY); 
  pCharacteristic->addDescriptor(new BLE2902()); //adds a descriptor which is required for BLE Clients
  BLECharacteristic *pCharacteristic = //create an Rx Characteristic, use property write which means the client sends data to the ESP32 
  pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setCallbacks(new MyCallbacks()); //custom callback function to handle incoming data
  pService->start(); //start service
  pServer->getAdvertising()->start(); //make visible 
  Serial.println("Waiting a clien connection to notify...");
}


void setup() {
  Serial.begin(115200);
  setupBLE("ESP32_Bluetooth");
}

void loop(){
  long now = millis();
  if (now - lastMsg > 100){ //ensures process once every 100ms
    if (deviceConnected&&rxload.length()>0){
      Serial.println(rxload);
      rxload="";
    }
    if (Serial.available()>0){
      String str=Serial.readString();
      const char *newValue=str.c_str();
      pCharacteristic->setValue(newValue);
      pCharacteristic->notify();
    }
    lastMsg = now;
  }
}
