#include "p_car_manager.h"
#include <sstream>
#include <iostream>

string PasCarManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string PasCarManager::createData(const PassengerCar& pCar) {
    string data = to_string(pCar.id) + "\n" + to_string(pCar.mark->id) + "\n" + pCar.mark->name + "\n" + pCar.model + "\n" + to_string(pCar.produceDate) + "\n" + pCar.transmissonType + "\n" + to_string(pCar.engineCapacity) + "\n" + to_string(pCar.numberOfSeats) + "\n";
    return data;
}


PassengerCar PasCarManager::convertData(const string& data){
    PassengerCar pCar;
    string line;
    int flag = 0;
    pCar.mark = new Mark;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    pCar.id = stoi(line);
                } else if(flag == 1) {
                    pCar.mark->id = stoi(line);
                } else if(flag == 2) {
                    pCar.mark->name = line;
                } else if(flag == 3) {
                    pCar.model = line;
                } else if(flag == 4) {
                    pCar.produceDate = stoi(line);
                } else if(flag == 5) {
                    pCar.transmissonType = line;
                } else if(flag == 6){
                    pCar.engineCapacity = stod(line);
                } else {
                    pCar.numberOfSeats = stoi(line);
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }

    return pCar;
}

void PasCarManager::savePasCar(const PassengerCar& pCar){
    string filepath = createFilepath(pCar.id);
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
