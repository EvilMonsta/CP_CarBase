#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <truck_show_display.h>
#include <moto_show_display.h>
#include <p_car_show_display.h>
#include <mark_manager.h>
#include <QComboBox>
#include <mark_container_manager.h>


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
    void onVehicleTypeChanged(int id);

    void onMarkChanged(int id);

    void on_showButton_clicked();

private:
    Ui::MainWindow *ui;

    MarkContainerManager markContainerManager;
    MarkManager markManager;
    MotoShowDisplay _motoSD;
    PasCarShowDisplay _pasCarSD;
    TruckShowDisplay  _truckSD;

    void loadMarks();

    void showVehicles();

    void loadModels(int markId, const string &type);

};
#endif // MAINWINDOW_H
