#include "truck_manager.h"
#include <sstream>
#include <iostream>

TruckManager::TruckManager(QObject *parent) : FileManager(parent){};

string TruckManager::getFolderPath() const {
    return folderPath;
}

string TruckManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string TruckManager::createData(const Truck& tr) {
    string data = to_string(tr.id) + "\n" + to_string(tr.mark->id) + "\n" + tr.mark->name + "\n" + tr.model + "\n" + to_string(tr.produceDate) + "\n" + tr.transmissonType + "\n" + to_string(tr.engineCapacity) + "\n" + to_string(tr.loadCapacity) + "\n";
    return data;
}


Truck TruckManager::convertData(const string& data){
    Truck tr;
    string line;
    int flag = 0;
    tr.mark = new Mark;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    tr.id = stoi(line);
                } else if(flag == 1) {
                    tr.mark->id = stoi(line);
                } else if(flag == 2) {
                    tr.mark->name = line;
                } else if(flag == 3) {
                    tr.model = line;
                } else if(flag == 4) {
                    tr.produceDate = stoi(line);
                } else if(flag == 5) {
                    tr.transmissonType = line;
                } else if(flag == 6){
                    tr.engineCapacity = stod(line);
                } else {
                    tr.loadCapacity = stod(line);
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }

    return tr;
}

void TruckManager::saveTruck(const Truck& tr){
    string filepath = createFilepath(tr.id);
    string data = createData(tr);
    saveToFile(filepath, data);
}

Truck TruckManager::loadTruck(int id) {
    string filepath = createFilepath(id);
    string data = loadFromFile(filepath);
    return convertData(data);
}

void TruckManager::deleteTruck(int id) {
    string filepath = createFilepath(id);
    deleteFile(filepath);
}

void TruckManager::PrintTrucksIds(){
    cout << "Trucks:" << endl;
    printFilenamesInFolder(folderPath);
}
