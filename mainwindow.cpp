#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    ui->comboBoxMark->setCurrentIndex(0);
    ui->comboBoxVehicleType->setEnabled(false);
    ui->comboBoxModel->setEnabled(false);
    ui->cancelImageButton->setEnabled(false);

    loadMarks();
    connect(ui->comboBoxMark, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onMarkChanged);

    connect(ui->comboBoxVehicleType, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeChanged);

    connect(ui->comboBoxMarkAddBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onMarkAddBoxChanged);

    connect(ui->comboBoxVehicleTypeAddBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeAddBoxChanged);

    QVBoxLayout *inputLayout = new QVBoxLayout();
    ui->inputGroupBox->setLayout(inputLayout);
    ui->mainGroupBox->setVisible(true);
    ui->addGroupBox->setVisible(false);
    ui->inputGroupBox->setVisible(false);
    ui->selectImageButton->setVisible(false);
    ui->labelImage->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onVehicleTypeAddBoxChanged(int index) {
    QString selectedType = ui->comboBoxVehicleTypeAddBox->itemText(index);
    if (selectedType == "Не выбрано") {
        clearInputFields();
        ui->inputGroupBox->setVisible(false);
        ui->addObjectConfirmed->setEnabled(false);
        ui->selectImageButton->setVisible(false);
        ui->labelImage->setVisible(false);
    } else {
        setupInputFields(selectedType);
        ui->selectImageButton->setVisible(true);
        ui->labelImage->setVisible(true);
    }
    ui->comboBoxVehicleTypeAddBox->setCurrentText(selectedType);
}

void MainWindow::onMarkAddBoxChanged(int index) {
    QString selectedMark = ui->comboBoxMarkAddBox->itemText(index);

    if (selectedMark == "Не выбрано") {
        ui->comboBoxVehicleTypeAddBox->setCurrentIndex(0);
        ui->comboBoxVehicleTypeAddBox->setEnabled(false);
    } else {
        ui->comboBoxVehicleTypeAddBox->setEnabled(true);
    }
    ui->comboBoxMarkAddBox->setCurrentText(selectedMark);
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
        cout << mark.id << ' ' << mark.name << endl;
    }
    for (const Mark &mark : marks) {
        ui->comboBoxMark->addItem(QString::fromStdString(mark.name), mark.id);
        ui->comboBoxMarkAddBox->addItem(QString::fromStdString(mark.name), mark.id);
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

    markContainerManager.loadIdsFromFile();
    markContainerManager.saveIdsToFile();
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

void MainWindow::on_showAddGroupBox_clicked()
{
    ui->comboBoxVehicleTypeAddBox->setCurrentIndex(0);
    ui->comboBoxMarkAddBox->setCurrentIndex(0);
    ui->mainGroupBox->setVisible(false);
    ui->addGroupBox->setVisible(true);
}


void MainWindow::on_addObjectConfirmed_clicked()
{
    if (validateFields()) {
        int selectedMarkId = ui->comboBoxMarkAddBox->currentData().toInt();
        QString vehicleType = ui->comboBoxVehicleTypeAddBox->currentText();

        QMap<QString, QString> data;
        for (auto it = inputFields.begin(); it != inputFields.end(); ++it) {
            data[it.key()] = it.value()->text();
        }
        QString key = "Модель";

        if (inputFields.contains(key)) {
            QString fieldText = inputFields[key]->text();
            string fieldStdString = fieldText.toUtf8().constData();
            qDebug() << "Ключ" << key << "найден: " << QString::fromStdString(fieldStdString);
        } else {
            // Обработка ситуации, если ключ не найден
            qDebug() << "Ключ" << key << "не найден!";
        }

        if(vehicleType == "Мотоцикл"){

        } else if(vehicleType == "Грузовик"){

        } else if(vehicleType == "Легковая"){

        }
        // Здесь вы можете создать объект нужного типа и сохранить его
        // Пример вывода данных для проверки
        qDebug() << "Добавлен объект:";
        qDebug() << "Марка:" << selectedMarkId;
        qDebug() << "Тип:" << vehicleType;
        for (auto it = data.begin(); it != data.end(); ++it) {
            qDebug() << it.key() << ":" << it.value();
        }

        // TODO: Добавьте код для создания объекта и сохранения в файл

        // Очистка полей и возврат на основной интерфейс
        clearInputFields();
        ui->inputGroupBox->setVisible(false);
        ui->addGroupBox->setVisible(false);
        ui->mainGroupBox->setVisible(true);
    }
}

void MainWindow::on_returnToMainPage_clicked()
{
    clearInputFields();
    ui->inputGroupBox->setVisible(false);
    ui->mainGroupBox->setVisible(true);
    ui->addGroupBox->setVisible(false);
    on_cancelImageButton_clicked();
}

void MainWindow::setupInputFields(const QString &type)
{
    QLayout *layout = ui->inputGroupBox->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
    inputFields.clear();

    QStringList fieldNames;
    QMap<QString, QString> fieldTypes;

    if (type == "Мотоцикл") {
        fieldNames << "Модель" << "Поколение" << "Год производства" << "Цена"
                   << "Лошадиные силы" << "Цвет" << "Объем топлива"
                   << "Тип двигателя" << "Объем цилиндра";
        fieldTypes["Модель"] = "string";
        fieldTypes["Поколение"] = "string";
        fieldTypes["Год производства"] = "int";
        fieldTypes["Цена"] = "int";
        fieldTypes["Лошадиные силы"] = "int";
        fieldTypes["Цвет"] = "string";
        fieldTypes["Объем топлива"] = "double";
        fieldTypes["Тип двигателя"] = "string";
        fieldTypes["Объем цилиндра"] = "double";
    }
    else if (type == "Грузовик") {
        fieldNames << "Модель" << "Поколение" << "Год производства" << "Цена"
                   << "Лошадиные силы" << "Цвет" << "Объем топлива"
                   << "Тип трансмиссии" << "Объем двигателя" << "Грузоподъемность";
        fieldTypes["Модель"] = "string";
        fieldTypes["Поколение"] = "string";
        fieldTypes["Год производства"] = "int";
        fieldTypes["Цена"] = "int";
        fieldTypes["Лошадиные силы"] = "int";
        fieldTypes["Цвет"] = "string";
        fieldTypes["Объем топлива"] = "double";
        fieldTypes["Тип трансмиссии"] = "string";
        fieldTypes["Объем двигателя"] = "double";
        fieldTypes["Грузоподъемность"] = "double";
    }
    else if (type == "Легковая") {
        fieldNames << "Модель" << "Поколение" << "Год производства" << "Цена"
                   << "Лошадиные силы" << "Цвет" << "Объем топлива"
                   << "Тип трансмиссии" << "Объем двигателя" << "Количество сидений";
        fieldTypes["Модель"] = "string";
        fieldTypes["Поколение"] = "string";
        fieldTypes["Год производства"] = "int";
        fieldTypes["Цена"] = "int";
        fieldTypes["Лошадиные силы"] = "int";
        fieldTypes["Цвет"] = "string";
        fieldTypes["Объем топлива"] = "double";
        fieldTypes["Тип трансмиссии"] = "string";
        fieldTypes["Объем двигателя"] = "double";
        fieldTypes["Количество сидений"] = "int";
    } else {
        clearInputFields();
        ui->inputGroupBox->setVisible(false);
    }

    for (const QString &field : fieldNames) {
        QLineEdit *lineEdit = new QLineEdit(ui->inputGroupBox);
        lineEdit->setPlaceholderText(field);
        lineEdit->setFixedSize(250, 30);

        QFont font("Arial", 10, QFont::Bold);
        lineEdit->setFont(font);

        if (fieldTypes.contains(field)) {
            QString typeStr = fieldTypes[field];
            if (typeStr == "int") {
                lineEdit->setValidator(new QIntValidator(0, 1000000, lineEdit));
            }
            else if (typeStr == "double") {
                lineEdit->setValidator(new QDoubleValidator(0, 1000000, 2, lineEdit));
            }
        }

        inputFields[field] = lineEdit;
        layout->addWidget(lineEdit);
    }

    ui->inputGroupBox->setVisible(!fieldNames.isEmpty());
}

bool MainWindow::validateFields()
{
    for (auto it = inputFields.begin(); it != inputFields.end(); ++it) {
        QString fieldName = it.key();
        QLineEdit *lineEdit = it.value();

        if (lineEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Ошибка", QString("Поле \"%1\" не должно быть пустым").arg(fieldName));
            return false;
        }

        if (!lineEdit->hasAcceptableInput()) {
            QMessageBox::warning(this, "Ошибка", QString("Поле \"%1\" содержит некорректное значение").arg(fieldName));
            return false;
        }
    }
    return true;
}

