#include "transport_loader.h"
#include <QPixmap>
#include<QHBoxLayout>
#include<QLabel>
#include"moto_manager.h"
#include"p_car_manager.h"
#include"truck_manager.h"
#include<mark_manager.h>
#include<model_manager.h>
// #include <QString>
using namespace std;
void TransportLoader::loadMotorbikeData(const Motorbike &bike, QPushButton *button,int markId,int modelId) {

    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);
    string bikeName = mark.name + " " + model.name + " " + bike.generation;
    QString name = QString::fromStdString(bikeName);
    QString year = QString("Год: %1").arg(bike.produceDate);
    QString price = QString("Цена: %1 $.").arg(bike.factoryPrice);
    QString imagePath = QString::fromStdString("C:/course/CourseProject/resources/images/" + bike.img);
    QWidget *containerWidget = new QWidget(button);
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    QPixmap pixmap(imagePath);
    if (pixmap.width() > pixmap.height()) {
        int x_offset = (pixmap.width() - pixmap.height()) / 2;
        pixmap = pixmap.copy(x_offset, 0, pixmap.height(), pixmap.height());
    } else if (pixmap.height() > pixmap.width()) {
        int y_offset = (pixmap.height() - pixmap.width()) / 2;
        pixmap = pixmap.copy(0, y_offset, pixmap.width(), pixmap.width());
    }
    pixmap = pixmap.scaled(201, 201, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(pixmap);
    imageLabel->setFixedSize(201,201);
    layout->addWidget(imageLabel);
    QLabel *textLabel = new QLabel(
        "<div style='font-family: Arial;'>"
        "    <p style='font-size: 20px; margin-bottom: 20;text-align: center;'>" + name + "</p>"
                 "    <hr style='border: 14px solid #D8BFD8; width: 100%;'>"

        "    <p style='font-size: 16px; margin: 0;line-height: 30px;text-align: left;'>" + year + "</p>"
        "    <p style='font-size: 16px; margin: 0;line-height: 30px;text-align: left;'>" + price + "</p>"
        "</div>");

    layout->addWidget(textLabel);
    containerWidget->setLayout(layout);
    button->setLayout(new QVBoxLayout());
    button->layout()->addWidget(containerWidget);
    button->setText("");
    button->setStyleSheet(
        "QPushButton {"
        "border-right: 2px solid rgb(31, 8, 41);"
        "border-bottom: 2px solid rgb(31, 8, 41);"
        "border-top: 2px solid rgb(145, 110, 133);"
        "border-left: 2px solid rgb(145, 110, 133);"
        "}"
        "QPushButton::hover {"
            "background-color: #3a3a3a;"
        "}"
        "QPushButton::pressed {"
        "border-right: 2px solid rgb(145, 110, 133);"
        "border-bottom: 2px solid rgb(145, 110, 133);"
        "border-top: 2px solid rgb(31, 8, 41);"
        "border-left: 2px solid rgb(31, 8, 41);"
        "}"
        );

}

void TransportLoader::loadPassengerCarData(const PassengerCar &pCar, QPushButton *button,int markId,int modelId) {
    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);
    string pCarName = mark.name + " " + model.name + " " + pCar.generation;
    QString name = QString::fromStdString(pCarName);
    QString year = QString("Год: %1").arg(pCar.produceDate);
    QString price = QString("Цена: %1 $.").arg(pCar.factoryPrice);
    QString imagePath = QString::fromStdString("C:/course/CourseProject/resources/images/" + pCar.img);
    QWidget *containerWidget = new QWidget(button);
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    QPixmap pixmap(imagePath);
    if (pixmap.width() > pixmap.height()) {
        int x_offset = (pixmap.width() - pixmap.height()) / 2;
        pixmap = pixmap.copy(x_offset, 0, pixmap.height(), pixmap.height());
    } else if (pixmap.height() > pixmap.width()) {
        int y_offset = (pixmap.height() - pixmap.width()) / 2;
        pixmap = pixmap.copy(0, y_offset, pixmap.width(), pixmap.width());
    }
    pixmap = pixmap.scaled(201, 201, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(pixmap);
    imageLabel->setFixedSize(201,201);
    imageLabel->setStyleSheet(
        "QLabel {"
        "    border: 6px solid #D8BFD8;"
        "    border-radius: 5px;"
        "}"
        );
    layout->addWidget(imageLabel);

    QLabel *textLabel = new QLabel(
        "<div style='font-family: Arial;'>"
        "    <p style='font-size: 20px; margin-bottom: 20;text-align: center;'>" + name + "</p>"
                 "    <hr style='border: 14px solid #D8BFD8; width: 100%;'>"

                 "    <p style='font-size: 16px; margin: 0;line-height: 30px;text-align: left;'>" + year + "</p>"
                 "    <p style='font-size: 16px; margin: 0;line-height: 30px;text-align: left;'>" + price + "</p>"
                  "</div>");

    layout->addWidget(textLabel);
    containerWidget->setLayout(layout);
    button->setLayout(new QVBoxLayout());
    button->layout()->addWidget(containerWidget);
    button->setText("");
    button->setStyleSheet(
        "QPushButton {"
        "border-right: 2px solid rgb(31, 8, 41);"
        "border-bottom: 2px solid rgb(31, 8, 41);"
        "border-top: 2px solid rgb(145, 110, 133);"
        "border-left: 2px solid rgb(145, 110, 133);"
        "}"
        "QPushButton::hover {"
        "background-color: #3a3a3a;"
        "}"
        "QPushButton::pressed {"
        "border-right: 2px solid rgb(145, 110, 133);"
        "border-bottom: 2px solid rgb(145, 110, 133);"
        "border-top: 2px solid rgb(31, 8, 41);"
        "border-left: 2px solid rgb(31, 8, 41);"
        "}"
        );
}

