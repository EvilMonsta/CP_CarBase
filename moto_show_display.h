#ifndef MOTO_SHOW_DISPLAY_H
#define MOTO_SHOW_DISPLAY_H
#include <moto_manager.h>
class MotoShowDisplay
{
public:
    MotoShowDisplay();

    void printData(int id);

    void PrintMotorbikesIds();

private:

    MotoManager motoManager;

};

#endif // MOTO_SHOW_DISPLAY_H
