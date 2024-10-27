#include "p_car_show_display.h"
#include <iostream>

PasCarShowDisplay::PasCarShowDisplay() {}

void PasCarShowDisplay::printData(int id) {
    PassengerCar pasCar = pasCarManager.loadPasCar(id);
        cout << "[PassengerCar]" << endl;
        cout << "mark:" << pasCar.mark->name << endl;
        cout << "model: " << pasCar.model << endl;
        cout << "produce year: " << pasCar.produceDate << endl;
        cout << "type of transmission: " << pasCar.transmissonType << endl;
        cout << "engine capacity: " << pasCar.engineCapacity << endl;
        cout << "number of seats: " << pasCar.numberOfSeats << endl;
        cout << "-------------------" << endl;
}


void PasCarShowDisplay::PrintPasCarsIds() {
    cout << "Motos:" << endl;
    pasCarManager.printFilenamesInFolder(pasCarManager.folderPath);
}
