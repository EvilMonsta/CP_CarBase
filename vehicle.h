#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <mark.h>

using namespace std;

class Vehicle {
private:

    int id;

    Mark* mark;

    string model;

    string generation;

    int produceDate;
public:

    Vehicle() : id(0), mark(0), model("Default Model"), generation("def"), produceDate(0) {}

    Vehicle(int id, Mark* mark, const string& model, const string& generation, int produceDate): id(id),mark(mark),model(model),generation(generation),produceDate(produceDate) {}

    virtual ~Vehicle(){};

    int getId() const;

    Mark* getMark() const;

    string getModel() const;

    string getGenetation() const;

    int getProduceDate() const;

    void setId(int newId);

    void setMark(Mark* newMark);

    void setModel(string newModel);

    void setGeneration(string newGeneration);

    void setProduceDate(int newProduceDate);

};



#endif // VEHICLE_H
