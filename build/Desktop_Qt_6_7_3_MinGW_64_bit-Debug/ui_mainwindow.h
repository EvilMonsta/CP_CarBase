/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBoxVehicleType;
    QComboBox *comboBoxMark;
    QComboBox *comboBoxModel;
    QLabel *labelMark;
    QLabel *labelVehicleType;
    QLabel *labelModel;
    QPushButton *showButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
        MainWindow->resize(1200, 700);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBoxVehicleType = new QComboBox(centralwidget);
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->setObjectName("comboBoxVehicleType");
        comboBoxVehicleType->setGeometry(QRect(120, 40, 101, 31));
        comboBoxVehicleType->setStyleSheet(QString::fromUtf8(""));
        comboBoxMark = new QComboBox(centralwidget);
        comboBoxMark->addItem(QString());
        comboBoxMark->setObjectName("comboBoxMark");
        comboBoxMark->setGeometry(QRect(10, 40, 101, 31));
        comboBoxModel = new QComboBox(centralwidget);
        comboBoxModel->addItem(QString());
        comboBoxModel->addItem(QString());
        comboBoxModel->addItem(QString());
        comboBoxModel->setObjectName("comboBoxModel");
        comboBoxModel->setGeometry(QRect(230, 40, 101, 31));
        labelMark = new QLabel(centralwidget);
        labelMark->setObjectName("labelMark");
        labelMark->setGeometry(QRect(10, 20, 71, 16));
        labelVehicleType = new QLabel(centralwidget);
        labelVehicleType->setObjectName("labelVehicleType");
        labelVehicleType->setGeometry(QRect(120, 20, 121, 16));
        labelModel = new QLabel(centralwidget);
        labelModel->setObjectName("labelModel");
        labelModel->setGeometry(QRect(230, 20, 49, 16));
        showButton = new QPushButton(centralwidget);
        showButton->setObjectName("showButton");
        showButton->setGeometry(QRect(300, 210, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 380, 121, 121));
        label->setStyleSheet(QString::fromUtf8("font-size:40px\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBoxVehicleType->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));
        comboBoxVehicleType->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\321\213\320\265", nullptr));
        comboBoxVehicleType->setItemText(2, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273\321\213", nullptr));
        comboBoxVehicleType->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272\320\270", nullptr));

        comboBoxVehicleType->setCurrentText(QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));
        comboBoxMark->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));

        comboBoxModel->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));
        comboBoxModel->setItemText(1, QCoreApplication::translate("MainWindow", "model1", nullptr));
        comboBoxModel->setItemText(2, QCoreApplication::translate("MainWindow", "model2", nullptr));

        labelMark->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260:", nullptr));
        labelVehicleType->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        labelModel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        showButton->setText(QCoreApplication::translate("MainWindow", "SHOW", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
