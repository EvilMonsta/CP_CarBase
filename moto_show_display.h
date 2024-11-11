#ifndef MOTO_SHOW_DISPLAY_H
#define MOTO_SHOW_DISPLAY_H
#include <moto_manager.h>
class MotoShowDisplay
{
private:

    MotoManager motoManager;

    void printIds(vector<int> ids);

public:
    MotoShowDisplay();

    void printData(int id);

    void PrintMotorbikesIds();

    void prepareDataAndCreateBike(const QMap<QString, QString>& data);

};

#endif // MOTO_SHOW_DISPLAY_H
