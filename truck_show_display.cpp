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

void TruckShowDisplay::changeTruck(const QMap<QString, QString>& data, int markId, int modelId, string imageName, int id) {
    QLocale locale(QLocale::Russian);

    Truck truck;

    truck = truckManager.loadTruck(id);
    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);
    truck.mark = new Mark(mark);
    truck.model = new Model(model);
    truck.generation = data.value("Поколение").toStdString();
    truck.produceDate = data.value("Год производства").toInt();
    truck.factoryPrice = data.value("Цена").toInt();
    truck.img = imageName;
    truck.horsepower = data.value("Лошадиные силы").toInt();
    truck.color = data.value("Цвет").toStdString();
    data.value("Объем топлива").replace(',', '.');
    truck.fuelVolume = locale.toDouble(data.value("Объем топлива"));
    truck.transmissionType = data.value("Тип трансмиссии").toStdString();
    data.value("Объем двигателя").replace(',', '.');
    truck.engineCapacity = locale.toDouble(data.value("Объем двигателя"));
    truck.loadCapacity = data.value("Грузоподъемность").toDouble();

    truckManager.saveTruck(truck);
}

void TruckShowDisplay::loadTruck(int id, Truck& truck, int& markId, int& modelId){
    truck = truckManager.loadTruck(id);
    markId = truck.mark->id;
    modelId = truck.model->id;
}

void TruckShowDisplay::deleteTruck(int id){
    truckManager.deleteTruck(id);
}
