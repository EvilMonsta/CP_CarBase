#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <mark.h>
#include <model.h>
using namespace std;

class Vehicle {

public:

    int id;

    Mark* mark;

    Model* model;

    string generation;

    int produceDate;

    int factoryPrice;

    string img;

    int horsepower;

    string color;

    double fuelVolume;

    Vehicle() : id(0), mark(0), model(0), generation("def"), produceDate(0), factoryPrice(0), img("def"),horsepower(0),color("def"), fuelVolume(0) {}

    Vehicle(int id, Mark* mark, Model* model, const string& generation, int produceDate, int factoryPrice,
            string img, int horsepower, string color, double fuelVolume): id(id),mark(mark),model(model),generation(generation),produceDate(produceDate),factoryPrice(factoryPrice),img(img),horsepower(horsepower),color(color),fuelVolume(fuelVolume) {}

    virtual ~Vehicle(){};

};



#endif // VEHICLE_H
