#ifndef TRANSPORT_INPUT_BOX_H
#define TRANSPORT_INPUT_BOX_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

class TransportInputBox : public QWidget {
    Q_OBJECT

public:
    TransportInputBox(QWidget *parent = nullptr);
    QPushButton* getAddButton() const;
    void setupFields(int numFields, const QStringList &fieldNames, const QStringList &fieldTypes);
    bool validateFields();
    QStringList getFieldValues() const;

signals:
    void addClicked();

private:
    QFormLayout *formLayout;
    QPushButton *addButton;
};

#endif // TRANSPORT_INPUT_BOX_H
