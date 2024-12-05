#include "combo_box_controller.h"
#include "mark_container_manager.h"
#include "model_manager.h"

ComboBoxController::ComboBoxController(QComboBox *vehicleTypeBox, QComboBox *markBox, QComboBox *modelBox,
                                       QPushButton *showButton, QComboBox *markSelectBox, QComboBox *typeSelectBox,
                                       QLineEdit *newModelField, QComboBox *vehicleTypeAddBox, QComboBox *markAddBox,
                                       QComboBox *modelAddBox, QPushButton *addModel, QObject *parent)
    : QObject(parent), vehicleTypeBox(vehicleTypeBox), markBox(markBox), modelBox(modelBox),
    showButton(showButton), markSelectBox(markSelectBox), typeSelectBox(typeSelectBox), newModelField(newModelField),
    vehicleTypeAddBox(vehicleTypeAddBox), markAddBox(markAddBox), modelAddBox(modelAddBox), addModel(addModel) {

    connect(vehicleTypeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onVehicleTypeChanged(int)));
    connect(markBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onMarkChanged(int)));
    connect(modelBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onModelChanged(int)));
    connect(markSelectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(markSelectComboBoxChanged(int)));
    connect(typeSelectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(typeSelectComboBoxChanged(int)));
    connect(vehicleTypeAddBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onVehicleTypeAddBoxChanged(int)));
    connect(markAddBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onMarkAddBoxChanged(int)));
}

void ComboBoxController::onVehicleTypeAddBoxChanged(int index) {
    QString selectedType = vehicleTypeAddBox->itemText(index);
    int selectedMarkId = markAddBox->currentData().toInt();

    if (selectedType == "Не выбрано") {
        modelAddBox->clear();
        modelAddBox->setEnabled(false);
    } else {
        clearModels();
        loadModels(selectedMarkId, selectedType.toStdString(), modelAddBox);
        modelAddBox->setEnabled(true);
    }

    vehicleTypeAddBox->setCurrentText(selectedType);
}

void ComboBoxController::onMarkAddBoxChanged(int index) {
    QString selectedMark = markAddBox->itemText(index);

    if (selectedMark == "Не выбрано") {
        vehicleTypeAddBox->setCurrentIndex(0);
        vehicleTypeAddBox->setEnabled(false);
    } else {
        vehicleTypeAddBox->setCurrentIndex(0);
        vehicleTypeAddBox->setEnabled(true);
    }
    markAddBox->setCurrentText(selectedMark);
}

void ComboBoxController::onVehicleTypeChanged(int index) {
    QString selectedType = vehicleTypeBox->itemText(index);

    if (selectedType == "Не выбрано") {
        showButton->setEnabled(false);
        markBox->setCurrentIndex(0);
        modelBox->setCurrentIndex(0);
        markBox->setEnabled(false);
        modelBox->setEnabled(false);
    } else {
        showButton->setEnabled(true);
        markBox->setEnabled(true);
        markBox->setCurrentIndex(0);
    }

    vehicleTypeBox->setCurrentText(selectedType);
}

void ComboBoxController::onMarkChanged(int index) {
    QString selectedMark = markBox->itemText(index);
    int selectedMarkId = markBox->currentData().toInt();
    QString selectedType = vehicleTypeBox->currentText();

    if (selectedMark == "Любые") {
        modelBox->setCurrentIndex(0);
        modelBox->setEnabled(false);
    } else {
        modelBox->setEnabled(true);
        clearModels();
        loadModels(selectedMarkId, selectedType.toStdString(), modelBox);
    }

    markBox->setCurrentText(selectedMark);
}

void ComboBoxController::onModelChanged(int index) {
    QString selectedModel = modelBox->itemText(index);
        modelBox->setCurrentText(selectedModel);
}

void ComboBoxController::clearModels() {
    modelAddBox->clear();
    modelAddBox->addItem(QString::fromStdString("Не выбрано"),0);
    modelBox->clear();
    modelBox->addItem(QString::fromStdString("Любые"),0);
}

void ComboBoxController::loadModels(int markId, const string &type, QComboBox *modelBox) {
    vector<int> ids;
    MarkContainerManager markContainerManager;
    markContainerManager.loadIdsFromFile();
    ModelManager modelManager;
    if(type == "Легковая"){
        ids = markContainerManager.getPassengerCarModelsIds(markId);
    } else if(type == "Грузовик") {
        ids = markContainerManager.getTruckModelsIds(markId);
    } else if(type == "Мотоцикл") {
        ids = markContainerManager.getMotorbikeModelsIds(markId);
    }
    vector<Model> models = modelManager.getModels(ids);

    for(const Model &model: models) {
        qDebug() << "m= " << model.id << model.name;
        modelBox->addItem(QString::fromStdString(model.name), model.id);
    }
}

void ComboBoxController::markSelectComboBoxChanged(int index) {
    QString selectedMark = markSelectBox->itemText(index);

    if (selectedMark == "Не выбрано") {
        typeSelectBox->setCurrentIndex(0);
        typeSelectBox->setEnabled(false);
    } else {
        typeSelectBox->setEnabled(true);
    }
}

void ComboBoxController::typeSelectComboBoxChanged(int index) {
    QString selectedType = typeSelectBox->itemText(index);

    if (selectedType == "Не выбрано") {
        newModelField->setEnabled(false);
        addModel->setEnabled(false);
    } else {
        newModelField->setEnabled(true);
        addModel->setEnabled(true);
    }
}
