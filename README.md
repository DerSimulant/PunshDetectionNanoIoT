# PunshDetectionNanoIoT
German below*************************************
Project to detect punshed with the MPU6050 and the Arduino Nano 33 IoT


Libraries and Objects

ArduinoIoTCloud.h: This is the library required for communicating with the Arduino IoT Cloud.
Wire.h and MPU6050.h: These libraries are needed for communicating with the MPU6050 sensor over the I2C bus.
MPU6050 mpu: Here, an object named mpu of type MPU6050 is created which is used for interfacing with the sensor.


Global Variables

myLED and turbine: These are pin numbers for an LED and a turbine sensor.
lastPunchTime: Stores the last time a punch was detected.
PUNCH_DETECTION_INTERVAL: The time interval (in milliseconds) in which a punch can be detected. Set here to 1 second (1000 ms).
PUNCH_THRESHOLD: The acceleration threshold at which a punch is considered detected.


Setup Function

Serial communication is started.
Pins are configured.
The MPU6050 sensor is initialized.
It checks if a connection to the MPU6050 can be established.
A connection to the Arduino IoT Cloud is established and debug information is printed out.


Loop Function

Here's where the main logic of the program happens:

The IoT Cloud is updated.
The value from the turbine sensor is read.
Acceleration values from the MPU6050 are read.
The magnitude of the acceleration is calculated and compared with the threshold.
It checks if enough time has passed since the last detected punch.
If a punch is detected, relevant variables are updated.


Tuning Parameters:

PUNCH_DETECTION_INTERVAL: This value determines how often a punch can be detected. A higher value means fewer punches per second can be detected; a lower value allows for more frequent detection.
PUNCH_THRESHOLD: This value determines the minimum acceleration to be considered as a punch. A higher value means stronger punches are required for detection, while a lower value might detect softer punches.
By adjusting these two values, you can fine-tune the behavior of the program regarding punch detection.


Functions for IoT Cloud Changes

These functions get called when the respective variables in the IoT Cloud get changed. You can add code here to act upon changes in these variables.

************************************************************************************************************************

Bibliotheken und Objekte

ArduinoIoTCloud.h: Dies ist die Bibliothek, die zur Kommunikation mit der Arduino IoT Cloud benötigt wird.
Wire.h und MPU6050.h: Diese Bibliotheken sind erforderlich, um mit dem MPU6050 Sensor über den I2C-Bus zu kommunizieren.
MPU6050 mpu: Hier wird ein Objekt namens mpu vom Typ MPU6050 erstellt, das zur Kommunikation mit dem Sensor verwendet wird.
Globale Variablen
myLED und turbine: Diese sind Pin-Nummern für eine LED und einen Turbinensensor.
lastPunchTime: Speichert die letzte Zeit, zu der ein Schlag erkannt wurde.
PUNCH_DETECTION_INTERVAL: Das Zeitintervall (in Millisekunden), in dem ein Schlag erkannt werden kann. Hier auf 1 Sekunde (1000 ms) gesetzt.
PUNCH_THRESHOLD: Der Schwellenwert für die Beschleunigung, bei dem ein Schlag erkannt wird.


Setup-Funktion

Die serielle Kommunikation wird gestartet.
Die Pins werden konfiguriert.
Der MPU6050 Sensor wird initialisiert.
Es wird überprüft, ob eine Verbindung zum MPU6050 hergestellt werden kann.
Eine Verbindung zur Arduino IoT Cloud wird hergestellt und Debug-Informationen werden ausgegeben.
Loop-Funktion


Hier passiert die Hauptlogik des Programms:

Die IoT Cloud wird aktualisiert.
Der Wert des Turbinensensors wird gelesen.
Die Beschleunigungswerte des MPU6050 werden gelesen.
Die Beschleunigung wird berechnet und mit dem Schwellenwert verglichen.
Es wird überprüft, ob seit dem letzten erkannten Schlag genügend Zeit vergangen ist.
Wenn ein Schlag erkannt wird, werden die entsprechenden Variablen aktualisiert.


Feinabstimmungsparameter:

PUNCH_DETECTION_INTERVAL: Dieser Wert bestimmt, wie oft ein Schlag erkannt werden kann. Ein höherer Wert bedeutet, dass weniger Schläge pro Sekunde erkannt werden, ein niedrigerer Wert ermöglicht eine häufigere Erkennung.
PUNCH_THRESHOLD: Dieser Wert bestimmt die Mindestbeschleunigung, die als Schlag erkannt wird. Ein höherer Wert bedeutet, dass stärkere Schläge erforderlich sind, um erkannt zu werden, während ein niedrigerer Wert auch schwächere Schläge erkennt.
Durch das Justieren dieser beiden Werte kann das Verhalten des Programms in Bezug auf die Schlagdetektion abgestimmt werden.


Funktionen für IoT Cloud-Änderungen

Diese Funktionen werden aufgerufen, wenn die entsprechenden Variablen in der IoT Cloud geändert werden. Sie können hier Code hinzufügen, um auf Änderungen dieser Variablen zu reagieren.
