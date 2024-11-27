#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include<car.h>
#include<passenger_car.h>
#include<truck.h>
#include<vehicle.h>
#include<mark_container_manager.h>
#include<moto_manager.h>
#include<QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/alfa.png"));
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
