// ArduinoIoTCloud - Version: Latest 
#include <ArduinoIoTCloud.h>


#include "thingProperties.h"
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int myLED = 13;
int turbine = A0;

// Variablen für Schlag-Detektion

unsigned long lastPunchTime = 0;
const int PUNCH_DETECTION_INTERVAL = 1000; // 1 Sekunde
const float PUNCH_THRESHOLD = 1.5; // Dieser Wert ist nur ein Schätzwert. Im Test anzupassen

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  pinMode(myLED, OUTPUT);
  pinMode(turbine, INPUT);

  // MPU6050 initialisieren
  Wire.begin();
  mpu.initialize();
  
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 Verbindung fehlgeschlagen");
    while(1);
  }

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  turbinePower = analogRead(turbine);

  // Beschleunigungswerte von MPU6050 lesen
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Einen Schlag detektieren
  float accelerationMagnitude = sqrt(ax*ax + ay*ay + az*az) / 16384.0;  // 16384 ist der Standardwert für den Beschleunigungssensor bei einer Empfindlichkeit von ±2g.
  
  if (accelerationMagnitude > PUNCH_THRESHOLD && millis() - lastPunchTime > PUNCH_DETECTION_INTERVAL) {
    lastPunchTime = millis();
    totalPunches++;
    punshed = true;
    punchPower = accelerationMagnitude;
    frequencyOfPunch = 60000 / PUNCH_DETECTION_INTERVAL; // Schläge pro Minute
  } else {
    punshed = false;
  }
}
/*
  Since PunchPower is READ_WRITE variable, onPunchPowerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPunchPowerChange()  {
  // Add your code here to act upon PunchPower change
}
/*
  Since FrequencyOfPunch is READ_WRITE variable, onFrequencyOfPunchChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onFrequencyOfPunchChange()  {
  // Add your code here to act upon FrequencyOfPunch change
}
/*
  Since TotalPunches is READ_WRITE variable, onTotalPunchesChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTotalPunchesChange()  {
  // Add your code here to act upon TotalPunches change
}
/*
  Since LED is READ_WRITE variable, onLEDChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLEDChange()  {
  // Add your code here to act upon LED change
}
/*
  Since Punshed is READ_WRITE variable, onPunshedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPunshedChange()  {
  // Add your code here to act upon Punshed change
}
