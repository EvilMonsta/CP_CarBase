#ifndef CAR_H
#define CAR_H
#include "vehicle.h"

class Car : public Vehicle {
public:

    string transmissonType;

    double engineCapacity;

    Car() : Vehicle() {};

    Car(int id, Mark* mark, const string& model, int produceDate, const string& transmissonType,
        double engineCapacity) : Vehicle(id, mark, model, produceDate),
        transmissonType(transmissonType), engineCapacity(engineCapacity) {}

};

#endif // CAR_H
