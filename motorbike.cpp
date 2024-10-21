#include "motorbike.h"
#include <iostream>


void Motorbike::printData() const {
    cout << "[Motorbike]" << endl;
    cout << "mark: " << mark->name << ' ' << mark->id << endl;
    cout << "model: " << model << endl;
    cout << "produce year: " <<produceDate << endl;
    cout << "engine type: " << engineType << endl;
    cout << "cylinder capacity: " << cylinderCapacity << endl;
    cout << "-------------------" << endl;
}

// Motorbike Motorbike::loadFromFile(const string& filename, int id) {

// }
