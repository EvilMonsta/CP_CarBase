#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
#include<vector>
#include <QObject>

using namespace std;
class fileManager : public QObject {

    Q_OBJECT

public:

    explicit fileManager(QObject *parent = nullptr);

    ~fileManager() {}

    void saveToFile(const string& filepath, const string& data);

    string loadFromFile(const string& filepath);

    void deleteFile(const string& filePath);

    int readMarkIdFromFile(const string& filePath);

    vector<int> openFilesInFolder(const string& folderPath);

    void printFilenamesInFolder(const string& folderPath);

};

#endif // FILE_MANAGER_H
