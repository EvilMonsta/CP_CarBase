#include "moto_show_display.h"
#include <iostream>
#include<QMap>
#include<QDebug>
MotoShowDisplay::MotoShowDisplay() {};

void MotoShowDisplay::prepareDataAndCreateBike(const QMap<QString, QString>& data, int markId, string imageName) {
    int id = motoManager.getNextMotoId();

    Motorbike newBike;
    MarkManager markManager;
    Mark mark = markManager.loadMark(markId);

    newBike.id = id;
    newBike.mark = &mark;
    newBike.model = data.value("Модель").toStdString();
    newBike.generation = data.value("Поколение").toStdString();
    newBike.produceDate = data.value("Год производства").toInt();
    newBike.factoryPrice = data.value("Цена").toInt();
    newBike.img = imageName;
    newBike.horsepower = data.value("Лошадиные силы").toInt();
    newBike.color = data.value("Цвет").toStdString();
    newBike.fuelVolume = data.value("Объем топлива").toDouble();
    newBike.engineType = data.value("Тип двигателя").toStdString();
    newBike.cylinderCapacity = data.value("Объем цилиндра").toDouble();

    motoManager.saveMotorbike(newBike);

    MarkContainerManager markContainerManager;

    markContainerManager.loadIdsFromFile();
    markContainerManager.addMotorbike(mark, newBike);
    markContainerManager.saveIdsToFile();
}
