#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
#include<vector>
#include <QObject>
#include<functional>
#include <iostream>
#include <fstream>
using namespace std;
class FileManager : public QObject {

    Q_OBJECT

public:

    explicit FileManager(QObject *parent = nullptr);

    ~FileManager() {}

    // void saveToFile(const string& filepath, const string& data);

    // string loadFromFile(const string& filepath);

    template <typename T>
    void saveToFile(const T& obj, const string& filepath, function<string(const T&)> createData){
        ofstream file(filepath);
        if (!file.is_open()) {
            cout << "error" << endl;
            return;
        }

        string data = createData(obj);
        file << data;
        file.close();

        cout << "Successfull wrote to file: " << filepath << endl;
    }

    template <typename T>
    T loadFromFile(const string& filepath, function<T(const string&)> convertData) {
        ifstream file(filepath);
        if (!file.is_open()) {
            cout << "Unable to open: " << filepath << endl;
            return T();
        }

        string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file.close();

        cout << "successful" << endl;
        return convertData(data);
    }

    void deleteFile(const string& filePath);

    int readMarkIdFromFile(const string& filePath);

    vector<int> openFilesInFolder(const string& folderPath);

    void printFilenamesInFolder(const string& folderPath);

};
#endif // FILE_MANAGER_H
