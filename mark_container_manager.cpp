#include "mark_container_manager.h"
#include <sstream>
MarkContainerManager::MarkContainerManager() {}

string MarkContainerManager::vectorToString(const vector<int>& ids) {
    ostringstream stream;

    for (size_t i = 0; i < ids.size(); ++i) {
        stream << ids[i];
        if (i < ids.size() - 1) {
            stream << " ";
        }
    }

    return stream.str();
}

void MarkContainerManager::addMotorbike(const Mark& mark, const Motorbike& motorbike) {
    motorbikeContainer.addVehicleId(mark.id, motorbike.model->id);
}

void MarkContainerManager::addPassengerCar(const Mark& mark, const PassengerCar& passengerCar) {
    passengerCarContainer.addVehicleId(mark.id, passengerCar.model->id);
}

void MarkContainerManager::addTruck(const Mark& mark, const Truck& truck) {
    truckContainer.addVehicleId(mark.id, truck.model->id);
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

vector<int> MarkContainerManager::getVehicleIdsByMark(int markId) const {
    vector<int> vehicleIds;
    auto motorbikeIds = motorbikeContainer.getOneTypeVehicleIds(markId);
    if (!motorbikeIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    auto passengerCarIds = passengerCarContainer.getOneTypeVehicleIds(markId);
    if (!passengerCarIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    auto truckIds = truckContainer.getOneTypeVehicleIds(markId);
    if (!truckIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), truckIds.begin(), truckIds.end());
    }
    return vehicleIds;
}

vector<int> MarkContainerManager::getMotorbikeModelsIds(int markId) {
    vector<int> ids;
    auto motorbikeIds = motorbikeContainer.getOneTypeVehicleIds(markId);
    if (!motorbikeIds.empty()) {
        ids.insert(ids.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    return ids;
}
vector<int> MarkContainerManager::getPassengerCarModelsIds(int markId) {
    vector<int> ids;
    auto passengerCarIds = passengerCarContainer.getOneTypeVehicleIds(markId);
    if (!passengerCarIds.empty()) {
        ids.insert(ids.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    return ids;
}
vector<int> MarkContainerManager::getTruckModelsIds(int markId) {
    vector<int> ids;
    auto truckIds = truckContainer.getOneTypeVehicleIds(markId);
    if (!truckIds.empty()) {
        ids.insert(ids.end(), truckIds.begin(), truckIds.end());
    }
    return ids;
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

