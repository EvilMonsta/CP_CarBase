#include "model_container_manager.h"
#include <sstream>

ModelContainerManager::ModelContainerManager() {}

string ModelContainerManager::vectorToString(const vector<int>& ids) {
    ostringstream stream;

    for (size_t i = 0; i < ids.size(); ++i) {
        stream << ids[i];
        if (i < ids.size() - 1) {
            stream << " ";
        }
    }

    return stream.str();
}

void ModelContainerManager::addMotorbike(const Model& model, const Motorbike& motorbike) {
    motorbikeContainer.addVehicleId(model.id, motorbike.id);
}

void ModelContainerManager::addPassengerCar(const Model& model, const PassengerCar& passengerCar) {
    passengerCarContainer.addVehicleId(model.id, passengerCar.id);
}

void ModelContainerManager::addTruck(const Model& model, const Truck& truck) {
    truckContainer.addVehicleId(model.id, truck.id);
}

vector<int> ModelContainerManager::getAllVehicleIds() const {
    vector<int> allIds;
    auto motorbikeIds = motorbikeContainer.getAllVehicleIds();
    allIds.insert(allIds.end(), motorbikeIds.begin(), motorbikeIds.end());

    auto passengerCarIds = passengerCarContainer.getAllVehicleIds();
    allIds.insert(allIds.end(), passengerCarIds.begin(), passengerCarIds.end());

    auto truckIds = truckContainer.getAllVehicleIds();
    allIds.insert(allIds.end(), truckIds.begin(), truckIds.end());

    return allIds;
}

vector<int> ModelContainerManager::getVehicleIdsByModel(int modelId) const {
    vector<int> vehicleIds;
    auto motorbikeIds = motorbikeContainer.getOneTypeVehicleIds(modelId);
    if (!motorbikeIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    auto passengerCarIds = passengerCarContainer.getOneTypeVehicleIds(modelId);
    if (!passengerCarIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    auto truckIds = truckContainer.getOneTypeVehicleIds(modelId);
    if (!truckIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), truckIds.begin(), truckIds.end());
    }
    return vehicleIds;
}

vector<int> ModelContainerManager::getMotorbikeIds(int modelId) {
    vector<int> ids;
    auto motorbikeIds = motorbikeContainer.getOneTypeVehicleIds(modelId);
    if (!motorbikeIds.empty()) {
        ids.insert(ids.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    return ids;
}
vector<int> ModelContainerManager::getPassengerCarIds(int modelId) {
    vector<int> ids;
    auto passengerCarIds = passengerCarContainer.getOneTypeVehicleIds(modelId);
    if (!passengerCarIds.empty()) {
        ids.insert(ids.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    return ids;
}
vector<int> ModelContainerManager::getTruckIds(int modelId) {
    vector<int> ids;
    auto truckIds = truckContainer.getOneTypeVehicleIds(modelId);
    if (!truckIds.empty()) {
        ids.insert(ids.end(), truckIds.begin(), truckIds.end());
    }
    return ids;
}

void ModelContainerManager::saveIdsToFile() {
    motorbikeContainer.saveToFile(motorbikesPath);
    passengerCarContainer.saveToFile(passengerCarsPath);
    truckContainer.saveToFile(trucksPath);
}

void ModelContainerManager::loadIdsFromFile() {
    motorbikeContainer.loadFromFile(motorbikesPath);
    passengerCarContainer.loadFromFile(passengerCarsPath);
    truckContainer.loadFromFile(trucksPath);
}


