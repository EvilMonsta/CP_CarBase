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
    ui->comboBoxMark->setEnabled(false);
    ui->comboBoxModel->setEnabled(false);
    ui->typeSelectComboBox->setEnabled(false);
    ui->cancelImageButton->setEnabled(false);
    ui->newModelField->setEnabled(false);
    ui->comboBoxModelAddBox->setEnabled(false);
    ui->centralwidget->setFixedSize(1920,1080);
    ui->pageLabel->setAlignment(Qt::AlignCenter);
    ui->showButton->setEnabled(false);
    ui->infoGroupBox->setVisible(false);
    ui->prevPageButton->setVisible(false);
    ui->nextPageButton->setVisible(false);
    ui->pageLabel->setVisible(false);
    QVBoxLayout *inputLayout = new QVBoxLayout();
    ui->inputGroupBox->setLayout(inputLayout);
    ui->mainGroupBox->setVisible(true);
    ui->addGroupBox->setVisible(false);
    ui->addModelGroupBox->setVisible(false);
    ui->inputGroupBox->setVisible(false);
    ui->selectImageButton->setVisible(false);
    ui->labelImage->setVisible(false);
    markContainerManager.loadIdsFromFile();
    ui->label->setVisible(false);
    loadMarks();

    connect(ui->comboBoxModelAddBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onModelAddBoxChanged);
    connect(ui->addMarkField, &QLineEdit::textChanged, this, &MainWindow::onAddMarkFieldChanged);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(paginator, &Paginator::pageChanged, this, &MainWindow::updateGrid);
    connect(paginator, &Paginator::pageInfoUpdated, this, [this](int currentPage, int totalPages) {
        updatePaginationControls(currentPage, totalPages);
    });
    connect(ui->prevPageButton, &QPushButton::clicked, paginator, &Paginator::prevPage);
    connect(ui->nextPageButton, &QPushButton::clicked, paginator, &Paginator::nextPage);

    comboBoxController = new ComboBoxController(ui->comboBoxVehicleType, ui->comboBoxMark, ui->comboBoxModel,
        ui->showButton, ui->markSelectComboBox, ui->typeSelectComboBox, ui->newModelField,
        ui->comboBoxVehicleTypeAddBox, ui->comboBoxMarkAddBox, ui->comboBoxModelAddBox, this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->markSelectComboBox->clear();
    ui->markSelectComboBox->addItem(QString::fromStdString("Не выбрано"),0);
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
    QString selectedMark = ui->comboBoxMark->currentText();
    QString selectedType = ui->comboBoxVehicleType->currentText();
    int selectedMarkId = ui->comboBoxMark->currentData().toInt();
    int selectedModelId = ui->comboBoxModel->currentData().toInt();
    QString selectedModel = ui->comboBoxModel->currentText();

    modelContainerManager.loadIdsFromFile();

    vector<int> modelsIds;
    vector<int> ids;
    vector<int> tempIds;
    bool isOneModel = false;

    if(selectedType == "Легковая" && selectedMark != "Любые") {
        if(selectedModel=="Любые") {
            modelsIds = markContainerManager.getPassengerCarModelsIds(selectedMarkId);
            isOneModel = false;
        } else {
            isOneModel = true;
            ids = modelContainerManager.getPassengerCarIds(selectedModelId);
        }
    } else if(selectedType == "Грузовик" && selectedMark != "Любые") {
        if(selectedModel=="Любые") {
            modelsIds = markContainerManager.getTruckModelsIds(selectedMarkId);
            isOneModel = false;
        } else {
            isOneModel = true;
            ids = modelContainerManager.getTruckIds(selectedModelId);
        }
    } else if(selectedType == "Мотоцикл" && selectedMark != "Любые") {
        if(selectedModel=="Любые") {
            modelsIds = markContainerManager.getMotorbikeModelsIds(selectedMarkId);
            isOneModel = false;
        } else {
            isOneModel = true;
            ids = modelContainerManager.getMotorbikeIds(selectedModelId);
        }
    } else if(selectedType == "Легковая" && selectedMark == "Любые") {
        vector<int> marksIds = markContainerManager.getAllPassengerCarMarks();
        isOneModel = false;
        for(int markId : marksIds) {
            tempIds = markContainerManager.getPassengerCarModelsIds(markId);
            modelsIds.insert(modelsIds.end(),tempIds.begin(),tempIds.end());
        }
    } else if(selectedType == "Грузовик" && selectedMark == "Любые") {
        vector<int> marksIds = markContainerManager.getAllTruckMarks();
        isOneModel = false;
        for(int markId : marksIds) {
            tempIds = markContainerManager.getTruckModelsIds(markId);
            modelsIds.insert(modelsIds.end(),tempIds.begin(),tempIds.end());
        }
    } else if(selectedType == "Мотоцикл" && selectedMark == "Любые") {
        vector<int> marksIds = markContainerManager.getAllMotorbikeMarks();

        isOneModel = false;
        for(int markId : marksIds) {
            tempIds = markContainerManager.getMotorbikeModelsIds(markId);
            modelsIds.insert(modelsIds.end(),tempIds.begin(),tempIds.end());
        }
    }
    if(!isOneModel) {
        if(selectedType == "Мотоцикл") {
            ids.clear();
            for(int id: modelsIds) {
                tempIds = modelContainerManager.getMotorbikeIds(id);
                ids.insert(ids.end(),tempIds.begin(),tempIds.end());
            }
        } else if(selectedType == "Грузовик") {
            ids.clear();
            for(int id: modelsIds) {
                tempIds = modelContainerManager.getTruckIds(id);
                ids.insert(ids.end(),tempIds.begin(),tempIds.end());
            }
        } else if(selectedType == "Легковая") {
            ids.clear();
            for(int id: modelsIds) {
                tempIds = modelContainerManager.getPassengerCarIds(id);
                ids.insert(ids.end(),tempIds.begin(),tempIds.end());
            }
        }

    }
    QStringList idList;
    for (int id : ids) {
        idList << QString::number(id);
    }
    QString formattedIds = idList.join(", ");
    ui->label->setText(formattedIds);
    if(ids.size() != 0){
        ui->prevPageButton->setVisible(true);
        ui->nextPageButton->setVisible(true);
        ui->pageLabel->setVisible(true);
    }
    paginator->setIds(ids);
    // updateGrid(ids);
}


