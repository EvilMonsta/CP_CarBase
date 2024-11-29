#ifndef P_CAR_SHOW_DISPLAY_H
#define P_CAR_SHOW_DISPLAY_H
#include <p_car_manager.h>


class PasCarShowDisplay
{
private:

    PasCarManager pasCarManager;

public:

    PasCarShowDisplay();

    void prepareDataAndCreatePasCar(const QMap<QString, QString>& data, int markId, int modelId, string imageName);

    PassengerCar loadPasCar(int id);

};

#endif // P_CAR_SHOW_DISPLAY_H


