#include "car.h"
#include<iostream>

string Car::getTransmissionType() const {
    return transmissonType;
}

double Car:: getEngineCapacity() const {
    return engineCapacity;
}

void Car::setTransmissionType(string newTransmissionType) {
    transmissonType = newTransmissionType;
}

void Car::setEngineCapacity(double newEngineCapacity) {
    engineCapacity = newEngineCapacity;
}
