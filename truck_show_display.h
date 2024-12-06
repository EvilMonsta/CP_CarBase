#ifndef TRUCK_SHOW_DISPLAY_H
#define TRUCK_SHOW_DISPLAY_H
#include "truck_manager.h"

class TruckShowDisplay
{
private:

    TruckManager truckManager;

public:
    TruckShowDisplay();

    ~TruckShowDisplay() {};

    void prepareDataAndCreateTruck(const QMap<QString, QString>& data, int markId, int modelId, string imageName);

    void loadTruck(int id, Truck &truck, int& markId, int& modelId);

    void changeTruck(const QMap<QString, QString>& data, int markId, int modelId, string imageName, int id);

    void deleteTruck(int id);

};

#endif // TRUCK_SHOW_DISPLAY_H

