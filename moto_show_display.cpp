#include "moto_show_display.h"
#include <iostream>

MotoShowDisplay::MotoShowDisplay() {};


void MotoShowDisplay::printData(int id) {
    Motorbike bike = motoManager.loadMotorbike(id);
    cout << "[Motorbike]" << endl;
    cout << "mark: " << bike.getMark()->getName() << ' ' << bike.getMark()->getId()<< endl;
    cout << "model: " << bike.getModel() << ' ' << bike.getGenetation() << endl;
    cout << "produce year: " << bike.getProduceDate() << endl;
    cout << "engine type: " << bike.getEngineType() << endl;
    cout << "cylinder capacity: " << bike.getCylinderCapacity() << endl;
    cout << "-------------------" << endl;
}


void MotoShowDisplay::PrintMotorbikesIds() {
    cout << "Motos:" << endl;
    motoManager.printFilenamesInFolder(motoManager.folderPath);
}
