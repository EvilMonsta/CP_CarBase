#include "moto_show_display.h"
#include <iostream>

MotoShowDisplay::MotoShowDisplay() {};


void MotoShowDisplay::printData(int id) {
    Motorbike bike = motoManager.loadMotorbike(id);
    cout << "[Motorbike]" << endl;
    cout << "mark: " << bike.mark->name << ' ' << bike.mark->id << endl;
    cout << "model: " << bike.model << endl;
    cout << "produce year: " << bike.produceDate << endl;
    cout << "engine type: " << bike.engineType << endl;
    cout << "cylinder capacity: " << bike.cylinderCapacity << endl;
    cout << "-------------------" << endl;
}


void MotoShowDisplay::PrintMotorbikesIds() {
    cout << "Motos:" << endl;
    motoManager.printFilenamesInFolder(motoManager.folderPath);
}
