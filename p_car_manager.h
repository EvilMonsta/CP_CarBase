#ifndef P_CAR_MANAGER_H
#define P_CAR_MANAGER_H
#include <string>
#include<passenger_car.h>
#include<mark_manager.h>
using namespace std;

class PasCarManager : public FileManager {

    Q_OBJECT

private:

    MarkManager markManager;

    string createFilepath(int id);

    string createData(const PassengerCar& pCar);

    PassengerCar convertData(const string& data);

    const string folderPath = "C:/course/CourseProject/resources/motorbikes";

public:

    explicit PasCarManager(QObject *parent = nullptr);

    ~PasCarManager() {};

    string getFolderPath() const;

    void savePasCar(const PassengerCar& bike);

    PassengerCar loadPasCar(int id);

    void deletePasCar(int id);

    void PrintPasCarIds();

};

#endif // P_CAR_MANAGER_H

