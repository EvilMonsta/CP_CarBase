#include "model_container_manager.h"
#include <sstream>

ModelContainerManager::ModelContainerManager() {}

void ModelContainerManager::addMotorbike(const Model& model, const Motorbike& motorbike) {
    motorbikeContainer.addValue(model.id, motorbike.id);
}

void ModelContainerManager::addPassengerCar(const Model& model, const PassengerCar& passengerCar) {
    passengerCarContainer.addValue(model.id, passengerCar.id);
}

void ModelContainerManager::addTruck(const Model& model, const Truck& truck) {
    truckContainer.addValue(model.id, truck.id);
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
    auto motorbikeIds = motorbikeContainer.getValuesByOneKey(modelId);
    if (!motorbikeIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    auto passengerCarIds = passengerCarContainer.getValuesByOneKey(modelId);
    if (!passengerCarIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    auto truckIds = truckContainer.getValuesByOneKey(modelId);
    if (!truckIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), truckIds.begin(), truckIds.end());
    }
    return vehicleIds;
}

vector<int> ModelContainerManager::getMotorbikeIds(int modelId) {
    vector<int> ids;
    auto motorbikeIds = motorbikeContainer.getValuesByOneKey(modelId);
    if (!motorbikeIds.empty()) {
        ids.insert(ids.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    return ids;
}
vector<int> ModelContainerManager::getPassengerCarIds(int modelId) {
    vector<int> ids;
    auto passengerCarIds = passengerCarContainer.getValuesByOneKey(modelId);
    if (!passengerCarIds.empty()) {
        ids.insert(ids.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    return ids;
}
vector<int> ModelContainerManager::getTruckIds(int modelId) {
    vector<int> ids;
    auto truckIds = truckContainer.getValuesByOneKey(modelId);
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

void ModelContainerManager::removeVehicleByModel(int modelId, int vehicleId, const string& vehicleType) {
    if (vehicleType == "Мотоцикл") {
        motorbikeContainer.removeValueByKey(motorbikeContainer.begin(), motorbikeContainer.end(), modelId, vehicleId);
    } else if (vehicleType == "Легковая") {
        passengerCarContainer.removeValueByKey(passengerCarContainer.begin(), passengerCarContainer.end(), modelId, vehicleId);
    } else if (vehicleType == "Грузовик") {
        truckContainer.removeValueByKey(truckContainer.begin(), truckContainer.end(), modelId, vehicleId);
    }
}


void ModelContainerManager::removeModel(int modelId) {
    auto motorbikeIt = motorbikeContainer.find(modelId);
    if (motorbikeIt != motorbikeContainer.end()) {
        motorbikeContainer.erase(motorbikeIt);
    }
    auto passengerCarIt = passengerCarContainer.find(modelId);
    if (passengerCarIt != passengerCarContainer.end()) {
        passengerCarContainer.erase(passengerCarIt);
    }
    auto truckIt = truckContainer.find(modelId);
    if (truckIt != truckContainer.end()) {
        truckContainer.erase(truckIt);
    }
}


