#include "file_manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
fileManager::fileManager() {}

void fileManager::saveToFile(const string& filepath, const string& data) {
    ofstream file(filepath, ios::out | ios::app);
    if(file.is_open()) {
        file << data;
        file.close();
        cout << "data saved to: " << filepath << endl;
    } else {
        cout << "unable to open file!" << endl;
    }
};

string fileManager::loadFromFile(const string& filepath) {
    string data;
    ifstream file(filepath);

    if(file.is_open()) {
        stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
        file.close();
        cout << "file: " << filepath << " opened" << endl;
    } else {
        cout << "unable to open file" << endl;
        data = "";
    }
    return data;
};

void fileManager::deleteFile(const string& filepath) {
    if(filesystem::remove(filepath)) {
        cout << "file " << filepath << " removed" << endl;
    } else {
        cout << "unable to remove a file" << endl;
    }
};
