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
#include <QLineEdit>
#include <QValidator>
#include <QMap>
#include <QVBoxLayout>

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

    void onVehicleTypeAddBoxChanged(int id);

    void onMarkAddBoxChanged(int id);

    void onAddMarkFieldChanged();

    void on_showButton_clicked();

    void on_addObjectConfirmed_clicked();

    void on_showAddGroupBox_clicked();

    void on_returnToMainPage_clicked();

    void on_selectImageButton_clicked();

    void on_cancelImageButton_clicked();

    void on_addMarkButton_clicked();

private:
    Ui::MainWindow *ui;

    MarkContainerManager markContainerManager;

    MarkManager markManager;

    MotoShowDisplay _motoSD;

    PasCarShowDisplay _pasCarSD;

    TruckShowDisplay  _truckSD;

    QMap<QString, QLineEdit*> inputFields;

    QLineEdit *imageLineEdit;

    QString selectedImagePath;

    void loadMarks();

    void clearMarks();

    void showVehicles();

    void setupInputFields(const QString &type);

    bool validateFields();

    void clearInputFields();

    void loadModels(int markId, const string &type);

};
#endif // MAINWINDOW_H
