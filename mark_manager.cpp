#include "mark_manager.h"
#include <filesystem>
#include <fstream>

MarkManager::MarkManager(QObject *parent) : QObject(parent){};

vector<int> MarkManager::extractIds(const std::string& input) {
    std::vector<int> ids;
    std::istringstream stream(input);
    int id;

    while (stream >> id) {
        ids.push_back(id);
    }

    return ids;
}

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

vector<int> MarkManager::readIds(const string& folderPath) {
    vector<int> ids = fileManager.readIdFromFilenames(folderPath, [&](const string& filePath) { return fileManager.idExtractor(filePath); });
    return ids;
}
