#ifndef MARK_CONTAINER_MANAGER_H
#define MARK_CONTAINER_MANAGER_H

#include "marks_transport_id_container.h"
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

    void pr();

private:
    MarksTransportIdContainer<Motorbike> motorbikeContainer;
    MarksTransportIdContainer<PassengerCar> passengerCarContainer;
    MarksTransportIdContainer<Truck> truckContainer;
};

#endif // MARK_CONTAINER_MANAGER_H
