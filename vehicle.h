#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Mark {
public:
    int id;

    string name;

    Mark() : id(0), name("def") {}

    Mark(int id, const string& name) : id(id),name(name) {}

    ~Mark() {};

};

class Vehicle {

public:
    int id;

    Mark* mark;

    string model;

    int produceDate;

    Vehicle() : id(0), mark(0), model("Default Model"), produceDate(0) {}

    Vehicle(int id, Mark* mark, const string& model, int produceDate): id(id),mark(mark),model(model),produceDate(produceDate) {}

    virtual ~Vehicle(){};

    virtual void printData() const = 0;
};

void saveMarkToFile(const Mark& mark, const string& filename);

void loadMarkFromFile(const Mark& mark, const string& filename);


#endif // VEHICLE_H
