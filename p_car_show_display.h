#ifndef P_CAR_SHOW_DISPLAY_H
#define P_CAR_SHOW_DISPLAY_H
#include <p_car_manager.h>


class PasCarShowDisplay
{
private:

    PasCarManager pasCarManager;

    void printIds(vector<int> ids);

public:

    PasCarShowDisplay();

    void printData(int id);

    void PrintPassengerCarsIds();

};

#endif // P_CAR_SHOW_DISPLAY_H


