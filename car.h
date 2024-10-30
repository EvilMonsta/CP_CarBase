#ifndef CAR_H
#define CAR_H
#include "vehicle.h"

class Car : public Vehicle {
public:
    string transmissonType;

    double engineCapacity;

    Car() : Vehicle() {};

    Car(int id, Mark* mark, const string& model, const string& generation, int produceDate, const string& transmissonType,
        double engineCapacity) : Vehicle(id, mark, model, generation, produceDate),
        transmissonType(transmissonType), engineCapacity(engineCapacity) {}

    ~Car() {};

};

#endif // CAR_H
