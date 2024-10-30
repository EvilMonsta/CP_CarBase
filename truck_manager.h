#ifndef TRUCK_MANAGER_H
#define TRUCK_MANAGER_H
#include <string>
#include<truck.h>
#include<mark_manager.h>
using namespace std;

class TruckManager : public QObject {

    Q_OBJECT

private:
    FileManager fileManager;
    MarkManager markManager;

    string createFilepath(int id);

    string createData(const Truck& tr);

    Truck convertData(const string& data);

    const string folderPath = "C:/course/CourseProject/resources/trucks";

public:

    explicit TruckManager(QObject *parent = nullptr);

    ~TruckManager() {};

    string getFolderPath() const;

    void saveTruck(const Truck& tr);

    Truck loadTruck(int id);

    void deleteTruck(int id);

    void PrintTrucksIds();

};

#endif // TRUCK_MANAGER_H
