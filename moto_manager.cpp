#include "moto_manager.h"
#include <sstream>
#include <iostream>

MotoManager::MotoManager(QObject *parent) : fileManager(parent){};


string MotoManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string MotoManager::createData(const Motorbike& bike) {
    string data = to_string(bike.id) + "\n" + to_string(bike.mark->id) + "\n" + bike.mark->name + "\n" + bike.model + "\n" + to_string(bike.produceDate) + "\n" + bike.engineType + "\n" + to_string(bike.cylinderCapacity) + "\n";
    return data;
}

Motorbike MotoManager::convertData(const string& data){
    Motorbike bike;
    string line;
    int flag = 0;
    bike.mark = new Mark;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    bike.id = stoi(line);
                } else if(flag == 1) {
                    bike.mark->id = stoi(line);
                } else if(flag == 2) {
                    bike.mark->name = line;
                } else if(flag == 3) {
                        bike.model = line;
                } else if(flag == 4) {
                    bike.produceDate = stoi(line);
                } else if(flag == 5) {
                    bike.engineType = line;
                } else {
                    bike.cylinderCapacity = stod(line);
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }

    return bike;
}


void MotoManager::saveMotorbike(const Motorbike& bike){
    string filepath = createFilepath(bike.id);
    string data = createData(bike);
    saveToFile(filepath, data);
}

Motorbike MotoManager::loadMotorbike(int id) {
    string filepath = createFilepath(id);
    string data = loadFromFile(filepath);
    return convertData(data);
}

void MotoManager::deleteMotorbike(int id) {
    string filepath = createFilepath(id);
    deleteFile(filepath);
}