void MainWindow::on_showAddGroupBox_clicked()
{
    ui->comboBoxVehicleTypeAddBox->setCurrentIndex(0);
    ui->comboBoxMarkAddBox->setCurrentIndex(0);
    ui->mainGroupBox->setVisible(false);
    ui->addGroupBox->setVisible(true);
    clearPageContent();
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
    clearPageContent();
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
                lineEdit->setValidator(new QDoubleValidator(0, 1000000, 5, lineEdit));
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

        if (!fileName.isEmpty() && QFile::exists(targetFolder + "/" + fileName)) {
            QFile::remove(targetFolder + "/" + fileName);
        }

        if (QFile::copy(imagePath, targetPath)) {

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
    QString fileName = ui->imageLabelName->text();
    if (!fileName.isEmpty()) {
        QString targetFolder = "C:/course/CourseProject/resources/images";
        QString targetPath = targetFolder + "/" + fileName;

        if (QFile::exists(targetPath)) {
            QFile::remove(targetPath);
        }

        fileName.clear();
        ui->selectImageButton->setIcon(QIcon());
        ui->selectImageButton->setText("➕");
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
    loadMarks();
    ui->addModelGroupBox->setVisible(true);
    ui->addGroupBox->setVisible(false);
}

void MainWindow::updateGrid(const vector<int> &pageIds) {
    string vehicleType = ui->comboBoxVehicleType->currentText().toStdString();

    QLayoutItem *item;
    while ((item = ui->vehicleGrid->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    int row = 0, col = 0;
    for (int id : pageIds) {
        QPushButton *button = new QPushButton(this);
        button->setFixedSize(501, 201);
        loadTransportDataById(id, button, vehicleType);

        ui->vehicleGrid->addWidget(button, row, col);
        connect(button, &QPushButton::clicked, this, &MainWindow::onTransportButtonClicked);

        if (++col == 3) {
            col = 0;
            ++row;
        }
    }
    for(int i = 0;i < 9-int(pageIds.size());i ++) {
        QLabel *label = new QLabel();
        label->setStyleSheet("background-color: #262626");
        ui->vehicleGrid->addWidget(label, row, col);
        if (++col == 3) {
            col = 0;
            ++row;
        }
    }
}


void MainWindow::updatePaginationControls(int currentPage, int totalPages) {
    ui->pageLabel->setText(QString("%1").arg(currentPage));
    ui->prevPageButton->setEnabled(currentPage > 1);
    ui->nextPageButton->setEnabled(currentPage < totalPages);
}

void MainWindow::loadTransportDataById(int id, QPushButton *button, const string& type) {
    if (type == "Мотоцикл") {
        button->setProperty("id", id);
        button->setProperty("type", 1);
        Motorbike bike = _motoSD.loadMoto(id);
        TransportLoader::loadMotorbikeData(bike, button);
    } else if (type == "Легковая") {
        button->setProperty("id", id);
        button->setProperty("type", 2);
        PassengerCar pCar = _pasCarSD.loadPasCar(id);
        TransportLoader::loadPassengerCarData(pCar, button);
    } else if (type == "Грузовик") {
        button->setProperty("id", id);
        button->setProperty("type", 3);
        Truck truck = _truckSD.loadTruck(id);
        TransportLoader::loadTruckData(truck, button);
    }
}


void MainWindow::clearPageContent() {
    QLayoutItem *item;
    while ((item = ui->vehicleGrid->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    ui->prevPageButton->setVisible(false);
    ui->nextPageButton->setVisible(false);
    ui->pageLabel->setVisible(false);
}

void MainWindow::onTransportButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    int objectId = button->property("id").toInt();
    int type = button->property("type").toInt();
    if(type == 1) {
        ui->seatsAndLoadLabel->setVisible(false);
        TransportLoader::loadMotorbikeToInfoPage(objectId,ui->nameLabel, ui->produceYearLabel, ui->factoryPriceLabel,ui->horsepowerLabel,ui->colorLabel,ui->fuelVolumeLabel,ui->engineTypeLabel,ui->CapacityLabel,ui->imageInfoLabel);
    } else if(type == 2) {
        ui->seatsAndLoadLabel->setVisible(true);
        TransportLoader::loadPassengerCarToInfoPage(objectId,ui->nameLabel, ui->produceYearLabel, ui->factoryPriceLabel,ui->horsepowerLabel,ui->colorLabel,ui->fuelVolumeLabel,ui->engineTypeLabel,ui->CapacityLabel,ui->seatsAndLoadLabel,ui->imageInfoLabel);
    } else if(type == 3){
        ui->seatsAndLoadLabel->setVisible(true);
        TransportLoader::loadTruckToInfoPage(objectId,ui->nameLabel, ui->produceYearLabel, ui->factoryPriceLabel,ui->horsepowerLabel,ui->colorLabel,ui->fuelVolumeLabel,ui->engineTypeLabel,ui->CapacityLabel,ui->seatsAndLoadLabel,ui->imageInfoLabel);
    }
    ui->infoGroupBox->setVisible(true);
    ui->blackLabelLeft->setVisible(false);
    ui->blackLabelRight->setVisible(false);

    // showTransportDetails(objectId);
}


void MainWindow::on_closeInfoButton_clicked()
{
    ui->infoGroupBox->setVisible(false);
    ui->blackLabelLeft->setVisible(true);
    ui->blackLabelRight->setVisible(true);
}

