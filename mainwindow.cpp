#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBoxMark->setCurrentIndex(0);
    ui->comboBoxVehicleType->setEnabled(false);
    ui->comboBoxModel->setEnabled(false);

    loadMarks();
    connect(ui->comboBoxMark, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onMarkChanged);

    connect(ui->comboBoxVehicleType, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onVehicleTypeChanged(int index) {
    QString selectedType = ui->comboBoxVehicleType->itemText(index);
    if (selectedType == "Любые") {
        ui->comboBoxModel->setCurrentIndex(0);
        ui->comboBoxModel->setEnabled(false);
    } else {
        if (ui->comboBoxMark->currentText() != "Любые") {
            ui->comboBoxModel->setEnabled(true);
        }
    }
    ui->comboBoxVehicleType->setCurrentText(selectedType);
}

void MainWindow::onMarkChanged(int index) {
    QString selectedMark = ui->comboBoxMark->itemText(index);

    if (selectedMark == "Любые") {
        ui->comboBoxVehicleType->setCurrentIndex(0);
        ui->comboBoxVehicleType->setEnabled(false);
        ui->comboBoxModel->setCurrentIndex(0);
        ui->comboBoxModel->setEnabled(false);
    } else {
        ui->comboBoxVehicleType->setEnabled(true);
    }
    ui->comboBoxMark->setCurrentText(selectedMark);
}

void MainWindow::loadMarks() {
    vector<Mark> marks = markManager.getMarks();
    for (const Mark &mark : marks) {
        ui->comboBoxMark->addItem(QString::fromStdString(mark.name), mark.id);
    }
}

void MainWindow::loadModels(int markId, const string &type){
    //функция будет пееределана
    ui->comboBoxModel->clear();
}

void MainWindow::on_showButton_clicked()
{
    showVehicles();
}

void MainWindow::showVehicles() {
    QString selectedMark = ui->comboBoxMark->currentText();

    MarkContainerManager markContainerManager;
    MotoManager motoM;
    Mark kawasaki(50, "Kawasaki");
    Mark yamaha(40,"YAMAHA");
    Motorbike bike;
    bike = motoM.loadMotorbike(1);
    markContainerManager.addMotorbike(kawasaki,bike);
    bike = motoM.loadMotorbike(3);
    markContainerManager.addMotorbike(yamaha,bike);
    bike = motoM.loadMotorbike(5);
    markContainerManager.addMotorbike(yamaha,bike);

    if (selectedMark == "Любые") {
        auto allVehicleIds = markContainerManager.getAllVehicleIds();
        //временно----
        QStringList idList;
        for (int id : allVehicleIds) {
            idList << QString::number(id);
        }

        QString formattedIds = idList.join(", ");
        ui->label->setText(formattedIds);

        //временно----
    } else {
        int selectedMarkId = ui->comboBoxMark->currentData().toInt();
        auto vehicleIds = markContainerManager.getVehicleIdsByMark(selectedMarkId);
    //временно----
        QStringList idList;
        for (int id : vehicleIds) {
            idList << QString::number(id);
        }

        QString formattedIds = idList.join(", ");
        ui->label->setText(formattedIds);
        //временно----
    }
}
