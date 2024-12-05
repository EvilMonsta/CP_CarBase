#ifndef P_CAR_SHOW_DISPLAY_H
#define P_CAR_SHOW_DISPLAY_H
#include <p_car_manager.h>


class PasCarShowDisplay
{
private:

    PasCarManager pasCarManager;

public:

    PasCarShowDisplay();

    ~PasCarShowDisplay() {};

    void prepareDataAndCreatePasCar(const QMap<QString, QString>& data, int markId, int modelId, string imageName);

    void loadPasCar(int id, PassengerCar& pCar);

    void deletePasCar(int id);

};

#endif // P_CAR_SHOW_DISPLAY_H


