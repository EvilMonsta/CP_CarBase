#include "p_car_show_display.h"
#include <iostream>

PasCarShowDisplay::PasCarShowDisplay() {}

void PasCarShowDisplay::prepareDataAndCreatePasCar(const QMap<QString, QString>& data, int markId, int modelId, string imageName) {
    int id = pasCarManager.getNextPassengerCarId();

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
    newPasCar.fuelVolume = data.value("Объем топлива").toDouble();
    newPasCar.transmissionType = data.value("Тип трансмиссии").toStdString();
    newPasCar.engineCapacity = data.value("Объем двигателя").toDouble();
    newPasCar.numberOfSeats = data.value("Количество сидений").toInt();

    pasCarManager.savePasCar(newPasCar);

    MarkContainerManager markContainerManager;
    ModelContainerManager modelContainerManager;

    markContainerManager.loadIdsFromFile();
    markContainerManager.addPassengerCar(mark, newPasCar);
    markContainerManager.saveIdsToFile();

    modelContainerManager.loadIdsFromFile();
    modelContainerManager.addPassengerCar(model, newPasCar);
    modelContainerManager.saveIdsToFile();
}
