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

    void loadMoto(int id, Motorbike& bike, int& markId, int& modelId);

    void changeMoto(const QMap<QString, QString>& data, int markId, int modelId, string imageName, int id);

    void deleteMotorbike(int id);
};

#endif // MOTO_SHOW_DISPLAY_H
