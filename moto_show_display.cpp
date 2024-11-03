#include "moto_show_display.h"
#include <iostream>

MotoShowDisplay::MotoShowDisplay() {};

void MotoShowDisplay::printIds(vector<int> ids){
    for (size_t i = 0; i < ids.size(); ++i) {
        cout << ids[i];
        if (i != ids.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void MotoShowDisplay::printData(int id) {
    Motorbike bike = motoManager.loadMotorbike(id);
    cout << "[Motorbike]" << endl;
    cout << "mark: " << bike.mark->name << endl;
    cout << "model: " << bike.model << ' ' << bike.generation << endl;
    cout << "produce year: " << bike.produceDate << endl;
    cout << "engine type: " << bike.engineType << endl;
    cout << "cylinder capacity: " << bike.cylinderCapacity << endl;
    cout << "-------------------" << endl;
}


void MotoShowDisplay::PrintMotorbikesIds() {
    cout << "Motorbikes ID's:" << endl;
    vector<int> ids = motoManager.readIds(motoManager.getFolderPath());
    printIds(ids);
}
