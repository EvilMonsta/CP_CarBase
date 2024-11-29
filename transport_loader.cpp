#include "transport_loader.h"
#include <QPixmap>
#include<QHBoxLayout>
#include<QLabel>
void TransportLoader::loadMotorbikeData(const Motorbike &bike, QPushButton *button) {
    string bikeName = bike.mark->name + " " + bike.model->name + " " + bike.generation;
    QString name = QString::fromStdString(bikeName);
    QString year = QString("Год: %1").arg(bike.produceDate);
    QString price = QString("Цена: %1 руб.").arg(bike.factoryPrice);
    QString imagePath = QString::fromStdString("C:/Users/Roman Ambrosevich/Downloads/" + bike.img);
    QWidget *containerWidget = new QWidget(button);
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
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
    layout->addWidget(imageLabel);

    QLabel *textLabel = new QLabel(name + "\n" + year + "\n" + price);
    layout->addWidget(textLabel);

    button->setLayout(layout);
    button->setText("");
}

void TransportLoader::loadPassengerCarData(const PassengerCar &pCar, QPushButton *button) {

    string pCarName = pCar.mark->name + " " + pCar.model->name + " " + pCar.generation;

    QString name = QString::fromStdString(pCarName);
    QString year = QString("Год: %1").arg(pCar.produceDate);
    QString price = QString("Цена: %1 руб.").arg(pCar.factoryPrice);
    QString imagePath = QString::fromStdString("C:/Users/Roman Ambrosevich/Downloads/" + pCar.img);

    QWidget *containerWidget = new QWidget(button);
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
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
    layout->addWidget(imageLabel);

    QLabel *textLabel = new QLabel(name + "\n" + year + "\n" + price);
    layout->addWidget(textLabel);

    button->setLayout(layout);
    button->setText("");
}

void TransportLoader::loadTruckData(const Truck &truck, QPushButton *button) {
    string truckName = truck.mark->name + " " + truck.model->name + " " + truck.generation;

    QString name = QString::fromStdString(truckName);
    QString year = QString("Год: %1").arg(truck.produceDate);
    QString price = QString("Цена: %1 руб.").arg(truck.factoryPrice);
    QString imagePath = QString::fromStdString("C:/Users/Roman Ambrosevich/Downloads/" + truck.img);

    QWidget *containerWidget = new QWidget(button);
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
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
    layout->addWidget(imageLabel);

    QLabel *textLabel = new QLabel(name + "\n" + year + "\n" + price);
    layout->addWidget(textLabel);

    button->setLayout(layout);
    button->setText("");
}
