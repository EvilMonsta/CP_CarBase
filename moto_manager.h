#ifndef MOTO_MANAGER_H
#define MOTO_MANAGER_H
#include <string>
#include<motorbike.h>
#include<file_manager.h>
using namespace std;

class MotoManager : public fileManager{
private:

    string createFilepath(int id);

    string createData(const Motorbike& bike);

    Motorbike convertData(const string& data);

public:
    const string folderPath = "C:/course/CourseProject/resources/motorbikes";

    MotoManager() {};

    ~MotoManager() {};

    void saveMotorbike(const Motorbike& bike);

    Motorbike loadMotorbike(int id);

    void deleteMotorbike(int id);

    void PrintMotorbikesIds();

};

#endif // MOTO_MANAGER_H
