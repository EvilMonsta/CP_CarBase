#ifndef TRANSPORT_LOADER_H
#define TRANSPORT_LOADER_H
#include <QPushButton>
#include "motorbike.h"
#include "passenger_car.h"
#include "truck.h"

class TransportLoader {
public:
    static void loadMotorbikeData(const Motorbike &bike, QPushButton *button);
    static void loadPassengerCarData(const PassengerCar &pCar, QPushButton *button);
    static void loadTruckData(const Truck &truck, QPushButton *button);
};
#endif // TRANSPORT_LOADER_H
