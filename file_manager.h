#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>

using namespace std;
class fileManager {
public:
    fileManager();

    ~fileManager() {}

    void saveToFile(const string& filepath, const string& data);

    string loadFromFile(const string& filepath);

    void deleteFile(const string& filePath);

};

#endif // FILE_MANAGER_H
