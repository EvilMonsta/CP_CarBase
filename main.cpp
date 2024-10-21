// #include "mainwindow;.h"

// #include <QApplication>
#include <QTextStream>
#include<car.h>
#include<iostream>
#include<passenger_car.h>
#include<truck.h>
#include<moto_manager.h>
#include<p_car_manager.h>
#include<vehicle.h>
#include<truck_manager.h>
int main(/*int argc, char *argv[]*/)
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

    MotoManager motoManager;
    PasCarManager pCarManager;
    TruckManager  trManager;

    Mark toyota(10, "Toyota");
    Mark ford(20, "Ford");
    Mark audi(30,"Audi");

    Motorbike mBike;
    PassengerCar c;
    Truck truck;

    PassengerCar pc(1,&toyota,"Camry",2023,"Auto",1.7,5);
    Truck tr(2,&audi,"Targa",2043,"Auto",3,4);
    Motorbike moto(5,&audi,"kapra",2001,"Kerosene",2);
    Motorbike moto1(2,&audi,"kapra",2001,"Kerosene",2);
    Motorbike moto2(1,&audi,"kapra",2001,"Kerosene",2);
    Motorbike moto3(3,&audi,"kapra",2001,"Kerosene",2);


    cout << "-------------------" << endl;

    pc.printData();
    tr.printData();
    moto.printData();

    motoManager.saveMotorbike(moto);
    // motoManager.deleteMotorbike(moto.id);
    // motoManager.saveMotorbike(moto1);
    // motoManager.saveMotorbike(moto2);
    // motoManager.saveMotorbike(moto3);

    // pCarManager.savePasCar(pc);
    trManager.saveTruck(tr);
    truck = trManager.loadTruck(2);
    truck.printData();
    c = pCarManager.loadPasCar(1);
    c.printData();
    mBike = motoManager.loadMotorbike(5);
    mBike.printData();

    //tr.saveToFile("C:/course/CourseProject/trucks.txt");
    //pc.saveToFile("C:/course/CourseProject/passenger_cars.txt");
    //moto.saveToFile("C:/course/CourseProject/motorbikes.txt");
}
