#ifndef TRUCK_SHOW_DISPLAY_H
#define TRUCK_SHOW_DISPLAY_H
#include "truck_manager.h"

class TruckShowDisplay
{
private:

    TruckManager truckManager;

public:
    TruckShowDisplay();

    void prepareDataAndCreateTruck(const QMap<QString, QString>& data, int markId, int modelId, string imageName);

};

#endif // TRUCK_SHOW_DISPLAY_H

