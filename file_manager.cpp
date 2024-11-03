#include "file_manager.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <functional>

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

