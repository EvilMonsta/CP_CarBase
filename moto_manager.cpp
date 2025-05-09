#include "moto_manager.h"
MotoManager::MotoManager(QObject *parent) : QObject(parent){};

string MotoManager::getFolderPath() const {
    return folderPath;
}

string MotoManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string MotoManager::createData(const Motorbike& bike) {
    string data = to_string(bike.id) + "\n" + to_string(bike.mark->id) + "\n" + to_string(bike.model->id) + "\n"
                  + bike.generation + "\n" + to_string(bike.produceDate) + "\n" + to_string(bike.factoryPrice) + "\n"
                  + bike.img + "\n" + to_string(bike.horsepower) + "\n" + bike.color + "\n" + to_string(bike.fuelVolume) + "\n" + bike.engineType + "\n"
                  + to_string(bike.cylinderCapacity) + "\n";
    return data;
}

Motorbike MotoManager::convertData(const string& data){
    Motorbike bike;
    string line;
    int flag = 0;
    int markId;
    int modelId;

    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    bike.id = stoi(line);
                } else if(flag == 1) {
                    markId = stoi(line);
                } else if(flag == 2) {
                    modelId = stoi(line);
                } else if(flag == 3) {
                    bike.generation =line;
                } else if(flag == 4) {
                    bike.produceDate = stoi(line);
                } else if(flag == 5) {
                    bike.factoryPrice = stoi(line);
                } else if(flag == 6) {
                    bike.img = line;
                } else if(flag == 7) {
                    bike.horsepower = stoi(line);
                } else if(flag == 8) {
                    bike.color = line;
                } else if(flag == 9) {
                    bike.fuelVolume = stod(line);
                } else if(flag == 10) {
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
    Model model = modelManager.loadModel(modelId);
    Mark mark = markManager.loadMark(markId);
    bike.mark = new Mark(mark);
    bike.model = new Model(model);
    return bike;
}


void MotoManager::saveMotorbike(const Motorbike& bike){
    string filepath = createFilepath(bike.id);
    fileManager.saveToFile<Motorbike>(bike, filepath, [this](const Motorbike& b) {
              return this->createData(b);
    });
}

Motorbike MotoManager::loadMotorbike(int id) {
    string filepath = createFilepath(id);
    return fileManager.loadFromFile<Motorbike>(filepath, [this](const string& data) {
        return this->convertData(data);
    });
}

void MotoManager::deleteMotorbike(int id) {
    string filepath = createFilepath(id);
    fileManager.deleteFile(filepath);
}

vector<int> MotoManager::readIds(const string& folderPath) {
    vector<int> ids = fileManager.readIdFromFilenames(folderPath, [&](const string& filePath) {
        return fileManager.idExtractor(filePath);
    });
    return ids;
}

int MotoManager::getNextMotoId() {
    return fileManager.getNextAvailableId(folderPath);
}
