#ifndef TRUCK_SHOW_DISPLAY_H
#define TRUCK_SHOW_DISPLAY_H
#include "truck_manager.h"

class TruckShowDisplay
{
private:

    void printIds(vector<int> ids);

    TruckManager truckManager;

public:
    TruckShowDisplay();

    void printData(int id);

    void PrintTrucksIds();
};

#endif // TRUCK_SHOW_DISPLAY_H

