#include <Arduino.h>

int analogPin = A0;
int digitalPin = 2;
int greenLight = 3;
int redLight = 4;

void setup() {
    pinMode(analogPin, INPUT);
    pinMode(digitalPin, INPUT);
    pinMode(greenLight, OUTPUT);
    pinMode(redLight, OUTPUT);

    Serial.begin(115200);
}

void loop() {
    int thresholdValue = 200;

    int sensorValue = analogRead(analogPin);
    Serial.print(sensorValue);

    if(sensorValue < thresholdValue){
        Serial.println(" - Doesn't need watering");
        digitalWrite(redLight, LOW);
        digitalWrite(greenLight, HIGH);
    }
   else {
        Serial.println(" - Time to water your plant");
        digitalWrite(redLight, HIGH);
        digitalWrite(greenLight, LOW);
  }
  delay(500);
}
