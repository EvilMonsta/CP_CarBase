#include "truck_show_display.h"
#include <iostream>

TruckShowDisplay::TruckShowDisplay() {}

void TruckShowDisplay::prepareDataAndCreateTruck(const QMap<QString, QString>& data, int markId, int modelId, string imageName){
    int id = truckManager.getNextTruckId();

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
    newTruck.fuelVolume = data.value("Объем топлива").toDouble();
    newTruck.transmissionType = data.value("Тип трансмиссии").toStdString();
    newTruck.engineCapacity = data.value("Объем двигателя").toDouble();
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
