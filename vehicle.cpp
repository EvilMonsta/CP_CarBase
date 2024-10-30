#include "vehicle.h"
#include<iostream>
#include<fstream>

int Vehicle::getId() const {
    return id;
}

Mark* Vehicle::getMark() const {
    return mark;
}

string Vehicle::getModel() const {
    return model;
}

string Vehicle::getGenetation() const {
    return generation;
}

int Vehicle::getProduceDate() const {
    return produceDate;
}

void Vehicle::setId(int newId) {
    id = newId;
}

void Vehicle::setMark(Mark* newMark) {
    mark = newMark;
}

void Vehicle::setModel(string newModel) {
    model = newModel;
}

void Vehicle::setGeneration(string newGeneration) {
    generation = newGeneration;
}

void Vehicle::setProduceDate(int newProduceDate) {
    produceDate = newProduceDate;
}
