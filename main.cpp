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

    // Mark kawasaki(50, "Kawasaki");
    // Mark yamaha(40,"YAMAHA");

    // Mark ford(20, "Ford");
    // Mark audi(30,"Audi");
    // Mark yamaha(40,"YAMAHA");
    // Mark kawa(50,"Kawasaki");

    return a.exec();
}
