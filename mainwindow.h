#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <truck_show_display.h>
#include <moto_show_display.h>
#include <p_car_show_display.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButton1Clicked();  // Слот для кнопки 1
    void onButton2Clicked();  // Слот для кнопки 2
    void onButton3Clicked();  // Слот для кнопки 3
private:
    Ui::MainWindow *ui;

    MotoShowDisplay _motoSD;
    PasCarShowDisplay _pasCarSD;
    TruckShowDisplay  _truckSD;

};
#endif // MAINWINDOW_H
