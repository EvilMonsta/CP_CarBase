#include "moto_show_display.h"
#include <iostream>
#include <QLocale>

MotoShowDisplay::MotoShowDisplay() {};

void MotoShowDisplay::prepareDataAndCreateBike(const QMap<QString, QString>& data, int markId, int modelId, string imageName) {
    int id = motoManager.getNextMotoId();
    QLocale locale(QLocale::Russian);
    Motorbike newBike;
    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);
    newBike.id = id;
    newBike.mark = &mark;
    newBike.model = &model;
    newBike.generation = data.value("Поколение").toStdString();
    newBike.produceDate = data.value("Год производства").toInt();
    newBike.factoryPrice = data.value("Цена").toInt();
    newBike.img = imageName;
    newBike.horsepower = data.value("Лошадиные силы").toInt();
    newBike.color = data.value("Цвет").toStdString();
    newBike.fuelVolume = locale.toDouble(data.value("Объем топлива"));
    newBike.engineType = data.value("Тип двигателя").toStdString();
    newBike.cylinderCapacity = locale.toDouble(data.value("Объем цилиндра"));
    motoManager.saveMotorbike(newBike);

    MarkContainerManager markContainerManager;
    ModelContainerManager modelContainerManager;

    modelContainerManager.loadIdsFromFile();
    modelContainerManager.addMotorbike(model, newBike);
    modelContainerManager.saveIdsToFile();
}

void MotoShowDisplay::loadMoto(int id, Motorbike& bike){
    bike = motoManager.loadMotorbike(id);
}

void MotoShowDisplay::changeMoto(const QMap<QString, QString>& data, string imageName, int id) {
    QLocale locale(QLocale::Russian);
    Motorbike bike;
    bike = motoManager.loadMotorbike(id);
    bike.generation = data.value("Поколение").toStdString();
    bike.produceDate = data.value("Год производства").toInt();
    bike.factoryPrice = data.value("Цена").toInt();
    bike.img = imageName;
    bike.horsepower = data.value("Лошадиные силы").toInt();
    bike.color = data.value("Цвет").toStdString();
    bike.fuelVolume = locale.toDouble(data.value("Объем топлива"));
    bike.engineType = data.value("Тип двигателя").toStdString();
    bike.cylinderCapacity = locale.toDouble(data.value("Объем цилиндра"));
    motoManager.saveMotorbike(bike);
}


void MotoShowDisplay::deleteMotorbike(int id) {
    motoManager.deleteMotorbike(id);
}
