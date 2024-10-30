#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
#include<vector>
#include <QObject>
#include<functional>
using namespace std;
class FileManager : public QObject {

    Q_OBJECT

public:

    explicit FileManager(QObject *parent = nullptr);

    ~FileManager() {}

    // void saveToFile(const string& filepath, const string& data);

    // string loadFromFile(const string& filepath);

    template <typename T>
    void saveToFile(const T& obj, const string& filepath, function<string(const T&)> createData);

    template <typename T>
    T loadFromFile(const string& filepath, function<T(const string&)> convertData);

    void deleteFile(const string& filePath);

    int readMarkIdFromFile(const string& filePath);

    vector<int> openFilesInFolder(const string& folderPath);

    void printFilenamesInFolder(const string& folderPath);

};
#include "file_manager.tpp"
#endif // FILE_MANAGER_H
