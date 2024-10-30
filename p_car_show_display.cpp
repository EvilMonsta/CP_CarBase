#include "p_car_show_display.h"
#include <iostream>

PasCarShowDisplay::PasCarShowDisplay() {}

void PasCarShowDisplay::printData(int id) {
    PassengerCar pasCar = pasCarManager.loadPasCar(id);
        cout << "[PassengerCar]" << endl;
        cout << "mark:" << pasCar.getMark()->getName() << endl;
        cout << "model: " << pasCar.getModel() << ' ' << pasCar.getGenetation() << endl;
        cout << "produce year: " << pasCar.getProduceDate() << endl;
        cout << "type of transmission: " << pasCar.getTransmissionType() << endl;
        cout << "engine capacity: " << pasCar.getEngineCapacity() << endl;
        cout << "number of seats: " << pasCar.getNumberOfSeats() << endl;
        cout << "-------------------" << endl;
}


void PasCarShowDisplay::PrintPasCarsIds() {
    cout << "Motos:" << endl;
    pasCarManager.printFilenamesInFolder(pasCarManager.getFolderPath());
}
