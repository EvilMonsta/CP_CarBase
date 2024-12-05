#include "mark_container_manager.h"
MarkContainerManager::MarkContainerManager() {}

void MarkContainerManager::sortContainers(int markId) {

    vector<int>idsM = motorbikeContainer.getValuesByOneKey(markId);
    vector<int>idsT = truckContainer.getValuesByOneKey(markId);
    vector<int>idsC = passengerCarContainer.getValuesByOneKey(markId);

    motorbikeContainer.sortRange(idsM.begin(), idsM.end());
    truckContainer.sortRange(idsT.begin(), idsT.end());
    passengerCarContainer.sortRange(idsC.begin(), idsC.end());

    motorbikeContainer.changeIds(idsM,markId);
    truckContainer.changeIds(idsT,markId);
    passengerCarContainer.changeIds(idsC,markId);
}


void MarkContainerManager::addModel(int markId, const Model& model, const string& vehicleType){
    if(vehicleType == "Мотоцикл") {
        motorbikeContainer.addValue(markId, model.id);
    } else if (vehicleType == "Легковая") {
        passengerCarContainer.addValue(markId, model.id);
    } else if (vehicleType == "Грузовик") {
        truckContainer.addValue(markId, model.id);
    }
}

vector<int> MarkContainerManager::getAllVehicleIds() const {
    vector<int> allIds;
    auto motorbikeIds = motorbikeContainer.getAllVehicleIds();
    allIds.insert(allIds.end(), motorbikeIds.begin(), motorbikeIds.end());

    auto passengerCarIds = passengerCarContainer.getAllVehicleIds();
    allIds.insert(allIds.end(), passengerCarIds.begin(), passengerCarIds.end());

    auto truckIds = truckContainer.getAllVehicleIds();
    allIds.insert(allIds.end(), truckIds.begin(), truckIds.end());

    return allIds;
}

vector<int> MarkContainerManager::getModelsIdsByMark(int markId) const {
    vector<int> vehicleIds;
    auto motorbikeIds = motorbikeContainer.getValuesByOneKey(markId);
    if (!motorbikeIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    auto passengerCarIds = passengerCarContainer.getValuesByOneKey(markId);
    if (!passengerCarIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    auto truckIds = truckContainer.getValuesByOneKey(markId);
    if (!truckIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), truckIds.begin(), truckIds.end());
    }
    return vehicleIds;
}

vector<int> MarkContainerManager::getMotorbikeModelsIds(int markId) {
    vector<int> ids;
    auto motorbikeIds = motorbikeContainer.getValuesByOneKey(markId);
    if (!motorbikeIds.empty()) {
        ids.insert(ids.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    return ids;
}
vector<int> MarkContainerManager::getPassengerCarModelsIds(int markId) {
    vector<int> ids;
    auto passengerCarIds = passengerCarContainer.getValuesByOneKey(markId);
    if (!passengerCarIds.empty()) {
        ids.insert(ids.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    return ids;
}
vector<int> MarkContainerManager::getTruckModelsIds(int markId) {
    vector<int> ids;
    auto truckIds = truckContainer.getValuesByOneKey(markId);
    if (!truckIds.empty()) {
        ids.insert(ids.end(), truckIds.begin(), truckIds.end());
    }
    return ids;
}

vector<int> MarkContainerManager::getAllMotorbikeMarks() {
    return motorbikeContainer.getKeys();
}
vector<int> MarkContainerManager::getAllTruckMarks() {
    return truckContainer.getKeys();
}
vector<int> MarkContainerManager::getAllPassengerCarMarks() {
    return passengerCarContainer.getKeys();
}

void MarkContainerManager::saveIdsToFile() {
    motorbikeContainer.saveToFile(motorbikesPath);
    passengerCarContainer.saveToFile(passengerCarsPath);
    truckContainer.saveToFile(trucksPath);
}

void MarkContainerManager::loadIdsFromFile() {
    motorbikeContainer.loadFromFile(motorbikesPath);
    passengerCarContainer.loadFromFile(passengerCarsPath);
    truckContainer.loadFromFile(trucksPath);
}

void MarkContainerManager::removeMark(int markId) {
    auto motorbikeIt = motorbikeContainer.find(markId);
    if (motorbikeIt != motorbikeContainer.end()) {
        motorbikeContainer.erase(motorbikeIt);
    }
    auto passengerCarIt = passengerCarContainer.find(markId);
    if (passengerCarIt != passengerCarContainer.end()) {
        passengerCarContainer.erase(passengerCarIt);
    }
    auto truckIt = truckContainer.find(markId);
    if (truckIt != truckContainer.end()) {
        truckContainer.erase(truckIt);
    }
}

