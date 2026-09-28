#include "TamperSensor.h"

TamperSensor::TamperSensor(
    int tamperPin,
    int buzzerPin,
    int ledPin
)
{
    this->tamperPin = tamperPin;
    this->buzzerPin = buzzerPin;
    this->ledPin = ledPin;

    tamperDetected = false;
}


void TamperSensor::begin()
{
    pinMode(tamperPin, INPUT_PULLUP);

    pinMode(buzzerPin, OUTPUT);

    pinMode(ledPin, OUTPUT);

    digitalWrite(buzzerPin, LOW);

    digitalWrite(ledPin, LOW);

    Serial.println();
    Serial.println("==============================");
    Serial.println("      ANTI-TAMPER SYSTEM");
    Serial.println("==============================");


    if (digitalRead(tamperPin) == HIGH)
    {
        tamperDetected = true;

        Serial.println("WARNING!");
        Serial.println("Seal is already broken!");

        digitalWrite(ledPin, HIGH);
    }
    else
    {
        Serial.println("Seal Status: SECURE");
    }
}


void TamperSensor::check()
{
    // If tampering has already occurred,
    // keep the box in TAMPERED state.

    if (tamperDetected)
    {
        digitalWrite(ledPin, HIGH);

        Serial.println("STATUS: TAMPERED");

        digitalWrite(buzzerPin, HIGH);

        delay(300);

        digitalWrite(buzzerPin, LOW);

        delay(700);

        return;
    }


    // Read the tamper seal

    int sealState = digitalRead(tamperPin);


    if (sealState == HIGH)
    {
        tamperDetected = true;

        Serial.println();
        Serial.println("==============================");
        Serial.println("     !!! TAMPER DETECTED !!!");
        Serial.println("==============================");

        Serial.println("Holographic seal has been broken.");

        Serial.println("Box security compromised.");


        digitalWrite(ledPin, HIGH);


        // Sound alarm

        digitalWrite(buzzerPin, HIGH);

        delay(3000);

        digitalWrite(buzzerPin, LOW);
    }

    else
    {
        digitalWrite(ledPin, LOW);

        Serial.println("STATUS: SECURE");

        delay(2000);
    }
}


bool TamperSensor::isTampered()
{
    return tamperDetected;
}


void TamperSensor::reset()
{
    tamperDetected = false;

    digitalWrite(buzzerPin, LOW);

    digitalWrite(ledPin, LOW);

    Serial.println("Tamper status reset.");
}