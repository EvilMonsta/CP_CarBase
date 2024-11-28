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
#include <model_container_manager.h>
#include <QLineEdit>
#include <QValidator>
#include <QMap>
#include <QVBoxLayout>
#include "paginator.h"

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

    void onModelChanged(int id);

    void onVehicleTypeAddBoxChanged(int id);

    void onModelAddBoxChanged(int id);

    void onMarkAddBoxChanged(int id);

    void markSelectComboBoxChanged(int index);

    void typeSelectComboBoxChanged(int index);

    void onAddMarkFieldChanged();

    void on_showButton_clicked();

    void on_addObjectConfirmed_clicked();

    void on_showAddGroupBox_clicked();

    void on_returnToMainPage_clicked();

    void on_selectImageButton_clicked();

    void on_cancelImageButton_clicked();

    void on_addMarkButton_clicked();

    void on_addModelButton_clicked();

    void on_returnToAddPage_clicked();

    void on_returToMainPageFromModel_clicked();

    void on_addNewModelButton_clicked();

    void updateGrid(const vector<int> &pageIds);

    void updatePaginationControls(int currentPage, int totalPages);

    void fillGrid(vector<int> cells);


private:
    Ui::MainWindow *ui;

    MarkContainerManager markContainerManager;

    ModelContainerManager modelContainerManager;

    MarkManager markManager;

    ModelManager modelManager;

    MotoShowDisplay _motoSD;

    PasCarShowDisplay _pasCarSD;

    TruckShowDisplay  _truckSD;

    QMap<QString, QLineEdit*> inputFields;

    QLineEdit *imageLineEdit;

    Paginator *paginator;

    QString selectedImagePath;

    void loadMarks();

    void clearMarks();

    void clearModels();

    void showVehicles();

    void setupInputFields(const QString &type);

    bool validateFields();

    void clearInputFields();

    void loadModels(int markId, const string &type, QComboBox *box);

};
#endif // MAINWINDOW_H
