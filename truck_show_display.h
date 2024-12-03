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

    Truck loadTruck(int id);
};

#endif // TRUCK_SHOW_DISPLAY_H

