#ifndef CAR_H
#define CAR_H
#include "vehicle.h"

class Car : public Vehicle {
private:

    string transmissonType;

    double engineCapacity;

public:
    Car() : Vehicle() {};

    Car(int id, Mark* mark, const string& model, const string& generation, int produceDate, const string& transmissonType,
        double engineCapacity) : Vehicle(id, mark, model, generation, produceDate),
        transmissonType(transmissonType), engineCapacity(engineCapacity) {}

    ~Car() {};

    string getTransmissionType() const;

    double getEngineCapacity() const;

    void setTransmissionType(string newTransmissionType);

    void setEngineCapacity(double newEngineCapacity);

};

#endif // CAR_H
