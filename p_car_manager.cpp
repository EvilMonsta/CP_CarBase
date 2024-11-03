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
    string data = to_string(pCar.id) + "\n" + to_string(pCar.mark->id) + "\n" + pCar.model+ "\n" + pCar.generation + "\n" + to_string(pCar.produceDate) + "\n" + pCar.transmissionType + "\n" + to_string(pCar.engineCapacity) + "\n" + to_string(pCar.numberOfSeats) + "\n";
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
                    pasCar.id = stoi(line);
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    pasCar.model = line;
                } else if(flag == 3) {
                    pasCar.generation = line;
                } else if(flag == 4) {
                    pasCar.produceDate = stoi(line);
                } else if(flag == 5) {
                    pasCar.transmissionType = line;
                } else if(flag == 6){
                    pasCar.engineCapacity = stod(line);
                } else {
                    pasCar.numberOfSeats = stod(line);
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }
    Mark mark = markManager.loadMarkFromFile(markId);
    pasCar.mark = &mark;
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
