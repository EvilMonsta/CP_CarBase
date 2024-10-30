#include "mark_manager.h"
#include <filesystem>
#include <fstream>

MarkManager::MarkManager(QObject *parent) : QObject(parent){};

string MarkManager::createFilepath(int id) {
    string filepath = folderPath + "/" + to_string(id) + ".txt";
    return filepath;
}

vector<Mark> MarkManager::getMarks() const {
    vector<Mark> marks;
    for (const auto &entry : filesystem::directory_iterator(folderPath)) {
        ifstream file(entry.path());
        if (file.is_open()) {
            string name;
            string id;
            getline(file,id);
            getline(file, name);

            marks.emplace_back(stoi(id), name);
        }
    }
    return marks;
}

bool MarkManager::markExists(int id) const {
    string markFile = folderPath + "/" + to_string(id) + ".txt";
    return filesystem::exists(markFile);
}

void MarkManager::saveMarkToFile(Mark mark) const {
    string filePath = folderPath + "/" + to_string(mark.id) + ".txt";
    ofstream file(filePath);
    if (file.is_open()) {
        file << mark.id << "\n" << mark.name;
        file.close();
    }
}

Mark MarkManager::loadMarkFromFile(int id) {
    string filePath = createFilepath(id);
    ifstream file(filePath);
    int markId = 0;
    string markName = "";
    if (file.is_open()) {
        file >> markId >> markName;
        file.close();
    }
    return Mark(markId,markName);
}