void MainWindow::clearInputFields()
{
    for (auto it = inputFields.begin(); it != inputFields.end(); ++it) {
        it.value()->clear();
    }
}

void MainWindow::on_selectImageButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Выберите изображение", "", "Images (*.png *.jpg *.jpeg)");

    if (!imagePath.isEmpty()) {
        QString targetFolder = "C:/course/CourseProject/resources/images";
        QDir().mkpath(targetFolder);

        QString fileName = QFileInfo(imagePath).fileName();
        QString targetPath = targetFolder + "/" + fileName;
        selectedImagePath = fileName;

        if (!selectedImagePath.isEmpty() && QFile::exists(targetFolder + "/" + selectedImagePath)) {
            QFile::remove(targetFolder + "/" + selectedImagePath);
        }

        if (QFile::copy(imagePath, targetPath)) {
            selectedImagePath = fileName;

            QPixmap pixmap(targetPath);
            QIcon icon(pixmap);
            ui->selectImageButton->setIcon(icon);
            ui->selectImageButton->setIconSize(ui->selectImageButton->size());
            ui->selectImageButton->setText("");
            ui->imageLabelName->setText(fileName);
            ui->imageLabelName->setAlignment(Qt::AlignCenter);

            ui->addObjectConfirmed->setEnabled(true);
            ui->cancelImageButton->setEnabled(true);
        }
    }
}


void MainWindow::on_cancelImageButton_clicked()
{
    if (!selectedImagePath.isEmpty()) {
        QString targetFolder = "C:/course/CourseProject/resources/images";
        QString targetPath = targetFolder + "/" + selectedImagePath;

        if (QFile::exists(targetPath)) {
            QFile::remove(targetPath);
        }

        selectedImagePath.clear();
        ui->selectImageButton->setIcon(QIcon());
        ui->selectImageButton->setText("+img");
        ui->imageLabelName->setText("Файл не выбран");
        ui->imageLabelName->setAlignment(Qt::AlignCenter);

        ui->addObjectConfirmed->setEnabled(false);
        ui->cancelImageButton->setEnabled(false);
    }
}

