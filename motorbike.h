#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include<vehicle.h>


class Motorbike : public Vehicle {
public:

    string engineType;

    double cylinderCapacity;

    Motorbike() : Vehicle() {};

    Motorbike(int id, Mark* mark, const string& model, const string& generation, int produceDate, const string& engineType,
              double cylinderCapacity) : Vehicle(id, mark, model, generation, produceDate),
        engineType(engineType), cylinderCapacity(cylinderCapacity) {};

    ~Motorbike(){};

};

#endif // MOTORBIKE_H
