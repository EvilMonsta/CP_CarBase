#include "motorbike.h"
#include <iostream>

double Motorbike::getCylinderCapacity() const {
    return cylinderCapacity;
}

string Motorbike::getEngineType() const {
    return engineType;
}

void Motorbike::setEngineType(string newEngineType) {
    engineType = newEngineType;
}

void Motorbike::setCylinderCapacity(double newCylinderCapacity) {
    cylinderCapacity = newCylinderCapacity;
}
