#include "p_car_show_display.h"
#include <iostream>
#include <QLocale>

PasCarShowDisplay::PasCarShowDisplay() {}

void PasCarShowDisplay::prepareDataAndCreatePasCar(const QMap<QString, QString>& data, int markId, int modelId, string imageName) {
    int id = pasCarManager.getNextPassengerCarId();
    QLocale locale(QLocale::Russian);

    PassengerCar newPasCar;
    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);

    newPasCar.id = id;
    newPasCar.mark = &mark;
    newPasCar.model = &model;
    newPasCar.generation = data.value("Поколение").toStdString();
    newPasCar.produceDate = data.value("Год производства").toInt();
    newPasCar.factoryPrice = data.value("Цена").toInt();
    newPasCar.img = imageName;
    newPasCar.horsepower = data.value("Лошадиные силы").toInt();
    newPasCar.color = data.value("Цвет").toStdString();
    newPasCar.fuelVolume = locale.toDouble(data.value("Объем топлива"));
    newPasCar.transmissionType = data.value("Тип трансмиссии").toStdString();
    newPasCar.engineCapacity = locale.toDouble(data.value("Объем двигателя"));
    newPasCar.numberOfSeats = data.value("Количество сидений").toInt();
    pasCarManager.savePasCar(newPasCar);

    MarkContainerManager markContainerManager;
    ModelContainerManager modelContainerManager;

    modelContainerManager.loadIdsFromFile();
    modelContainerManager.addPassengerCar(model, newPasCar);
    modelContainerManager.saveIdsToFile();
}

void PasCarShowDisplay::loadPasCar(int id, PassengerCar& car) {
    car = pasCarManager.loadPasCar(id);
}

void PasCarShowDisplay::changePasCar(const QMap<QString, QString>& data, string imageName, int id) {
    QLocale locale(QLocale::Russian);

    PassengerCar pasCar;
    pasCar = pasCarManager.loadPasCar(id);

    pasCar.generation = data.value("Поколение").toStdString();
    pasCar.produceDate = data.value("Год производства").toInt();
    pasCar.factoryPrice = data.value("Цена").toInt();
    pasCar.img = imageName;
    pasCar.horsepower = data.value("Лошадиные силы").toInt();
    pasCar.color = data.value("Цвет").toStdString();
    pasCar.fuelVolume = locale.toDouble(data.value("Объем топлива"));
    pasCar.transmissionType = data.value("Тип трансмиссии").toStdString();
    pasCar.engineCapacity = locale.toDouble(data.value("Объем двигателя"));
    pasCar.numberOfSeats = data.value("Количество сидений").toInt();
    pasCarManager.savePasCar(pasCar);
}

void PasCarShowDisplay::deletePasCar(int id) {
    pasCarManager.deletePasCar(id);
}
