#ifndef TRUCK_H
#define TRUCK_H
#include<car.h>


class Truck : public Car {
public:

    double loadCapacity;

    Truck() : Car() {};

    Truck(int id, Mark* mark, const string& model, int produceDate,
                 const string& transmissionType, double engineCapacity,
                 double loadCapacity) :
    Car(id, mark, model, produceDate, transmissionType, engineCapacity),
        loadCapacity(loadCapacity) {}

    ~Truck(){};

    void printData() const override;

};

#endif // TRUCK_H
