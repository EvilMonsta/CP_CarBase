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
#include "text_validation_exception.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), paginator(new Paginator(9, this)) {
    ui->setupUi(this);

    ui->comboBoxMark->setCurrentIndex(0);
    ui->comboBoxVehicleType->setEnabled(false);
    ui->comboBoxModel->setEnabled(false);
    ui->typeSelectComboBox->setEnabled(false);
    ui->cancelImageButton->setEnabled(false);
    ui->newModelField->setEnabled(false);
    ui->comboBoxModelAddBox->setEnabled(false);

    loadMarks();

    connect(ui->comboBoxMark, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onMarkChanged);

    connect(ui->comboBoxVehicleType, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeChanged);

    connect(ui->comboBoxMarkAddBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onMarkAddBoxChanged);

    connect(ui->comboBoxVehicleTypeAddBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeAddBoxChanged);
    connect(ui->comboBoxModel, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onModelChanged);
    connect(ui->comboBoxModelAddBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onModelAddBoxChanged);
    connect(ui->markSelectComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::markSelectComboBoxChanged);
    connect(ui->typeSelectComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::typeSelectComboBoxChanged);
    connect(ui->addMarkField, &QLineEdit::textChanged, this, &MainWindow::onAddMarkFieldChanged);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(paginator, &Paginator::pageChanged, this, &MainWindow::updateGrid);
    connect(paginator, &Paginator::pageInfoUpdated, this, [this](int currentPage, int totalPages) {
        updatePaginationControls(currentPage, totalPages);
    });
    QVBoxLayout *inputLayout = new QVBoxLayout();
    ui->inputGroupBox->setLayout(inputLayout);
    ui->mainGroupBox->setVisible(true);
    ui->addGroupBox->setVisible(false);
    ui->addModelGroupBox->setVisible(false);
    ui->inputGroupBox->setVisible(false);
    ui->selectImageButton->setVisible(false);
    ui->labelImage->setVisible(false);
    markContainerManager.loadIdsFromFile();

        connect(ui->prevPageButton, &QPushButton::clicked, paginator, &Paginator::prevPage);
        connect(ui->nextPageButton, &QPushButton::clicked, paginator, &Paginator::nextPage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillGrid(int cellsNumber) {
    std::vector<QString> transportData;
    for (int i = 1; i <= cellsNumber; ++i) {
        transportData.push_back(QString("Транспорт %1").arg(i));
    }
    paginator->setData(transportData);
}

void MainWindow::markSelectComboBoxChanged(int index) {
    QString selectedMark = ui->markSelectComboBox->itemText(index);

    if (selectedMark == "Не выбрано") {
        ui->typeSelectComboBox->setCurrentIndex(0);
        ui->typeSelectComboBox->setEnabled(false);
    } else {
        ui->typeSelectComboBox->setEnabled(true);
    }
}

void MainWindow::typeSelectComboBoxChanged(int index) {
    QString selectedType = ui->typeSelectComboBox->itemText(index);

    if (selectedType == "Не выбрано") {
        ui->newModelField->setEnabled(false);
    } else if(selectedType == "Легковые"){
        ui->newModelField->setEnabled(true);
    } else {
        ui->newModelField->setEnabled(true);
    }
}

void MainWindow::onVehicleTypeAddBoxChanged(int index) {
    QString selectedType = ui->comboBoxVehicleTypeAddBox->itemText(index);
    int selectedMarkId = ui->comboBoxMarkAddBox->currentData().toInt();

    if (selectedType == "Не выбрано") {
        ui->comboBoxModelAddBox->clear();
        ui->comboBoxModelAddBox->setEnabled(false);
    } else {
        clearModels();
        loadModels(selectedMarkId,selectedType.toStdString(),ui->comboBoxModelAddBox);
        ui->comboBoxModelAddBox->setEnabled(true);
    }
    ui->comboBoxVehicleTypeAddBox->setCurrentText(selectedType);
}

void MainWindow::onMarkAddBoxChanged(int index) {
    QString selectedMark = ui->comboBoxMarkAddBox->itemText(index);

    if (selectedMark == "Не выбрано") {
        ui->comboBoxVehicleTypeAddBox->setCurrentIndex(0);
        ui->comboBoxVehicleTypeAddBox->setEnabled(false);
    } else {
        ui->comboBoxVehicleTypeAddBox->setCurrentIndex(0);
        ui->comboBoxVehicleTypeAddBox->setEnabled(true);
    }
    ui->comboBoxMarkAddBox->setCurrentText(selectedMark);
}

void MainWindow::onModelAddBoxChanged(int index) {
    QString selectedModel= ui->comboBoxModelAddBox->itemText(index);
    QString selectedType = ui->comboBoxVehicleTypeAddBox->currentText();
    if (selectedModel == "Не выбрано") {
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
    ui->comboBoxModelAddBox->setCurrentText(selectedModel);
}

void MainWindow::onVehicleTypeChanged(int index) {
    QString selectedType = ui->comboBoxVehicleType->itemText(index);
    int selectedMarkId = ui->comboBoxMark->currentData().toInt();

    if (selectedType == "Любые") {
        ui->comboBoxModel->setCurrentIndex(0);
        ui->comboBoxModel->setEnabled(false);
    } else {
            ui->comboBoxModel->setEnabled(true);
            clearModels();

            loadModels(selectedMarkId,selectedType.toStdString(),ui->comboBoxModel);
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
        ui->comboBoxVehicleType->setCurrentIndex(0);
        ui->comboBoxVehicleType->setEnabled(true);
    }
    ui->comboBoxMark->setCurrentText(selectedMark);
}

void MainWindow::onModelChanged(int index) {
    QString selectedModel = ui->comboBoxModel->itemText(index);
    QString selectedType = ui->comboBoxVehicleTypeAddBox->currentText();

    ui->comboBoxModel->setCurrentText(selectedModel);

}

void MainWindow::loadMarks() {
    vector<Mark> marks = markManager.getMarks();
    for (const Mark &mark : marks) {
        ui->comboBoxMark->addItem(QString::fromStdString(mark.name), mark.id);
        ui->comboBoxMarkAddBox->addItem(QString::fromStdString(mark.name), mark.id);
        ui->markSelectComboBox->addItem(QString::fromStdString(mark.name), mark.id);
    }
}

void MainWindow::clearMarks() {
    ui->comboBoxMark->clear();
    ui->comboBoxMarkAddBox->clear();
    ui->comboBoxMark->addItem(QString::fromStdString("Любые"),0);
    ui->comboBoxMarkAddBox->addItem(QString::fromStdString("Не выбрано"),0);

}

void MainWindow::clearModels() {
    ui->comboBoxModel->clear();
    ui->comboBoxModelAddBox->clear();
    ui->comboBoxModel->addItem(QString::fromStdString("Любые"),0);
    ui->comboBoxModelAddBox->addItem(QString::fromStdString("Не выбрано"),0);

}

void MainWindow::loadModels(int markId, const string &type, QComboBox *box){
    vector<int> ids;
    if(type == "Легковая"){
        ids = markContainerManager.getPassengerCarModelsIds(markId);
    } else if(type == "Грузовик") {
        ids = markContainerManager.getTruckModelsIds(markId);
    } else if(type == "Мотоцикл") {
        ids = markContainerManager.getMotorbikeModelsIds(markId);
    }
    vector<Model> models = modelManager.getModels(ids);

    for(const Model &model: models) {
        box->addItem(QString::fromStdString(model.name), model.id);
    }
}

void MainWindow::on_showButton_clicked()
{
    showVehicles();
}

void MainWindow::showVehicles() {
    QString selectedMark = ui->comboBoxMark->currentText();
    QString selectedType = ui->comboBoxVehicleType->currentText();
    modelContainerManager.loadIdsFromFile();

    if (selectedMark == "Любые") {
        auto allModels = modelContainerManager.getAllVehicleIds();
        QStringList idList;
        for (int id : allModels) {
            idList << QString::number(id);
        }

        QString formattedIds = idList.join(", ");
        ui->label->setText(formattedIds);
        //временно----
    } else {
        int selectedMarkId = ui->comboBoxMark->currentData().toInt();
        QStringList idList;
        vector<int> ids;
        qDebug() << selectedType << selectedMarkId;
        if(selectedType == "Легковая") {
            auto modelIds = markContainerManager.getPassengerCarModelsIds(selectedMarkId);
            for (int id : modelIds) {
                qDebug() << id << "l";
                ids = modelContainerManager.getPassengerCarIds(id);
                for (int mId : ids) idList << QString::number(mId);
            }
        } else if(selectedType == "Грузовик") {
            auto modelIds = markContainerManager.getTruckModelsIds(selectedMarkId);
            for (int id : modelIds) {
                qDebug() << id << "g";
                ids = modelContainerManager.getTruckIds(id);
                for (int mId : ids) idList << QString::number(mId);
            }
        } else if(selectedType == "Мотоцикл") {
            auto modelIds = markContainerManager.getMotorbikeModelsIds(selectedMarkId);
            for (int id : modelIds) {
                qDebug() << id << "m";
                ids = modelContainerManager.getMotorbikeIds(id);
                for (int mId : ids) idList << QString::number(mId);
            }
        } else {
            auto modelIds = markContainerManager.getModelsIdsByMark(selectedMarkId);
            for (int id : modelIds) {
                qDebug() << id << "all";
                ids = modelContainerManager.getVehicleIdsByModel(id);
                for (int mId : ids) idList << QString::number(mId);
            }
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
        int selectedModelId = ui->comboBoxModelAddBox->currentData().toInt();
        QString vehicleType = ui->comboBoxVehicleTypeAddBox->currentText();

        QMap<QString, QString> data;
        for (auto it = inputFields.begin(); it != inputFields.end(); ++it) {
            data[it.key()] = it.value()->text();
        }

        if(vehicleType == "Мотоцикл"){
            _motoSD.prepareDataAndCreateBike(data,selectedMarkId, selectedModelId, ui->imageLabelName->text().toStdString());
        } else if(vehicleType == "Грузовик"){
            _truckSD.prepareDataAndCreateTruck(data,selectedMarkId, selectedModelId, ui->imageLabelName->text().toStdString());
        } else if(vehicleType == "Легковая"){
            _pasCarSD.prepareDataAndCreatePasCar(data,selectedMarkId, selectedModelId, ui->imageLabelName->text().toStdString());
        }
        QMessageBox messageBox(this);
        messageBox.setWindowTitle("Успешно добавлено!");
        messageBox.setText("Желаете продолжить добавление транспорта?");
        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        messageBox.setDefaultButton(QMessageBox::No);

        messageBox.setWindowFlags(messageBox.windowFlags() & ~Qt::WindowCloseButtonHint);
        messageBox.setFixedSize(300, 150);

        int reply = messageBox.exec();

        if (reply == QMessageBox::Yes) {
            clearInputFields();
            on_cancelImageButton_clicked();
        } else {
            on_returnToMainPage_clicked();
        }

    }

}

void MainWindow::on_returnToMainPage_clicked()
{
    markContainerManager.loadIdsFromFile();
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
        fieldNames << "Поколение" << "Год производства" << "Цена"
                   << "Лошадиные силы" << "Цвет" << "Объем топлива"
                   << "Тип двигателя" << "Объем цилиндра";
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
        fieldNames << "Поколение" << "Год производства" << "Цена"
                   << "Лошадиные силы" << "Цвет" << "Объем топлива"
                   << "Тип трансмиссии" << "Объем двигателя" << "Грузоподъемность";
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
        fieldNames << "Поколение" << "Год производства" << "Цена"
                   << "Лошадиные силы" << "Цвет" << "Объем топлива"
                   << "Тип трансмиссии" << "Объем двигателя" << "Количество сидений";
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
                lineEdit->setValidator(new QDoubleValidator(0, 1000000, 7, lineEdit));
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
        try {
            if (lineEdit->validator() == nullptr) {
                TextValidationException::validate(lineEdit->text(), this);
            }
        } catch (const TextValidationException &ex) {
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

void MainWindow::onAddMarkFieldChanged() {
    ui->addMarkButton->setEnabled(!ui->addMarkField->text().isEmpty());
}


void MainWindow::on_addMarkButton_clicked() {
    string markName = ui->addMarkField->text().toStdString();

    try {
        if (ui->addMarkField->validator() == nullptr) {
            TextValidationException::validate(ui->addMarkField->text(), this);
        }
    } catch (const TextValidationException &ex) {
        return;
    }

    try {
        Mark newMark = markManager.addMark(markName);

        markManager.saveMark(newMark);

        QMessageBox::information(this, "Успех", "Марка добавлена: " + QString::fromStdString(markName));

        ui->addMarkField->clear();

        clearMarks();

        loadMarks();
    } catch (const DuplicateMarkException&) {
        qDebug() << "error";
    }
}




void MainWindow::on_returnToAddPage_clicked()
{
    ui->addModelGroupBox->setVisible(false);
    ui->addGroupBox->setVisible(true);
    clearMarks();
    loadMarks();
}


void MainWindow::on_returToMainPageFromModel_clicked()
{
    ui->mainGroupBox->setVisible(true);
    ui->addModelGroupBox->setVisible(false);
}


void MainWindow::on_addNewModelButton_clicked()
{
    string modelName = ui->newModelField->text().toStdString();

    try {
        if (ui->newModelField->validator() == nullptr) {
            TextValidationException::validate(ui->newModelField->text(), this);
        }
    } catch (const TextValidationException &ex) {
        return;
    }

    try {
        int selectedMarkId = ui->markSelectComboBox->currentData().toInt();

        string vehicleType = ui->typeSelectComboBox->currentText().toStdString();

        Model newModel = modelManager.addModel(modelName,selectedMarkId);

        markContainerManager.loadIdsFromFile();
        markContainerManager.addModel(selectedMarkId, newModel, vehicleType);
        markContainerManager.saveIdsToFile();

        modelManager.saveModel(newModel);

        QMessageBox::information(this, "Успех", "Модель добавлена: " + QString::fromStdString(modelName));

        ui->newModelField->clear();

        clearModels();

    } catch (const DuplicateModelException&) {
        qDebug() << "error";
    }
}


void MainWindow::on_addModelButton_clicked()
{
    clearModels();
    clearMarks();
    ui->addModelGroupBox->setVisible(true);
    ui->addGroupBox->setVisible(false);
}

void MainWindow::updateGrid(const std::vector<QString> &pageData) {
    // Очистка старых виджетов
    QLayoutItem *item;
    while ((item = ui->vehicleGrid->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Заполнение новыми данными
    int row = 0, col = 0;
    for (const auto &transport : pageData) {
        QPushButton *button = new QPushButton(transport, this);
        button->setFixedSize(501, 201);

        ui->vehicleGrid->addWidget(button, row, col);

        if (++col == 3) { // 3 кнопки в строке
            col = 0;
            ++row;
        }
    }
    for(int i = 0;i < 9-int(pageData.size());i ++) {
        QLabel *label = new QLabel();
        label->setStyleSheet("background-color:white");
        ui->vehicleGrid->addWidget(label, row, col);
        if (++col == 3) { // 3 кнопки в строке
            col = 0;
            ++row;
        }
    }
}


void MainWindow::updatePaginationControls(int currentPage, int totalPages) {
    ui->pageLabel->setText(QString("Page %1 of %2").arg(currentPage).arg(totalPages));
    ui->prevPageButton->setEnabled(currentPage > 1);
    ui->nextPageButton->setEnabled(currentPage < totalPages);
}
