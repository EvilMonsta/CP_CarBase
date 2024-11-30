#ifndef TRANSPORT_LOADER_H
#define TRANSPORT_LOADER_H
#include <QPushButton>
#include "motorbike.h"
#include "passenger_car.h"
#include "truck.h"
#include <QLabel>
class TransportLoader {
public:
    static void loadMotorbikeData(const Motorbike &bike, QPushButton *button);
    static void loadPassengerCarData(const PassengerCar &pCar, QPushButton *button);
    static void loadTruckData(const Truck &truck, QPushButton *button);
    static void loadMotorbikeToInfoPage(int id, QLabel *name, QLabel *year, QLabel *price,
                                        QLabel *power, QLabel *color, QLabel* fuel,
                                        QLabel *engine, QLabel *capacity, QLabel *imageLabel);
    static void loadPassengerCarToInfoPage(int id, QLabel *name, QLabel *year, QLabel *price,
                                           QLabel *power, QLabel *color, QLabel* fuel,
                                           QLabel *engine, QLabel *capacity, QLabel *seats, QLabel *imageLabel);
    static void loadTruckToInfoPage(int id, QLabel *name, QLabel *year, QLabel *price,
                                    QLabel *power, QLabel *color, QLabel* fuel,
                                    QLabel *engine, QLabel *capacity,QLabel *load, QLabel *imageLabel);
};
#endif // TRANSPORT_LOADER_H
