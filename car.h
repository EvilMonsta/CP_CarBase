#ifndef CAR_H
#define CAR_H
#include "vehicle.h"

class Car : public Vehicle {
public:
    string transmissionType;

    double engineCapacity;

    Car() : Vehicle() {};

    Car(int id, Mark* mark, const string& model, const string& generation, int produceDate, int factoryPrice,
        string img, int horsepower, string color, double fuelVolume, const string& transmissionType,
        double engineCapacity) : Vehicle(id, mark, model, generation, produceDate,factoryPrice,img,horsepower,color,fuelVolume),
        transmissionType(transmissionType), engineCapacity(engineCapacity) {}

    ~Car() {};

};

#endif // CAR_H
