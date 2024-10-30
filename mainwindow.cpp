#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onButton1Clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::onButton2Clicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::onButton3Clicked);
    ui->comboBoxVehicleType->addItem("Грузовики");
    ui->comboBoxVehicleType->addItem("Легковые");
    ui->comboBoxVehicleType->addItem("Мотоциклы");
    connect(ui->comboBoxVehicleType, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeChanged);
    loadMarks();  // Загружаем марки из MarkManager
    connect(ui->comboBoxMark, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onMarkChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onVehicleTypeChanged(int index) {
    QString selectedType = ui->comboBoxVehicleType->itemText(index);
    ui->comboBoxVehicleType->setCurrentText(selectedType);  // Отображаем выбранный тип
}

void MainWindow::onMarkChanged(int index) {
    QString selectedBrand = ui->comboBoxMark->itemText(index);
    ui->comboBoxMark->setCurrentText(selectedBrand);  // Отображаем выбранную марку
}

void MainWindow::loadMarks() {
    vector<Mark> marks = markManager.getMarks();
    for (const Mark &mark : marks) {
        ui->comboBoxMark->addItem(QString::fromStdString(mark.name));  // Добавляем название марки в ComboBox
    }
}

void MainWindow::onButton1Clicked()
{
    // _motoSD.PrintMotorbikesIds();
    // _pasCarSD.PrintPasCarsIds();
    // _truckSD.PrintTrucksIds();
    _truckSD.printData(2);
    _pasCarSD.printData(1);
    _motoSD.printData(5);
}

void MainWindow::onButton2Clicked()
{
}

void MainWindow::onButton3Clicked()
{
}
