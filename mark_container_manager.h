#ifndef MARK_CONTAINER_MANAGER_H
#define MARK_CONTAINER_MANAGER_H

#include "ids_container.h"
#include "motorbike.h"
#include "passenger_car.h"
#include "truck.h"
#include "mark.h"
#include <vector>

class MarkContainerManager {
public:
    MarkContainerManager();

    void addMotorbike(const Mark& mark, const Motorbike& motorbike);
    void addPassengerCar(const Mark& mark, const PassengerCar& passengerCar);
    void addTruck(const Mark& mark, const Truck& truck);

    vector<int> getAllVehicleIds() const;

    vector<int> getVehicleIdsByMark(int markId) const;

    vector<int> getMotorbikeModelsIds(int markId);

    vector<int> getPassengerCarModelsIds(int markId);

    vector<int> getTruckModelsIds(int markId);

    void loadIdsFromFile();

    void saveIdsToFile();

private:
    IdsContainer<Motorbike> motorbikeContainer;
    IdsContainer<PassengerCar> passengerCarContainer;
    IdsContainer<Truck> truckContainer;

    const string motorbikesPath = "C:/course/CourseProject/resources/idsByMark/motorbikes.txt";
    const string passengerCarsPath = "C:/course/CourseProject/resources/idsByMark/passengerCars.txt";
    const string trucksPath = "C:/course/CourseProject/resources/idsByMark/trucks.txt";

    string vectorToString(const vector<int>& ids);
};

#endif // MARK_CONTAINER_MANAGER_H
