#include "p_car_show_display.h"
#include <iostream>

PasCarShowDisplay::PasCarShowDisplay() {}

void PasCarShowDisplay::printData(int id) {
    PassengerCar pasCar = pasCarManager.loadPasCar(id);
        cout << "[PassengerCar]" << endl;
        cout << "mark:" << pasCar.mark->name << endl;
        cout << "model: " << pasCar.model << ' ' << pasCar.generation << endl;
        cout << "produce year: " << pasCar.produceDate << endl;
        cout << "type of transmission: " << pasCar.transmissionType << endl;
        cout << "engine capacity: " << pasCar.engineCapacity << endl;
        cout << "number of seats: " << pasCar.numberOfSeats << endl;
        cout << "-------------------" << endl;
}


void PasCarShowDisplay::printIds(vector<int> ids){
    for (size_t i = 0; i < ids.size(); ++i) {
        cout << ids[i];
        if (i != ids.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}


void PasCarShowDisplay::PrintPassengerCarsIds() {
    cout << "Passenger cars ID's:" << endl;
    vector<int> ids = pasCarManager.readIds(pasCarManager.getFolderPath());
    printIds(ids);
}
