#include "mark_container_manager.h"

MarkContainerManager::MarkContainerManager() {}

void MarkContainerManager::addMotorbike(const Mark& mark, const Motorbike& motorbike) {
    motorbikeContainer.addVehicleId(mark, motorbike.id);
}

void MarkContainerManager::addPassengerCar(const Mark& mark, const PassengerCar& passengerCar) {
    passengerCarContainer.addVehicleId(mark, passengerCar.id);
}

void MarkContainerManager::addTruck(const Mark& mark, const Truck& truck) {
    truckContainer.addVehicleId(mark, truck.id);
}

vector<int> MarkContainerManager::getAllVehicleIds() const {
    std::vector<int> allIds;
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
    // Получаем ID мотоциклов для данной марки
    auto motorbikeIds = motorbikeContainer.getOneTypeVehicleIds(markId);
    if (!motorbikeIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), motorbikeIds.begin(), motorbikeIds.end());
    }
    // Получаем ID легковых автомобилей для данной марки
    auto passengerCarIds = passengerCarContainer.getOneTypeVehicleIds(markId);
    if (!passengerCarIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), passengerCarIds.begin(), passengerCarIds.end());
    }
    // // Получаем ID грузовиков для данной марки
    auto truckIds = truckContainer.getOneTypeVehicleIds(markId);
    if (!truckIds.empty()) {
        vehicleIds.insert(vehicleIds.end(), truckIds.begin(), truckIds.end());
    }
    return vehicleIds;
}

void MarkContainerManager::pr(){
    motorbikeContainer.printRegistry();
    passengerCarContainer.printRegistry();
    truckContainer.printRegistry();
}
