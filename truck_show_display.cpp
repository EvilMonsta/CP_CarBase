#include "truck_show_display.h"
#include <iostream>

TruckShowDisplay::TruckShowDisplay() {}

void TruckShowDisplay::printIds(vector<int> ids){
    for (size_t i = 0; i < ids.size(); ++i) {
        cout << ids[i];
        if (i != ids.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void TruckShowDisplay::printData(int id) {
    Truck truck = truckManager.loadTruck(id);
        cout << "[Truck]" << endl;
        cout << "mark:" << truck.mark->name << endl;
        cout << "model: " << truck.model << ' ' << truck.generation << endl;
        cout << "produce year: " << truck.produceDate << endl;
        cout << "type of transmission: " << truck.transmissionType << endl;
        cout << "engine capacity: " << truck.engineCapacity << endl;
        cout << "load capacity: " << truck.loadCapacity << endl;
        cout << "-------------------" << endl;
}

void TruckShowDisplay::PrintTrucksIds() {
    cout << "Trucks ID's:" << endl;
    vector<int> ids = truckManager.readIds(truckManager.getFolderPath());
    printIds(ids);
}
