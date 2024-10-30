#include "truck_manager.h"
#include <sstream>
#include <iostream>

TruckManager::TruckManager(QObject *parent) : QObject(parent){};

string TruckManager::getFolderPath() const {
    return folderPath;
}

string TruckManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string TruckManager::createData(const Truck& tr) {
    string data = to_string(tr.id) + "\n" + to_string(tr.mark->id) + "\n" + tr.model + "\n" + tr.generation + "\n" + to_string(tr.produceDate) + "\n" + tr.transmissionType + "\n" + to_string(tr.engineCapacity) + "\n" + to_string(tr.loadCapacity) + "\n";
    return data;
}


Truck TruckManager::convertData(const string& data){
    Truck tr;
    string line;
    int flag = 0;
    int markId;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    tr.id = stoi(line);
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    tr.model = line;
                } else if(flag == 3) {
                    tr.generation = line;
                } else if(flag == 4) {
                    tr.produceDate = stoi(line);
                } else if(flag == 5) {
                    tr.transmissionType = line;
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
    Mark mark = markManager.loadMarkFromFile(markId);
    tr.mark = &mark;
    return tr;
}

void TruckManager::saveTruck(const Truck& tr){
    string filepath = createFilepath(tr.id);
    fileManager.saveToFile<Truck>(tr, filepath, [this](const Truck& b) {
        return this->createData(b);
    });
}

Truck TruckManager::loadTruck(int id) {
    string filepath = createFilepath(id);
    return fileManager.loadFromFile<Truck>(filepath, [this](const string& data) {
        return this->convertData(data);
    });
}

void TruckManager::deleteTruck(int id) {
    string filepath = createFilepath(id);
    fileManager.deleteFile(filepath);
}

// void TruckManager::PrintTrucksIds(){
//     cout << "Trucks:" << endl;
//     printFilenamesInFolder(folderPath);
// }
