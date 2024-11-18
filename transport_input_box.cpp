#include "transport_input_box.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>
TransportInputBox::TransportInputBox(QWidget *parent) : QWidget(parent) {
    formLayout = new QFormLayout(this);
    connect(addButton, &QPushButton::clicked, this, &TransportInputBox::addClicked);  // Подключаем сигнал
    setLayout(formLayout);
}

QPushButton* TransportInputBox::getAddButton() const {
    return addButton;
}

void TransportInputBox::setupFields(int numFields, const QStringList &fieldNames, const QStringList &fieldTypes) {
    QLayoutItem *child;
    while ((child = formLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    for (int i = 0; i < numFields; ++i) {
        if (fieldTypes[i] == "int") {
            formLayout->addRow(fieldNames[i], new QLineEdit);
        } else if (fieldTypes[i] == "double") {
            formLayout->addRow(fieldNames[i], new QLineEdit);  // Можно использовать QLineEdit для чисел с плавающей точкой
        } else {
            formLayout->addRow(fieldNames[i], new QLineEdit);  // Для строковых данных
        }
    }

    formLayout->addRow(addButton);
}

bool TransportInputBox::validateFields() {
    for (int i = 0; i < formLayout->count(); ++i) {
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(formLayout->itemAt(i)->widget());
        if (lineEdit && lineEdit->text().isEmpty()) {
            return false;  // Проверка на пустые поля
        }
    }
    return true;
}

QStringList TransportInputBox::getFieldValues() const {
    QStringList values;
    for (int i = 0; i < formLayout->count(); ++i) {
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(formLayout->itemAt(i)->widget());
        if (lineEdit) {
            values.append(lineEdit->text());
        }
    }
    return values;
}
