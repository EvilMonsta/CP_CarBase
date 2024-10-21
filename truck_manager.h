#ifndef TRUCK_MANAGER_H
#define TRUCK_MANAGER_H
#include <string>
#include<truck.h>
#include<file_manager.h>
using namespace std;

class TruckManager : public fileManager {
private:

    string createFilepath(int id);

    string createData(const Truck& tr);

    Truck convertData(const string& data);

public:

    const string folderPath = "C:/course/CourseProject/resources/trucks";

    TruckManager() {};

    ~TruckManager() {};

    void saveTruck(const Truck& tr);

    Truck loadTruck(int id);

    void deleteTruck(int id);

};

#endif // TRUCK_MANAGER_H
