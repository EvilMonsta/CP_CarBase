#include "passenger_car.h"
#include<iostream>


int PassengerCar::getNumberOfSeats() const {
    return numberOfSeats;
}

void PassengerCar::setNumberOfSeats(int newNumberOfSeats) {
    numberOfSeats = newNumberOfSeats;
}
