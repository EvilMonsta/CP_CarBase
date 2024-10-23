#ifndef P_CAR_MANAGER_H
#define P_CAR_MANAGER_H
#include <string>
#include<passenger_car.h>
#include<file_manager.h>
using namespace std;

class PasCarManager : public fileManager {
private:

    string createFilepath(int id);

    string createData(const PassengerCar& pCar);

    PassengerCar convertData(const string& data);

public:

    const string folderPath = "C:/course/CourseProject/resources/passengerCars";

    PasCarManager() {};

    ~PasCarManager() {};

    void savePasCar(const PassengerCar& bike);

    PassengerCar loadPasCar(int id);

    void deletePasCar(int id);

    void PrintPasCarIds();

};

#endif // P_CAR_MANAGER_H

