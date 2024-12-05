#include "mark_manager.h"
#include <filesystem>
#include <fstream>
#include <string>
#include<QMessageBox>
MarkManager::MarkManager(QObject *parent) : QObject(parent){};

string MarkManager::getFolderPath() const {
    return folderPath;
}

string MarkManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

string MarkManager::createData(const Mark& mark) {
    string data = to_string(mark.id) + "\n" + mark.name + "\n";
    return data;
}

Mark MarkManager::convertData(const string& data){
    Mark mark;
    string line;
    int flag = 0;
    for(char ch : data) {
        if(ch == '\n') {
            if (!line.empty()) {
                if(flag == 0) {
                    mark.id = stoi(line);
                } else if(flag == 1) {
                    mark.name = line;
                }
                line.clear();
                flag++;
            }
        } else {
            line += ch;
        }
    }
    return mark;
}

Mark MarkManager::loadMark(int id) {
    string filepath = createFilepath(id);
    return fileManager.loadFromFile<Mark>(filepath, [this](const string& data) {
        return this->convertData(data);
    });
}

vector<Mark> MarkManager::getMarks(){
    vector<Mark> marks;
    for (const auto &entry : filesystem::directory_iterator(folderPath)) {
        string filename = entry.path().filename().string();
        int id = stoi(filename.substr(0, filename.find('.')));
        Mark mark = loadMark(id);
        marks.push_back(mark);
    }
    return marks;
}

void MarkManager::saveMark(const Mark& mark){
    string filepath = createFilepath(mark.id);
    fileManager.saveToFile<Mark>(mark, filepath, [this](const Mark& b) {
        return this->createData(b);
    });
}

vector<int> MarkManager::readIds() {
    vector<int> ids = fileManager.readIdFromFilenames(folderPath, [&](const string& filePath) { return fileManager.idExtractor(filePath); });
    return ids;
}

bool MarkManager::isMarkNameUnique(const string& name) {

    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path());
            if (file.is_open()) {
                string id;
                string markName;
                getline(file,id);
                getline(file,markName);

                file.close();

                if (markName == name) {
                    return false;
                }
            }
        }
    }

    return true;
}

Mark MarkManager::addMark(const string& newMarkName) {
    try {
        if (!isMarkNameUnique(newMarkName)) {
            throw DuplicateMarkException("Марка с таким именем уже существует: " + newMarkName);
        }

        int id = fileManager.getNextAvailableId(folderPath);

        Mark newMark(id, newMarkName);

        return newMark;

    } catch (const DuplicateMarkException& e) {
        QMessageBox::warning(nullptr, "Ошибка", QString::fromStdString(e.getMessage()));
        throw;
    }

}
