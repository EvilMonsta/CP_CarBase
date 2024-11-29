#include "p_car_manager.h"

PasCarManager::PasCarManager(QObject *parent) : QObject(parent){};

string PasCarManager::getFolderPath() const {
    return folderPath;
}

string PasCarManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string PasCarManager::createData(const PassengerCar& pCar) {
    string data = to_string(pCar.id) + "\n" + to_string(pCar.mark->id) + "\n" + to_string(pCar.model->id) + "\n" + pCar.generation + "\n"
                  + to_string(pCar.produceDate) + "\n" + to_string(pCar.factoryPrice) + "\n"
                  + pCar.img + "\n" + to_string(pCar.horsepower) + "\n" + pCar.color + "\n" + to_string(pCar.fuelVolume) + "\n"
                  + pCar.transmissionType + "\n" + to_string(pCar.engineCapacity) + "\n" + to_string(pCar.numberOfSeats) + "\n";
    return data;
}


PassengerCar PasCarManager::convertData(const string& data){
    PassengerCar pasCar;
    string line;
    int flag = 0;
    int markId;
    int modelId;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    pasCar.id = stoi(line);
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    modelId = stoi(line);
                } else if(flag == 3) {
                    pasCar.generation = line;
                } else if(flag == 4) {
                    pasCar.produceDate = stoi(line);
                } else if(flag == 5) {
                    pasCar.factoryPrice = stoi(line);
                } else if(flag == 6) {
                    pasCar.img = line;
                } else if(flag == 7) {
                    pasCar.horsepower = stoi(line);
                } else if(flag == 8) {
                    pasCar.color = line;
                } else if(flag == 9) {
                    pasCar.fuelVolume = stod(line);
                } else if(flag == 10) {
                    pasCar.transmissionType = line;
                } else if(flag == 11){
                    pasCar.engineCapacity = stod(line);
                } else {
                    pasCar.numberOfSeats = stoi(line);
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
    pasCar.mark = &mark;
    pasCar.model = &model;
    return pasCar;
}

void PasCarManager::savePasCar(const PassengerCar& pCar){
    string filepath = createFilepath(pCar.id);
    fileManager.saveToFile<PassengerCar>(pCar, filepath, [this](const PassengerCar& b) {
        return this->createData(b);
    });
}

PassengerCar PasCarManager::loadPasCar(int id) {
    string filepath = createFilepath(id);
    return fileManager.loadFromFile<PassengerCar>(filepath, [this](const string& data) {
        return this->convertData(data);
    });
}

void PasCarManager::deletePasCar(int id) {
    string filepath = createFilepath(id);
    fileManager.deleteFile(filepath);
}

vector<int> PasCarManager::readIds(const string& folderPath) {
    vector<int> ids = fileManager.readIdFromFilenames(folderPath, [&](const string& filePath) {
        return fileManager.idExtractor(filePath);
    });
    return ids;
}

int PasCarManager::getNextPassengerCarId() {
    return fileManager.getNextAvailableId(folderPath);
}
