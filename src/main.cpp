#include <Arduino.h>
#include "TamperSensor.h"


// Pin configuration

#define TAMPER_PIN 27
#define BUZZER_PIN 25
#define LED_PIN 26


// Create tamper sensor object

TamperSensor tamperSensor(
    TAMPER_PIN,
    BUZZER_PIN,
    LED_PIN
);


void setup()
{
    Serial.begin(115200);

    delay(1000);

    tamperSensor.begin();
}


void loop()
{
    tamperSensor.check();
}