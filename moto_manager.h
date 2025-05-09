#ifndef MOTO_MANAGER_H
#define MOTO_MANAGER_H
#include <string>
#include<motorbike.h>
#include<mark_manager.h>
#include<model_manager.h>
using namespace std;

class MotoManager : public QObject {
    Q_OBJECT
private:
    FileManager fileManager;
    MarkManager markManager;
    ModelManager modelManager;

    string createFilepath(int id);

    string createData(const Motorbike& bike);

    Motorbike convertData(const string& data);

    const string folderPath = "C:/course/CourseProject/resources/motorbikes";

public:
    explicit MotoManager(QObject *parent = nullptr);

    ~MotoManager() {};

    string getFolderPath() const;

    void saveMotorbike(const Motorbike& bike);

    Motorbike loadMotorbike(int id);

    void deleteMotorbike(int id);

    vector<int> readIds(const string& folderPath);

    int getNextMotoId();

};

#endif // MOTO_MANAGER_H
