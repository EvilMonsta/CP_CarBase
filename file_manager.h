#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <open_file_exception.h>
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

    template <typename T>
    void saveToFile(const T& obj, const string& filepath, function<string(const T&)> createData){
        try {
            ofstream file(filepath);
            if (!file.is_open()) {
                throw OpenFileException("Невозможно открыть файл для сохранения: " + filepath);
            }

            string data = createData(obj);
            file << data;
            file.close();
        } catch (const OpenFileException& ofexp) {
            OpenFileException::showErrorDialog(QString::fromStdString(ofexp.what()));
        }

    }

    template <typename T>
    T loadFromFile(const string& filepath, function<T(const string&)> convertData) {
        try {
            ifstream file(filepath);
            if (!file.is_open()) {
                throw OpenFileException("Невозможно открыть файл для загрузки данных: " + filepath);
            }
            string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();
            return convertData(data);
        } catch(const OpenFileException& ofexp) {
            OpenFileException::showErrorDialog(QString::fromStdString(ofexp.what()));
            return T();
        }
    }

    void deleteFile(const string& filePath);

    vector<int> readIdFromFilenames(const string& folderPath, function<int(const string&)> idExtractor);

    int idExtractor(const string& filePath);

    int getNextAvailableId(const string& folderPath);

};
#endif // FILE_MANAGER_H
