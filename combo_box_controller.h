#ifndef COMBO_BOX_CONTROLLER_H
#define COMBO_BOX_CONTROLLER_H
#include <QObject>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
class ComboBoxController : public QObject {
    Q_OBJECT

public:
    explicit ComboBoxController(QComboBox *vehicleTypeBox, QComboBox *markBox, QComboBox *modelBox,
                                QPushButton *showButton, QComboBox *markSelectBox, QComboBox *typeSelectBox,
                                QLineEdit *newModelField, QComboBox *vehicleTypeAddBox, QComboBox *markAddBox,
                                QComboBox *modelAddBox, QObject *parent = nullptr);
    void clearModels();
    void loadModels(int markId, const std::string &type, QComboBox *modelBox);

private slots:
    void onVehicleTypeChanged(int index);
    void onMarkChanged(int index);
    void onModelChanged(int index);
    void markSelectComboBoxChanged(int index);
    void typeSelectComboBoxChanged(int index);
    void onVehicleTypeAddBoxChanged(int index);
    void onMarkAddBoxChanged(int index);

private:
    QComboBox *vehicleTypeBox;
    QComboBox *markBox;
    QComboBox *modelBox;
    QPushButton *showButton;
    QComboBox *markSelectBox;
    QComboBox *typeSelectBox;
    QLineEdit *newModelField;

    QComboBox *vehicleTypeAddBox;
    QComboBox *markAddBox;
    QComboBox *modelAddBox;

};

#endif // COMBO_BOX_CONTROLLER_H
