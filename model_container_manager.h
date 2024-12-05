#ifndef MODEL_CONTAINER_MANAGER_H
#define MODEL_CONTAINER_MANAGER_H
#include "model.h"
#include<mark_container_manager.h>

class ModelContainerManager {
public:
    ModelContainerManager();

    void addMotorbike(const Model& model, const Motorbike& motorbike);
    void addPassengerCar(const Model& model, const PassengerCar& passengerCar);
    void addTruck(const Model& model, const Truck& truck);

    vector<int> getAllVehicleIds() const;

    vector<int> getVehicleIdsByModel(int modelId) const;

    vector<int> getMotorbikeIds(int modelId);

    vector<int> getPassengerCarIds(int modelId);

    vector<int> getTruckIds(int modelId);

    void loadIdsFromFile();

    void saveIdsToFile();

    void removeVehicleByModel(int modelId, int vehicleId, const string& vehicleType);

    void removeModel(int modelId);

private:
    MarkContainerManager markcontainerManager;
    IdsContainer<Motorbike> motorbikeContainer;
    IdsContainer<PassengerCar> passengerCarContainer;
    IdsContainer<Truck> truckContainer;

    const string motorbikesPath = "C:/course/CourseProject/resources/idsByModel/motorbikes.txt";
    const string passengerCarsPath = "C:/course/CourseProject/resources/idsByModel/passengerCars.txt";
    const string trucksPath = "C:/course/CourseProject/resources/idsByModel/trucks.txt";

};

#endif // MODEL_CONTAINER_MANAGER_H
