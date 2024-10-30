#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include<vehicle.h>


class Motorbike : public Vehicle {
private:
    string engineType;

    double cylinderCapacity;

public:

    Motorbike() : Vehicle() {};

    Motorbike(int id, Mark* mark, const string& model, const string& generation, int produceDate, const string& engineType,
              double cylinderCapacity) : Vehicle(id, mark, model, generation, produceDate),
        engineType(engineType), cylinderCapacity(cylinderCapacity) {};

    ~Motorbike(){};

    string getEngineType() const;

    double getCylinderCapacity() const;

    void setEngineType(string newEngineType);

    void setCylinderCapacity(double newCylinderCapacity);

};

#endif // MOTORBIKE_H
