#ifndef TRUCK_SHOW_DISPLAY_H
#define TRUCK_SHOW_DISPLAY_H
#include "truck_manager.h"

class TruckShowDisplay
{
public:
    TruckShowDisplay();

    void printData(int id);

    void PrintTrucksIds();
private:

    TruckManager truckManager;

};

#endif // TRUCK_SHOW_DISPLAY_H

