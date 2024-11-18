#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include<car.h>
#include<passenger_car.h>
#include<truck.h>
#include<vehicle.h>
#include<mark_container_manager.h>
#include<moto_manager.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
