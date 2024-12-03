#include "truck_show_display.h"
#include <iostream>
#include <QLocale>

TruckShowDisplay::TruckShowDisplay() {}

void TruckShowDisplay::prepareDataAndCreateTruck(const QMap<QString, QString>& data, int markId, int modelId, string imageName){
    int id = truckManager.getNextTruckId();
    QLocale locale(QLocale::Russian);

    Truck newTruck;
    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);

    newTruck.id = id;
    newTruck.mark = &mark;
    newTruck.model = &model;
    newTruck.generation = data.value("Поколение").toStdString();
    newTruck.produceDate = data.value("Год производства").toInt();
    newTruck.factoryPrice = data.value("Цена").toInt();
    newTruck.img = imageName;
    newTruck.horsepower = data.value("Лошадиные силы").toInt();
    newTruck.color = data.value("Цвет").toStdString();
    data.value("Объем топлива").replace(',', '.');
    newTruck.fuelVolume = locale.toDouble(data.value("Объем топлива"));
    newTruck.transmissionType = data.value("Тип трансмиссии").toStdString();
    data.value("Объем двигателя").replace(',', '.');
    newTruck.engineCapacity = locale.toDouble(data.value("Объем двигателя"));
    newTruck.loadCapacity = data.value("Грузоподъемность").toDouble();

    truckManager.saveTruck(newTruck);

    MarkContainerManager markContainerManager;
    ModelContainerManager modelContainerManager;

    modelContainerManager.loadIdsFromFile();
    modelContainerManager.addTruck(model, newTruck);
    modelContainerManager.saveIdsToFile();

}


Truck TruckShowDisplay::loadTruck(int id){
    Truck truck = truckManager.loadTruck(id);
    return truck;
}
