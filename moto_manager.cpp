#include "moto_manager.h"
#include <sstream>
#include <iostream>

MotoManager::MotoManager(QObject *parent) : FileManager(parent){};

string MotoManager::getFolderPath() const {
    return folderPath;
}

string MotoManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string MotoManager::createData(const Motorbike& bike) {
    string data = to_string(bike.getId()) + "\n" + to_string(bike.getMark()->getId()) + "\n" + bike.getModel() + "\n" + bike.getGenetation() + "\n" + to_string(bike.getProduceDate()) + "\n" + bike.getEngineType() + "\n" + to_string(bike.getCylinderCapacity()) + "\n";
    return data;
}

Motorbike MotoManager::convertData(const string& data){
    Motorbike bike;
    string line;
    int flag = 0;
    int markId;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    bike.setId(stoi(line));
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    bike.setModel(line);
                } else if(flag == 3) {
                    bike.setGeneration(line);
                } else if(flag == 4) {
                    bike.setProduceDate(stoi(line));
                } else if(flag == 5) {
                    bike.setEngineType(line);
                } else {
                    bike.setCylinderCapacity(stod(line));
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }
    Mark mark = markManager.loadMarkFromFile(markId);
    bike.setMark(&mark);
    return bike;
}


void MotoManager::saveMotorbike(const Motorbike& bike){
    string filepath = createFilepath(bike.getId());
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

