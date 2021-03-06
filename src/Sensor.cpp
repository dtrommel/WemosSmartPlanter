//
// Created by Daan Trommel on 20/04/2022.
//

#include "Sensor.h"

Sensor::Sensor(Multiplexer* multiplexer, int pin, int minValue, int maxValue) {
    _multiplexer = multiplexer;
    sensorPin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin,OUTPUT);
    digitalWrite(pin,LOW);
}

int Sensor::getPercentageValue() {
    int percentage = map(readSensor(),maxValue,minValue,100,0);
    return percentage;
}

int Sensor::getSensorValue() {
    return readSensor();
}

int Sensor::readSensor() {
    return _multiplexer->ReadValue(sensorPin);
}

void Sensor::setMinValue(int minValue) {
    minValue = minValue;
}

void Sensor::setMaxValue(int maxValue) {
    maxValue = maxValue;
}