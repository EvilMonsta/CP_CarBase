#ifndef TRUCK_H
#define TRUCK_H
#include<car.h>


class Truck : public Car {
public:

    double loadCapacity;

    Truck() : Car() {};

    Truck(int id, Mark* mark, const string& model, const string& generation, int produceDate,
                 const string& transmissionType, double engineCapacity,
                 double loadCapacity) :
    Car(id, mark, model, generation, produceDate, transmissionType, engineCapacity),
        loadCapacity(loadCapacity) {}

    ~Truck(){};
};

#endif // TRUCK_H
