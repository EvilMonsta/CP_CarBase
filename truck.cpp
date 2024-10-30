#include "truck.h"
#include<iostream>
using namespace std;

double Truck::getLoadCapacity() const {
    return loadCapacity;
}

void Truck::setLoadCapacity(double newLoadCapacity) {
    loadCapacity = newLoadCapacity;
}
