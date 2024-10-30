#include "p_car_manager.h"
#include <sstream>
#include <iostream>

PasCarManager::PasCarManager(QObject *parent) : FileManager(parent){};

string PasCarManager::getFolderPath() const {
    return folderPath;
}

string PasCarManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string PasCarManager::createData(const PassengerCar& pCar) {
    string data = to_string(pCar.getId()) + "\n" + to_string(pCar.getMark()->getId()) + "\n" + pCar.getModel()+ "\n" + pCar.getGenetation() + "\n" + to_string(pCar.getProduceDate()) + "\n" + pCar.getTransmissionType() + "\n" + to_string(pCar.getEngineCapacity()) + "\n" + to_string(pCar.getNumberOfSeats()) + "\n";
    return data;
}


PassengerCar PasCarManager::convertData(const string& data){
    PassengerCar pasCar;
    string line;
    int flag = 0;
    int markId;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    pasCar.setId(stoi(line));
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    pasCar.setModel(line);
                } else if(flag == 3) {
                    pasCar.setGeneration(line);
                } else if(flag == 4) {
                    pasCar.setProduceDate(stoi(line));
                } else if(flag == 5) {
                    pasCar.setTransmissionType(line);
                } else if(flag == 6){
                    pasCar.setEngineCapacity(stod(line));
                } else {
                    pasCar.setNumberOfSeats(stod(line));
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }
    Mark mark = markManager.loadMarkFromFile(markId);
    pasCar.setMark(&mark);
    return pasCar;
}

void PasCarManager::savePasCar(const PassengerCar& pCar){
    string filepath = createFilepath(pCar.getId());
    string data = createData(pCar);
    saveToFile(filepath, data);
}

PassengerCar PasCarManager::loadPasCar(int id) {
    string filepath = createFilepath(id);
    string data = loadFromFile(filepath);
    return convertData(data);
}

void PasCarManager::deletePasCar(int id) {
    string filepath = createFilepath(id);
    deleteFile(filepath);
}

void PasCarManager::PrintPasCarIds(){
    cout << "PasCars:" << endl;
    printFilenamesInFolder(folderPath);
}
