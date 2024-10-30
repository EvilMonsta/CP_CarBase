#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <mark.h>

using namespace std;

class Vehicle {

public:

    int id;

    Mark* mark;

    string model;

    string generation;

    int produceDate;

    Vehicle() : id(0), mark(0), model("Default Model"), generation("def"), produceDate(0) {}

    Vehicle(int id, Mark* mark, const string& model, const string& generation, int produceDate): id(id),mark(mark),model(model),generation(generation),produceDate(produceDate) {}

    virtual ~Vehicle(){};

};



#endif // VEHICLE_H
