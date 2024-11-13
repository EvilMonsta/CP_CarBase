#include "file_manager.h"
#include <iostream>
#include <filesystem>
#include <functional>
#include <set>
#include <regex>

FileManager::FileManager(QObject *parent) : QObject(parent) {};


int FileManager::idExtractor(const string& filePath) {
    filesystem::path path(filePath);
    string fileName = path.stem().string();

    try {
        return stoi(fileName);
    } catch (...) {
        return -1;
    }
}

void FileManager::deleteFile(const string& filepath) {
    if(filesystem::remove(filepath)) {
        cout << "file " << filepath << " removed" << endl;
    } else {
        cout << "unable to remove a file" << endl;
    }
};



vector<int> FileManager::readIdFromFilenames(const string& folderPath, function<int(const string&)> idExtractor){
    vector<int> ids;

    for(const auto& entry : filesystem::directory_iterator(folderPath)) {
        int id = idExtractor(entry.path().string());
        if (id != -1) {
            ids.push_back(id);
        }
    }

    return ids;
}

int FileManager::getNextAvailableId(const string& folderPath) {
    set<int> existingIds;
    regex idRegex(R"(^(\d+)\.txt$)");

    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            string fileName = entry.path().filename().string();
            smatch match;
            if (regex_match(fileName, match, idRegex)) {
                int id = stoi(match[1].str());
                existingIds.insert(id);
            }
        }
    }

    int newId = 1;
    while (existingIds.find(newId) != existingIds.end()) {
        ++newId;
    }

    return newId;
}