void TransportLoader::loadTruckData(const Truck &truck, QPushButton *button,int markId,int modelId) {
    MarkManager markManager;
    ModelManager modelManager;
    Mark mark = markManager.loadMark(markId);
    Model model = modelManager.loadModel(modelId);
    string truckName = mark.name + " " + model.name + " " + truck.generation;

    QString name = QString::fromStdString(truckName);
    QString year = QString("Год: %1").arg(truck.produceDate);
    QString price = QString("Цена: %1 $.").arg(truck.factoryPrice);
    QString imagePath = QString::fromStdString("C:/course/CourseProject/resources/images/" + truck.img);

    QWidget *containerWidget = new QWidget(button);
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    QPixmap pixmap(imagePath);
    if (pixmap.width() > pixmap.height()) {
        int x_offset = (pixmap.width() - pixmap.height()) / 2;
        pixmap = pixmap.copy(x_offset, 0, pixmap.height(), pixmap.height());
    } else if (pixmap.height() > pixmap.width()) {
        int y_offset = (pixmap.height() - pixmap.width()) / 2;
        pixmap = pixmap.copy(0, y_offset, pixmap.width(), pixmap.width());
    }
    pixmap = pixmap.scaled(201, 201, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(pixmap);
    imageLabel->setFixedSize(201,201);
    imageLabel->setStyleSheet(
        "QLabel {"
        "    border: 6px solid #D8BFD8;"
        "    border-radius: 5px;"
        "}"
        );
    layout->addWidget(imageLabel);
    QLabel *textLabel = new QLabel(
        "<div style='font-family: Arial;'>"
        "    <p style='font-size: 20px; margin-bottom: 20;text-align: center;'>" + name + "</p>"
                 "    <hr style='border: 14px solid #D8BFD8; width: 100%;'>"

                 "    <p style='font-size: 16px; margin: 0;line-height: 30px;text-align: left;'>" + year + "</p>"
                 "    <p style='font-size: 16px; margin: 0;line-height: 30px;text-align: left;'>" + price + "</p>"
                  "</div>");

    layout->addWidget(textLabel);
    containerWidget->setLayout(layout);
    button->setLayout(new QVBoxLayout());
    button->layout()->addWidget(containerWidget);
    button->setText("");
    button->setStyleSheet(
        "QPushButton {"
        "border-right: 2px solid rgb(31, 8, 41);"
        "border-bottom: 2px solid rgb(31, 8, 41);"
        "border-top: 2px solid rgb(145, 110, 133);"
        "border-left: 2px solid rgb(145, 110, 133);"
        "}"
        "QPushButton::hover {"
        "background-color: #3a3a3a;"
        "}"
        "QPushButton::pressed {"
        "border-right: 2px solid rgb(145, 110, 133);"
        "border-bottom: 2px solid rgb(145, 110, 133);"
        "border-top: 2px solid rgb(31, 8, 41);"
        "border-left: 2px solid rgb(31, 8, 41);"
        "}"
        );
}

void TransportLoader::loadMotorbikeToInfoPage(int id, QLabel *name, QLabel *year, QLabel *price,
                                              QLabel *power, QLabel *color, QLabel* fuel,
                                              QLabel *engine, QLabel *capacity, QLabel *imageLabel) {
    MotoManager motoManager;
    Motorbike bike = motoManager.loadMotorbike(id);
    QString bikeName = QString::fromStdString(bike.mark->name + " " + bike.model->name + " " +bike.generation);
    name->setText(bikeName);
    year->setText(QString::fromStdString("Год начала выпуска: " + to_string(bike.produceDate)));
    price->setText(QString::fromStdString("Фабричная цена: " + to_string(bike.factoryPrice) + "$"));
    power->setText(QString::fromStdString("Мощность: " + to_string(bike.horsepower) + " л.с."));
    color->setText(QString::fromStdString("Цвет: " + bike.color));
    fuel->setText(QString::fromStdString("Объем бака: " + QString::number(bike.fuelVolume, 'g', 7).toStdString() + " л."));
    engine->setText(QString::fromStdString("Тип двигателя: " + bike.engineType));
    capacity->setText(QString::fromStdString("Объем двигателя: " + QString::number(bike.cylinderCapacity, 'g', 7).toStdString() + " см куб."));

    QString imagePath = QString::fromStdString("C:/course/CourseProject/resources/images/" + bike.img);
    QPixmap pixmap(imagePath);
    if (pixmap.width() > pixmap.height()) {
        int x_offset = (pixmap.width() - pixmap.height()) / 2;
        pixmap = pixmap.copy(x_offset, 0, pixmap.height(), pixmap.height());
    } else if (pixmap.height() > pixmap.width()) {
        int y_offset = (pixmap.height() - pixmap.width()) / 2;
        pixmap = pixmap.copy(0, y_offset, pixmap.width(), pixmap.width());
    }
    pixmap = pixmap.scaled(600, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
}

void TransportLoader::loadPassengerCarToInfoPage(int id, QLabel *name, QLabel *year, QLabel *price,
                                                 QLabel *power, QLabel *color, QLabel* fuel,
                                                 QLabel *engine, QLabel *capacity, QLabel *seats, QLabel *imageLabel) {
    PasCarManager pcManager;
    PassengerCar pCar = pcManager.loadPasCar(id);
    QString carName = QString::fromStdString(pCar.mark->name + " " + pCar.model->name + " " +pCar.generation);
    name->setText(carName);
    year->setText(QString::fromStdString("Год начала выпуска: " + to_string(pCar.produceDate)));
    price->setText(QString::fromStdString("Фабричная цена: " + to_string(pCar.factoryPrice) + "$"));
    power->setText(QString::fromStdString("Мощность: " + to_string(pCar.horsepower) + " л.с."));
    color->setText(QString::fromStdString("Цвет: " + pCar.color));
    fuel->setText(QString::fromStdString("Объем бака: " + QString::number(pCar.fuelVolume, 'g', 7).toStdString() + " л."));
    engine->setText(QString::fromStdString("Тип коробки передач: " + pCar.transmissionType));
    capacity->setText(QString::fromStdString("Объем двигателя: " + QString::number(pCar.engineCapacity, 'g', 7).toStdString() + " см куб."));
    seats->setText(QString::fromStdString("Количество сидений: " + to_string(pCar.numberOfSeats)));

    QString imagePath = QString::fromStdString("C:/course/CourseProject/resources/images/" + pCar.img);
    QPixmap pixmap(imagePath);
    if (pixmap.width() > pixmap.height()) {
        int x_offset = (pixmap.width() - pixmap.height()) / 2;
        pixmap = pixmap.copy(x_offset, 0, pixmap.height(), pixmap.height());
    } else if (pixmap.height() > pixmap.width()) {
        int y_offset = (pixmap.height() - pixmap.width()) / 2;
        pixmap = pixmap.copy(0, y_offset, pixmap.width(), pixmap.width());
    }
    pixmap = pixmap.scaled(600, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
}

void TransportLoader::loadTruckToInfoPage(int id, QLabel *name, QLabel *year, QLabel *price,
                                          QLabel *power, QLabel *color, QLabel* fuel,
                                          QLabel *engine, QLabel *capacity,QLabel *load, QLabel *imageLabel) {
    TruckManager truckManager;
    Truck truck = truckManager.loadTruck(id);
    QString truckName = QString::fromStdString(truck.mark->name + " " + truck.model->name + " " +truck.generation);
    name->setText(truckName);
    year->setText(QString::fromStdString("Год начала выпуска: " + to_string(truck.produceDate)));
    price->setText(QString::fromStdString("Фабричная цена: " + to_string(truck.factoryPrice) + "$"));
    power->setText(QString::fromStdString("Мощность: " + to_string(truck.horsepower) + " л.с."));
    color->setText(QString::fromStdString("Цвет: " + truck.color));
    fuel->setText(QString::fromStdString("Объем бака: " + QString::number(truck.fuelVolume, 'g', 7).toStdString() + " л."));
    engine->setText(QString::fromStdString("Тип коробки передач: " + truck.transmissionType));
    capacity->setText(QString::fromStdString("Объем двигателя: " + to_string(truck.engineCapacity) + " см куб."));
    load->setText(QString::fromStdString("Грузоподъемность: " + QString::number(truck.loadCapacity, 'g', 7).toStdString() + " т."));

    QString imagePath = QString::fromStdString("C:/course/CourseProject/resources/images/" + truck.img);
    QPixmap pixmap(imagePath);
    if (pixmap.width() > pixmap.height()) {
        int x_offset = (pixmap.width() - pixmap.height()) / 2;
        pixmap = pixmap.copy(x_offset, 0, pixmap.height(), pixmap.height());
    } else if (pixmap.height() > pixmap.width()) {
        int y_offset = (pixmap.height() - pixmap.width()) / 2;
        pixmap = pixmap.copy(0, y_offset, pixmap.width(), pixmap.width());
    }
    pixmap = pixmap.scaled(600, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
}
