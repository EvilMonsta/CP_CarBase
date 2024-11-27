#include "model_manager.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include<QMessageBox>

ModelManager::ModelManager(QObject *parent) : QObject(parent){};

vector<int> ModelManager::extractIds(const string& input) {
    vector<int> ids;
    istringstream stream(input);
    int id;

    while (stream >> id) {
        ids.push_back(id);
    }

    return ids;
}

string ModelManager::getFolderPath() const {
    return folderPath;
}

string ModelManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string ModelManager::createData(const Model& model) {
    string data = to_string(model.id) + "\n" + model.name + "\n";
    return data;
}
Model ModelManager::convertData(const string& data){
    Model model;
    string line;
    int flag = 0;
    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    model.id = stoi(line);
                } else if(flag == 1) {
                    model.name = line;
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }
    return model;
}
Model ModelManager::loadModel(int id) {
    string filepath = createFilepath(id);
    return fileManager.loadFromFile<Model>(filepath, [this](const string& data) {
        return this->convertData(data);
    });
}

vector<Model> ModelManager::getModels(vector<int> modIds){
    vector<Model> models;
    for (const auto &entry : filesystem::directory_iterator(folderPath)) {
        string filename = entry.path().filename().string();
        int id = stoi(filename.substr(0, filename.find('.')));
        if(find(modIds.begin(),modIds.end(), id) != modIds.end()) {
            Model model = loadModel(id);
            models.push_back(model);
        }
    }
    return models;
}

void ModelManager::saveModel(const Model& model){
    string filepath = createFilepath(model.id);
    fileManager.saveToFile<Model>(model, filepath, [this](const Model& b) {
        return this->createData(b);
    });
}

vector<int> ModelManager::readIds(const string& folderPath) {
    vector<int> ids = fileManager.readIdFromFilenames(folderPath, [&](const string& filePath) { return fileManager.idExtractor(filePath); });
    return ids;
}


bool ModelManager::isModelNameUnique(const string& name, int markId) {
    markContainerManager.loadIdsFromFile();
    vector<int> checkingObjectsIds = markContainerManager.getModelsIdsByMark(markId);

    for (int id : checkingObjectsIds) {
        Model md = loadModel(id);
        qDebug() << md.name;
        if (md.name == name) {
            return false;
        }
    }
    return true;
}

Model ModelManager::addModel(const string& newModelName, int markId) {
    try {
        if (!isModelNameUnique(newModelName, markId)) {
            throw DuplicateModelException("Модель с таким именем уже существует: " + newModelName);
        }

        int id = fileManager.getNextAvailableId(folderPath);

        Model newModel(id, newModelName);

        return newModel;

    } catch (const DuplicateModelException& e) {
        QMessageBox::warning(nullptr, "Ошибка", QString::fromStdString(e.getMessage()));
        throw;
    }

}
