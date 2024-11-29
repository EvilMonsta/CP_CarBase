#ifndef LOAD_TRANSPORT_DATA_H
#define LOAD_TRANSPORT_DATA_H
#include <QPushButton>
#include <QPixmap>
#include <QString>

template <typename T>
void loadTransportData(const T &transport, QPushButton *button) {
    QString name = QString::fromStdString(transport.color);
    QString year = QString("Год: %1").arg(transport.produceDate);
    QString price = QString("Цена: %1 руб.").arg(transport.factoryPrice);
    QString imagePath = QString::fromStdString(transport.img);

    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        pixmap = pixmap.scaled(201, 201, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        button->setIcon(QIcon(pixmap));
        button->setIconSize(QSize(201, 201));
    }

    button->setText(name + "\n" + year + "\n" + price);
}
#endif // LOAD_TRANSPORT_DATA_H
