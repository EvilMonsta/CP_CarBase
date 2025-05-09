#ifndef P_CAR_MANAGER_H
#define P_CAR_MANAGER_H
#include <string>
#include<passenger_car.h>
#include<mark_manager.h>
#include<model_manager.h>
using namespace std;

class PasCarManager : public QObject {

    Q_OBJECT

private:
    FileManager fileManager;
    MarkManager markManager;
    ModelManager modelManager;

    string createFilepath(int id);

    string createData(const PassengerCar& pCar);

    PassengerCar convertData(const string& data);

    const string folderPath = "C:/course/CourseProject/resources/passengerCars";

public:

    explicit PasCarManager(QObject *parent = nullptr);

    ~PasCarManager() {};

    string getFolderPath() const;

    void savePasCar(const PassengerCar& pCar);

    PassengerCar loadPasCar(int id);

    void deletePasCar(int id);

    vector<int> readIds(const string& folderPath);

    int getNextPassengerCarId();

};

#endif // P_CAR_MANAGER_H

