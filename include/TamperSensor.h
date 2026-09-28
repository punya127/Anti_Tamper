#ifndef TAMPER_SENSOR_H
#define TAMPER_SENSOR_H

#include <Arduino.h>

class TamperSensor
{
private:
    int tamperPin;
    int buzzerPin;
    int ledPin;

    bool tamperDetected;

public:
    TamperSensor(
        int tamperPin,
        int buzzerPin,
        int ledPin
    );

    void begin();
    void check();

    bool isTampered();

    void reset();
};

#endif