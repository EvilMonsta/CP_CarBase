#include "truck_show_display.h"
#include <iostream>

TruckShowDisplay::TruckShowDisplay() {}

void TruckShowDisplay::printData(int id) {
    Truck truck = truckManager.loadTruck(id);
        cout << "[Truck]" << endl;
        cout << "mark:" << truck.mark->name << endl;
        cout << "model: " << truck.model << endl;
        cout << "produce year: " << truck.produceDate << endl;
        cout << "type of transmission: " << truck.transmissonType << endl;
        cout << "engine capacity: " << truck.engineCapacity << endl;
        cout << "load capacity: " << truck.loadCapacity << endl;
        cout << "-------------------" << endl;
}


void TruckShowDisplay::PrintTrucksIds() {
    cout << "Motos:" << endl;
    truckManager.printFilenamesInFolder(truckManager.folderPath);
}
