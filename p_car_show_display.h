#ifndef P_CAR_SHOW_DISPLAY_H
#define P_CAR_SHOW_DISPLAY_H
#include <p_car_manager.h>


class PasCarShowDisplay
{
public:
    PasCarShowDisplay();

    void printData(int id);

    void PrintPasCarsIds();

private:

    PasCarManager pasCarManager;

};

#endif // P_CAR_SHOW_DISPLAY_H


