#ifndef MOTO_SHOW_DISPLAY_H
#define MOTO_SHOW_DISPLAY_H
#include <moto_manager.h>
class MotoShowDisplay
{
private:

    MotoManager motoManager;


public:
    MotoShowDisplay();

    ~MotoShowDisplay() {};

    void prepareDataAndCreateBike(const QMap<QString, QString>& data, int markId, int modelId, string imageName);

    Motorbike loadMoto(int id);
};

#endif // MOTO_SHOW_DISPLAY_H
