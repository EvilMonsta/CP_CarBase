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

    void addModel(int markId, const Model& model, const string& vehicleType);

    vector<int> getAllVehicleIds() const;

    vector<int> getModelsIdsByMark(int markId) const;

    vector<int> getMotorbikeModelsIds(int markId);

    vector<int> getPassengerCarModelsIds(int markId);

    vector<int> getTruckModelsIds(int markId);

    vector<int> getAllMotorbikeMarks();

    vector<int> getAllTruckMarks();

    vector<int> getAllPassengerCarMarks();

    void loadIdsFromFile();

    void saveIdsToFile();

    void sortContainers(int markId);

    void removeMark(int markId);

private:
    IdsContainer<Motorbike> motorbikeContainer;
    IdsContainer<PassengerCar> passengerCarContainer;
    IdsContainer<Truck> truckContainer;

    const string motorbikesPath = "C:/course/CourseProject/resources/idsByMark/motorbikes.txt";
    const string passengerCarsPath = "C:/course/CourseProject/resources/idsByMark/passengerCars.txt";
    const string trucksPath = "C:/course/CourseProject/resources/idsByMark/trucks.txt";

};

#endif // MARK_CONTAINER_MANAGER_H
