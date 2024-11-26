#include "truck_manager.h"

TruckManager::TruckManager(QObject *parent) : QObject(parent){};

string TruckManager::getFolderPath() const {
    return folderPath;
}

string TruckManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string TruckManager::createData(const Truck& tr) {
    string data = to_string(tr.id) + "\n" + to_string(tr.mark->id) + "\n" + to_string(tr.model->id) + "\n" + tr.generation + "\n" + to_string(tr.produceDate) + "\n"
                  + to_string(tr.factoryPrice) + "\n" + tr.img + "\n" + to_string(tr.horsepower) + "\n" + tr.color + "\n"
                  + to_string(tr.fuelVolume) + "\n" + tr.transmissionType + "\n" + to_string(tr.engineCapacity) + "\n" + to_string(tr.loadCapacity) + "\n";
    return data;
}

Truck TruckManager::convertData(const string& data){
    Truck tr;
    string line;
    int flag = 0;
    int markId;
    int modelId;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    tr.id = stoi(line);
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    modelId = stoi(line);
                } else if(flag == 3) {
                    tr.generation = line;
                } else if(flag == 4) {
                    tr.produceDate = stoi(line);
                } else if(flag == 5) {
                    tr.factoryPrice = stoi(line);
                } else if(flag == 6) {
                    tr.img = line;
                } else if(flag == 7) {
                    tr.horsepower = stoi(line);
                } else if(flag == 8) {
                    tr.color = line;
                } else if(flag == 9) {
                    tr.fuelVolume = stod(line);
                } else if(flag == 10) {
                    tr.transmissionType = line;
                } else if(flag == 11){
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

    Model model = modelManager.loadModel(modelId);
    Mark mark = markManager.loadMark(markId);
    tr.mark = &mark;
    tr.model = &model;
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

vector<int> TruckManager::readIds(const string& folderPath) {
    vector<int> ids = fileManager.readIdFromFilenames(folderPath, [&](const string& filePath) {
        return fileManager.idExtractor(filePath);
    });
    return ids;
}

int TruckManager::getNextTruckId() {
    return fileManager.getNextAvailableId(folderPath);
}
