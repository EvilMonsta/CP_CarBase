/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *mainGroupBox;
    QPushButton *showButton;
    QComboBox *comboBoxModel;
    QLabel *labelModel;
    QComboBox *comboBoxVehicleType;
    QComboBox *comboBoxMark;
    QLabel *labelMark;
    QLabel *labelVehicleType;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *vehicleGrid;
    QGroupBox *headerMainBox;
    QPushButton *showAddGroupBox;
    QPushButton *showDeleteGroupBox;
    QPushButton *prevPageButton;
    QPushButton *nextPageButton;
    QLabel *pageLabel;
    QGroupBox *infoGroupBox;
    QLabel *imageInfoLabel;
    QPushButton *closeInfoButton;
    QLabel *nameLabel;
    QLabel *produceYearLabel;
    QLabel *factoryPriceLabel;
    QLabel *horsepowerLabel;
    QLabel *seatsAndLoadLabel;
    QLabel *CapacityLabel;
    QLabel *engineTypeLabel;
    QLabel *fuelVolumeLabel;
    QLabel *colorLabel;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QGroupBox *editInfoPage;
    QGroupBox *inputGroupBoxEdit;
    QLabel *labelImageEdit;
    QPushButton *selectImageButtonEdit;
    QLabel *imageLabelNameEdit;
    QPushButton *cancelImageButtonEdit;
    QPushButton *acceptChanges;
    QGroupBox *addGroupBox;
    QComboBox *comboBoxVehicleTypeAddBox;
    QComboBox *comboBoxMarkAddBox;
    QPushButton *addObjectConfirmed;
    QLabel *labelVehicleTypeOnAddPage;
    QLabel *labelMarkOnAddPage;
    QGroupBox *inputGroupBox;
    QLabel *labelImage;
    QPushButton *selectImageButton;
    QLabel *imageLabelName;
    QPushButton *cancelImageButton;
    QComboBox *comboBoxModelAddBox;
    QGroupBox *headerMainBoxAddBox;
    QPushButton *returnToMainPage;
    QPushButton *delMarkAndModelButton;
    QLabel *labelModelOnAddPage;
    QLabel *selectMarkLl;
    QPushButton *addMarkButton;
    QComboBox *typeSelectComboBox;
    QLabel *selectTypeLl;
    QComboBox *markSelectComboBox;
    QLabel *enterModelLl;
    QLabel *addMarkLabel;
    QPushButton *addNewModelButton;
    QLineEdit *addMarkField;
    QLineEdit *newModelField;
    QGroupBox *deleteGroupBox;
    QGroupBox *headerDeleteBox;
    QPushButton *returnToMainPageFromDel;
    QPushButton *returnToAddPage;
    QPushButton *deleteMarkButton;
    QPushButton *editMarkButton;
    QPushButton *editModelButton;
    QPushButton *deleteModelButton;
    QComboBox *comboBoxMarkToEditModel;
    QLabel *labelMarkDelPage;
    QLabel *labelModelDelPage;
    QComboBox *comboBoxTypeToEditModel;
    QLabel *labelTypeLDelPage;
    QComboBox *comboBoxModelToEdit;
    QComboBox *comboBoxMarkToEdit;
    QLabel *selectMarkLabel;
    QLabel *selectModelLabel;
    QLineEdit *editMarkField;
    QLineEdit *editModelField;
    QLabel *newMarkNameLabel;
    QLabel *newModelNameLabel;
    QPushButton *editMarkButton_a;
    QPushButton *editModelButton_a;
    QPushButton *closeButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#3a3a3a;\n"
"color:white;\n"
"}\n"
"QComboBox::hover{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#4d4d4d;\n"
"}\n"
"QComboBox::disabled{\n"
"border:2px solid rgba(180, 160, 200, 50);\n"
"background-color:#131313;\n"
"}\n"
"QComboBox::pressed{\n"
"border:2px solid rgba(240, 240, 255, 255);\n"
"background-color:#606060;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color:  #131313;\n"
"    color: white;                \n"
"    border: 1px solid rgba(240, 240, 255, 255);\n"
"    selection-background-color: #131313; \n"
"    selection-color: white;   \n"
"}\n"
"QLabel{\n"
"color:white;\n"
"}\n"
"QLineEdit{\n"
"background-color:#131313;\n"
"color:white;\n"
"}\n"
""));
        mainGroupBox = new QGroupBox(centralwidget);
        mainGroupBox->setObjectName("mainGroupBox");
        mainGroupBox->setGeometry(QRect(-1, -1, 1922, 1082));
        sizePolicy1.setHeightForWidth(mainGroupBox->sizePolicy().hasHeightForWidth());
        mainGroupBox->setSizePolicy(sizePolicy1);
        mainGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: #262626;\n"
"}"));
        showButton = new QPushButton(mainGroupBox);
        showButton->setObjectName("showButton");
        showButton->setGeometry(QRect(900, 270, 151, 51));
        showButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	outline: none;\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        comboBoxModel = new QComboBox(mainGroupBox);
        comboBoxModel->addItem(QString());
        comboBoxModel->setObjectName("comboBoxModel");
        comboBoxModel->setGeometry(QRect(620, 270, 151, 51));
        comboBoxModel->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#3a3a3a;\n"
"color:white;\n"
"}\n"
"QComboBox::hover{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#4d4d4d;\n"
"}\n"
"QComboBox::disabled{\n"
"border:2px solid rgba(180, 160, 200, 50);\n"
"background-color:#131313;\n"
"}\n"
"QComboBox::pressed{\n"
"border:2px solid rgba(2403, 240, 255, 255);\n"
"background-color:#606060;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color:  #131313;\n"
"    color: white;                \n"
"    border: 1px solid rgba(2403, 240, 255, 255);\n"
"    selection-background-color: #131313; \n"
"    selection-color: white;   \n"
"}"));
        labelModel = new QLabel(mainGroupBox);
        labelModel->setObjectName("labelModel");
        labelModel->setGeometry(QRect(620, 225, 101, 31));
        labelModel->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;"));
        comboBoxVehicleType = new QComboBox(mainGroupBox);
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->setObjectName("comboBoxVehicleType");
        comboBoxVehicleType->setGeometry(QRect(260, 270, 151, 51));
        comboBoxVehicleType->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#3a3a3a;\n"
"color:white;\n"
"}\n"
"QComboBox::hover{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#4d4d4d;\n"
"}\n"
"QComboBox::disabled{\n"
"border:2px solid rgba(180, 160, 200, 50);\n"
"background-color:#131313;\n"
"}\n"
"QComboBox::pressed{\n"
"border:2px solid rgba(2403, 240, 255, 255);\n"
"background-color:#606060;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color:  #131313;\n"
"    color: white;                \n"
"    border: 1px solid rgba(2403, 240, 255, 255);\n"
"    selection-background-color: #131313; \n"
"    selection-color: white;   \n"
"}"));
        comboBoxMark = new QComboBox(mainGroupBox);
        comboBoxMark->addItem(QString());
        comboBoxMark->setObjectName("comboBoxMark");
        comboBoxMark->setGeometry(QRect(440, 270, 151, 51));
        comboBoxMark->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#3a3a3a;\n"
"color:white;\n"
"}\n"
"QComboBox::hover{\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"background-color:#4d4d4d;\n"
"}\n"
"QComboBox::disabled{\n"
"border:2px solid rgba(180, 160, 200, 50);\n"
"background-color:#131313;\n"
"}\n"
"QComboBox::pressed{\n"
"border:2px solid rgba(2403, 240, 255, 255);\n"
"background-color:#606060;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color:  #131313;\n"
"    color: white;                \n"
"    border: 1px solid rgba(2403, 240, 255, 255);\n"
"    selection-background-color: #131313; \n"
"    selection-color: white;   \n"
"}"));
        labelMark = new QLabel(mainGroupBox);
        labelMark->setObjectName("labelMark");
        labelMark->setGeometry(QRect(440, 225, 111, 31));
        labelMark->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;"));
        labelVehicleType = new QLabel(mainGroupBox);
        labelVehicleType->setObjectName("labelVehicleType");
        labelVehicleType->setGeometry(QRect(260, 225, 161, 31));
        labelVehicleType->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;"));
        label = new QLabel(mainGroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 350, 271, 41));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
""));
        gridLayoutWidget = new QWidget(mainGroupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(200, 410, 1511, 611));
        vehicleGrid = new QGridLayout(gridLayoutWidget);
        vehicleGrid->setSpacing(2);
        vehicleGrid->setObjectName("vehicleGrid");
        vehicleGrid->setContentsMargins(2, 2, 2, 2);
        headerMainBox = new QGroupBox(mainGroupBox);
        headerMainBox->setObjectName("headerMainBox");
        headerMainBox->setGeometry(QRect(0, 0, 1931, 131));
        headerMainBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(91, 5, 67),stop:1 rgb(125, 69, 255));\n"
"color:white;\n"
"border:none;\n"
"}\n"
"\n"
""));
        showAddGroupBox = new QPushButton(headerMainBox);
        showAddGroupBox->setObjectName("showAddGroupBox");
        showAddGroupBox->setGeometry(QRect(1410, 40, 111, 51));
        showAddGroupBox->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        showDeleteGroupBox = new QPushButton(headerMainBox);
        showDeleteGroupBox->setObjectName("showDeleteGroupBox");
        showDeleteGroupBox->setGeometry(QRect(1270, 40, 111, 51));
        showDeleteGroupBox->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:14px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        prevPageButton = new QPushButton(mainGroupBox);
        prevPageButton->setObjectName("prevPageButton");
        prevPageButton->setGeometry(QRect(870, 1030, 41, 24));
        prevPageButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        nextPageButton = new QPushButton(mainGroupBox);
        nextPageButton->setObjectName("nextPageButton");
        nextPageButton->setGeometry(QRect(960, 1030, 41, 24));
        nextPageButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        pageLabel = new QLabel(mainGroupBox);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setGeometry(QRect(920, 1030, 31, 24));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:18px;border:2px solid rgba(223, 199, 255, 255);\n"
""));
        infoGroupBox = new QGroupBox(mainGroupBox);
        infoGroupBox->setObjectName("infoGroupBox");
        infoGroupBox->setEnabled(true);
        infoGroupBox->setGeometry(QRect(0, 130, 1921, 1050));
        infoGroupBox->setAutoFillBackground(false);
        infoGroupBox->setStyleSheet(QString::fromUtf8("border:none;\n"
""));
        imageInfoLabel = new QLabel(infoGroupBox);
        imageInfoLabel->setObjectName("imageInfoLabel");
        imageInfoLabel->setGeometry(QRect(100, 100, 600, 600));
        imageInfoLabel->setStyleSheet(QString::fromUtf8("border: 4px solid rgba(223, 199, 255, 255);\n"
""));
        closeInfoButton = new QPushButton(infoGroupBox);
        closeInfoButton->setObjectName("closeInfoButton");
        closeInfoButton->setGeometry(QRect(1800, 10, 111, 61));
        closeInfoButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        nameLabel = new QLabel(infoGroupBox);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(920, 70, 711, 81));
        nameLabel->setStyleSheet(QString::fromUtf8("font-size:32px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        produceYearLabel = new QLabel(infoGroupBox);
        produceYearLabel->setObjectName("produceYearLabel");
        produceYearLabel->setGeometry(QRect(920, 150, 711, 81));
        produceYearLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        factoryPriceLabel = new QLabel(infoGroupBox);
        factoryPriceLabel->setObjectName("factoryPriceLabel");
        factoryPriceLabel->setGeometry(QRect(920, 230, 711, 81));
        factoryPriceLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        horsepowerLabel = new QLabel(infoGroupBox);
        horsepowerLabel->setObjectName("horsepowerLabel");
        horsepowerLabel->setGeometry(QRect(920, 310, 711, 81));
        horsepowerLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        seatsAndLoadLabel = new QLabel(infoGroupBox);
        seatsAndLoadLabel->setObjectName("seatsAndLoadLabel");
        seatsAndLoadLabel->setGeometry(QRect(920, 710, 711, 81));
        seatsAndLoadLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        CapacityLabel = new QLabel(infoGroupBox);
        CapacityLabel->setObjectName("CapacityLabel");
        CapacityLabel->setGeometry(QRect(920, 630, 711, 81));
        CapacityLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        engineTypeLabel = new QLabel(infoGroupBox);
        engineTypeLabel->setObjectName("engineTypeLabel");
        engineTypeLabel->setGeometry(QRect(920, 470, 711, 81));
        engineTypeLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        fuelVolumeLabel = new QLabel(infoGroupBox);
        fuelVolumeLabel->setObjectName("fuelVolumeLabel");
        fuelVolumeLabel->setGeometry(QRect(920, 390, 711, 81));
        fuelVolumeLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        colorLabel = new QLabel(infoGroupBox);
        colorLabel->setObjectName("colorLabel");
        colorLabel->setGeometry(QRect(920, 550, 711, 81));
        colorLabel->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"border: 1px solid rgba(223, 199, 255, 100);"));
        editButton = new QPushButton(infoGroupBox);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(1800, 240, 111, 61));
        editButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        deleteButton = new QPushButton(infoGroupBox);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(1800, 480, 111, 61));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 122, 98);\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        editInfoPage = new QGroupBox(infoGroupBox);
        editInfoPage->setObjectName("editInfoPage");
        editInfoPage->setGeometry(QRect(0, 0, 1921, 1050));
        editInfoPage->setStyleSheet(QString::fromUtf8("border:none;\n"
""));
        inputGroupBoxEdit = new QGroupBox(editInfoPage);
        inputGroupBoxEdit->setObjectName("inputGroupBoxEdit");
        inputGroupBoxEdit->setGeometry(QRect(240, 170, 811, 581));
        inputGroupBoxEdit->setAutoFillBackground(false);
        inputGroupBoxEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-style:Arial;\n"
"background-color: #131313;\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"}\n"
"QGroupBox::title {\n"
"color:white;\n"
"    font: bold 14px Arial; \n"
"}"));
        inputGroupBoxEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        labelImageEdit = new QLabel(inputGroupBoxEdit);
        labelImageEdit->setObjectName("labelImageEdit");
        labelImageEdit->setGeometry(QRect(570, 100, 171, 91));
        labelImageEdit->setTabletTracking(false);
        labelImageEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        labelImageEdit->setStyleSheet(QString::fromUtf8("font-size:24px"));
        selectImageButtonEdit = new QPushButton(inputGroupBoxEdit);
        selectImageButtonEdit->setObjectName("selectImageButtonEdit");
        selectImageButtonEdit->setGeometry(QRect(590, 200, 131, 131));
        selectImageButtonEdit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:#3a3a3a;\n"
"border:2px solid rgba(223, 199, 255, 155);\n"
"color:white;\n"
"font-size:64px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#606060;\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"}"));
        imageLabelNameEdit = new QLabel(inputGroupBoxEdit);
        imageLabelNameEdit->setObjectName("imageLabelNameEdit");
        imageLabelNameEdit->setGeometry(QRect(540, 330, 231, 51));
        imageLabelNameEdit->setTabletTracking(false);
        imageLabelNameEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        imageLabelNameEdit->setStyleSheet(QString::fromUtf8("font-size:14px"));
        cancelImageButtonEdit = new QPushButton(inputGroupBoxEdit);
        cancelImageButtonEdit->setObjectName("cancelImageButtonEdit");
        cancelImageButtonEdit->setEnabled(true);
        cancelImageButtonEdit->setGeometry(QRect(700, 200, 21, 21));
        cancelImageButtonEdit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:#3a3a3a;\n"
"border:2px solid rgba(223, 199, 255, 155);\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#606060;\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"}\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"border:2px solid rgba(223, 199, 255, 25);\n"
"}"));
        acceptChanges = new QPushButton(inputGroupBoxEdit);
        acceptChanges->setObjectName("acceptChanges");
        acceptChanges->setEnabled(false);
        acceptChanges->setGeometry(QRect(590, 480, 131, 51));
        acceptChanges->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        addGroupBox = new QGroupBox(centralwidget);
        addGroupBox->setObjectName("addGroupBox");
        addGroupBox->setEnabled(true);
        addGroupBox->setGeometry(QRect(-1, -1, 1922, 1082));
        sizePolicy1.setHeightForWidth(addGroupBox->sizePolicy().hasHeightForWidth());
        addGroupBox->setSizePolicy(sizePolicy1);
        addGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: #262626;\n"
"}"));
        comboBoxVehicleTypeAddBox = new QComboBox(addGroupBox);
        comboBoxVehicleTypeAddBox->addItem(QString());
        comboBoxVehicleTypeAddBox->addItem(QString());
        comboBoxVehicleTypeAddBox->addItem(QString());
        comboBoxVehicleTypeAddBox->addItem(QString());
        comboBoxVehicleTypeAddBox->setObjectName("comboBoxVehicleTypeAddBox");
        comboBoxVehicleTypeAddBox->setEnabled(false);
        comboBoxVehicleTypeAddBox->setGeometry(QRect(440, 270, 151, 51));
        comboBoxVehicleTypeAddBox->setStyleSheet(QString::fromUtf8(""));
        comboBoxMarkAddBox = new QComboBox(addGroupBox);
        comboBoxMarkAddBox->addItem(QString());
        comboBoxMarkAddBox->setObjectName("comboBoxMarkAddBox");
        comboBoxMarkAddBox->setGeometry(QRect(260, 270, 151, 51));
        addObjectConfirmed = new QPushButton(addGroupBox);
        addObjectConfirmed->setObjectName("addObjectConfirmed");
        addObjectConfirmed->setEnabled(false);
        addObjectConfirmed->setGeometry(QRect(1100, 870, 151, 51));
        addObjectConfirmed->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        labelVehicleTypeOnAddPage = new QLabel(addGroupBox);
        labelVehicleTypeOnAddPage->setObjectName("labelVehicleTypeOnAddPage");
        labelVehicleTypeOnAddPage->setGeometry(QRect(440, 230, 141, 31));
        labelVehicleTypeOnAddPage->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        labelMarkOnAddPage = new QLabel(addGroupBox);
        labelMarkOnAddPage->setObjectName("labelMarkOnAddPage");
        labelMarkOnAddPage->setGeometry(QRect(260, 230, 91, 31));
        labelMarkOnAddPage->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        inputGroupBox = new QGroupBox(addGroupBox);
        inputGroupBox->setObjectName("inputGroupBox");
        inputGroupBox->setGeometry(QRect(260, 340, 811, 581));
        inputGroupBox->setAutoFillBackground(false);
        inputGroupBox->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-style:Arial;\n"
"background-color: #131313;\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"}\n"
"QGroupBox::title {\n"
"color:white;\n"
"    font: bold 14px Arial; \n"
"}"));
        inputGroupBox->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        labelImage = new QLabel(inputGroupBox);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(570, 100, 171, 91));
        labelImage->setTabletTracking(false);
        labelImage->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        labelImage->setStyleSheet(QString::fromUtf8("font-size:24px"));
        selectImageButton = new QPushButton(inputGroupBox);
        selectImageButton->setObjectName("selectImageButton");
        selectImageButton->setGeometry(QRect(590, 200, 131, 131));
        selectImageButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:#3a3a3a;\n"
"border:2px solid rgba(223, 199, 255, 155);\n"
"color:white;\n"
"font-size:64px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#606060;\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"}"));
        imageLabelName = new QLabel(inputGroupBox);
        imageLabelName->setObjectName("imageLabelName");
        imageLabelName->setGeometry(QRect(540, 330, 231, 51));
        imageLabelName->setTabletTracking(false);
        imageLabelName->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        imageLabelName->setStyleSheet(QString::fromUtf8("font-size:14px"));
        cancelImageButton = new QPushButton(inputGroupBox);
        cancelImageButton->setObjectName("cancelImageButton");
        cancelImageButton->setEnabled(true);
        cancelImageButton->setGeometry(QRect(700, 200, 21, 21));
        cancelImageButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:#3a3a3a;\n"
"border:2px solid rgba(223, 199, 255, 155);\n"
"color:white;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#606060;\n"
"border:2px solid rgba(223, 199, 255, 255);\n"
"}\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"border:2px solid rgba(223, 199, 255, 25);\n"
"}"));
        comboBoxModelAddBox = new QComboBox(addGroupBox);
        comboBoxModelAddBox->addItem(QString());
        comboBoxModelAddBox->setObjectName("comboBoxModelAddBox");
        comboBoxModelAddBox->setGeometry(QRect(620, 270, 151, 51));
        headerMainBoxAddBox = new QGroupBox(addGroupBox);
        headerMainBoxAddBox->setObjectName("headerMainBoxAddBox");
        headerMainBoxAddBox->setGeometry(QRect(-10, 0, 1931, 131));
        headerMainBoxAddBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(91, 5, 67),stop:1 rgb(125, 69, 255));\n"
"color:white;\n"
"border:none;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        returnToMainPage = new QPushButton(headerMainBoxAddBox);
        returnToMainPage->setObjectName("returnToMainPage");
        returnToMainPage->setGeometry(QRect(1420, 40, 111, 51));
        delMarkAndModelButton = new QPushButton(headerMainBoxAddBox);
        delMarkAndModelButton->setObjectName("delMarkAndModelButton");
        delMarkAndModelButton->setGeometry(QRect(1280, 40, 111, 51));
        delMarkAndModelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:14px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        labelModelOnAddPage = new QLabel(addGroupBox);
        labelModelOnAddPage->setObjectName("labelModelOnAddPage");
        labelModelOnAddPage->setGeometry(QRect(620, 230, 141, 31));
        labelModelOnAddPage->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        selectMarkLl = new QLabel(addGroupBox);
        selectMarkLl->setObjectName("selectMarkLl");
        selectMarkLl->setGeometry(QRect(1410, 230, 151, 31));
        selectMarkLl->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;"));
        addMarkButton = new QPushButton(addGroupBox);
        addMarkButton->setObjectName("addMarkButton");
        addMarkButton->setEnabled(false);
        addMarkButton->setGeometry(QRect(1590, 550, 91, 31));
        addMarkButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        addMarkButton->setAutoDefault(false);
        addMarkButton->setFlat(false);
        typeSelectComboBox = new QComboBox(addGroupBox);
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->setObjectName("typeSelectComboBox");
        typeSelectComboBox->setGeometry(QRect(1590, 280, 151, 51));
        selectTypeLl = new QLabel(addGroupBox);
        selectTypeLl->setObjectName("selectTypeLl");
        selectTypeLl->setGeometry(QRect(1590, 230, 131, 31));
        selectTypeLl->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;"));
        markSelectComboBox = new QComboBox(addGroupBox);
        markSelectComboBox->addItem(QString());
        markSelectComboBox->setObjectName("markSelectComboBox");
        markSelectComboBox->setGeometry(QRect(1410, 280, 151, 51));
        enterModelLl = new QLabel(addGroupBox);
        enterModelLl->setObjectName("enterModelLl");
        enterModelLl->setGeometry(QRect(1410, 350, 151, 61));
        enterModelLl->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;"));
        addMarkLabel = new QLabel(addGroupBox);
        addMarkLabel->setObjectName("addMarkLabel");
        addMarkLabel->setGeometry(QRect(1410, 510, 151, 31));
        addMarkLabel->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        addNewModelButton = new QPushButton(addGroupBox);
        addNewModelButton->setObjectName("addNewModelButton");
        addNewModelButton->setEnabled(false);
        addNewModelButton->setGeometry(QRect(1590, 420, 91, 31));
        addNewModelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        addMarkField = new QLineEdit(addGroupBox);
        addMarkField->setObjectName("addMarkField");
        addMarkField->setGeometry(QRect(1410, 550, 151, 31));
        addMarkField->setStyleSheet(QString::fromUtf8("width: 150px;\n"
"height: 30px;\n"
"font: bold 10pt 'Arial';\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-size: 14px;\n"
"color: white;\n"
""));
        newModelField = new QLineEdit(addGroupBox);
        newModelField->setObjectName("newModelField");
        newModelField->setGeometry(QRect(1410, 420, 151, 31));
        newModelField->setStyleSheet(QString::fromUtf8("width: 150px;\n"
"height: 30px;\n"
"font: bold 10pt 'Arial';\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-size: 14px;\n"
"color: white;\n"
""));
        deleteGroupBox = new QGroupBox(centralwidget);
        deleteGroupBox->setObjectName("deleteGroupBox");
        deleteGroupBox->setGeometry(QRect(-1, -1, 1922, 1082));
        deleteGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: #262626;\n"
"}"));
        headerDeleteBox = new QGroupBox(deleteGroupBox);
        headerDeleteBox->setObjectName("headerDeleteBox");
        headerDeleteBox->setGeometry(QRect(0, 0, 1931, 131));
        headerDeleteBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(91, 5, 67),stop:1 rgb(125, 69, 255));\n"
"color:white;\n"
"border:none;\n"
"}\n"
"QPushButton{\n"
"	outline: none;\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"background-color:#131313;\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        returnToMainPageFromDel = new QPushButton(headerDeleteBox);
        returnToMainPageFromDel->setObjectName("returnToMainPageFromDel");
        returnToMainPageFromDel->setGeometry(QRect(1410, 40, 111, 51));
        returnToAddPage = new QPushButton(headerDeleteBox);
        returnToAddPage->setObjectName("returnToAddPage");
        returnToAddPage->setGeometry(QRect(1270, 40, 111, 51));
        sizePolicy1.setHeightForWidth(returnToAddPage->sizePolicy().hasHeightForWidth());
        returnToAddPage->setSizePolicy(sizePolicy1);
        deleteMarkButton = new QPushButton(deleteGroupBox);
        deleteMarkButton->setObjectName("deleteMarkButton");
        deleteMarkButton->setEnabled(false);
        deleteMarkButton->setGeometry(QRect(460, 390, 101, 31));
        deleteMarkButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        deleteMarkButton->setAutoDefault(false);
        deleteMarkButton->setFlat(false);
        editMarkButton = new QPushButton(deleteGroupBox);
        editMarkButton->setObjectName("editMarkButton");
        editMarkButton->setEnabled(false);
        editMarkButton->setGeometry(QRect(460, 330, 101, 31));
        editMarkButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:14px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);\n"
"}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        editModelButton = new QPushButton(deleteGroupBox);
        editModelButton->setObjectName("editModelButton");
        editModelButton->setEnabled(false);
        editModelButton->setGeometry(QRect(1320, 330, 101, 31));
        editModelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:14px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        deleteModelButton = new QPushButton(deleteGroupBox);
        deleteModelButton->setObjectName("deleteModelButton");
        deleteModelButton->setEnabled(false);
        deleteModelButton->setGeometry(QRect(1320, 390, 101, 31));
        deleteModelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:18px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        deleteModelButton->setAutoDefault(false);
        deleteModelButton->setFlat(false);
        comboBoxMarkToEditModel = new QComboBox(deleteGroupBox);
        comboBoxMarkToEditModel->addItem(QString());
        comboBoxMarkToEditModel->setObjectName("comboBoxMarkToEditModel");
        comboBoxMarkToEditModel->setGeometry(QRect(750, 330, 151, 51));
        labelMarkDelPage = new QLabel(deleteGroupBox);
        labelMarkDelPage->setObjectName("labelMarkDelPage");
        labelMarkDelPage->setGeometry(QRect(750, 290, 91, 31));
        labelMarkDelPage->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        labelModelDelPage = new QLabel(deleteGroupBox);
        labelModelDelPage->setObjectName("labelModelDelPage");
        labelModelDelPage->setGeometry(QRect(1110, 290, 141, 31));
        labelModelDelPage->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        comboBoxTypeToEditModel = new QComboBox(deleteGroupBox);
        comboBoxTypeToEditModel->addItem(QString());
        comboBoxTypeToEditModel->addItem(QString());
        comboBoxTypeToEditModel->addItem(QString());
        comboBoxTypeToEditModel->addItem(QString());
        comboBoxTypeToEditModel->setObjectName("comboBoxTypeToEditModel");
        comboBoxTypeToEditModel->setEnabled(false);
        comboBoxTypeToEditModel->setGeometry(QRect(930, 330, 151, 51));
        comboBoxTypeToEditModel->setStyleSheet(QString::fromUtf8(""));
        labelTypeLDelPage = new QLabel(deleteGroupBox);
        labelTypeLDelPage->setObjectName("labelTypeLDelPage");
        labelTypeLDelPage->setGeometry(QRect(930, 290, 141, 31));
        labelTypeLDelPage->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        comboBoxModelToEdit = new QComboBox(deleteGroupBox);
        comboBoxModelToEdit->addItem(QString());
        comboBoxModelToEdit->setObjectName("comboBoxModelToEdit");
        comboBoxModelToEdit->setEnabled(false);
        comboBoxModelToEdit->setGeometry(QRect(1110, 330, 151, 51));
        comboBoxMarkToEdit = new QComboBox(deleteGroupBox);
        comboBoxMarkToEdit->addItem(QString());
        comboBoxMarkToEdit->setObjectName("comboBoxMarkToEdit");
        comboBoxMarkToEdit->setGeometry(QRect(250, 330, 151, 51));
        selectMarkLabel = new QLabel(deleteGroupBox);
        selectMarkLabel->setObjectName("selectMarkLabel");
        selectMarkLabel->setGeometry(QRect(250, 180, 181, 101));
        selectMarkLabel->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        selectModelLabel = new QLabel(deleteGroupBox);
        selectModelLabel->setObjectName("selectModelLabel");
        selectModelLabel->setGeometry(QRect(750, 180, 441, 101));
        selectModelLabel->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        editMarkField = new QLineEdit(deleteGroupBox);
        editMarkField->setObjectName("editMarkField");
        editMarkField->setGeometry(QRect(250, 510, 151, 31));
        editMarkField->setStyleSheet(QString::fromUtf8("width: 150px;\n"
"height: 30px;\n"
"font: bold 10pt 'Arial';\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-size: 14px;\n"
"color: white;\n"
""));
        editModelField = new QLineEdit(deleteGroupBox);
        editModelField->setObjectName("editModelField");
        editModelField->setGeometry(QRect(750, 510, 151, 31));
        editModelField->setStyleSheet(QString::fromUtf8("width: 150px;\n"
"height: 30px;\n"
"font: bold 10pt 'Arial';\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-size: 14px;\n"
"color: white;\n"
""));
        newMarkNameLabel = new QLabel(deleteGroupBox);
        newMarkNameLabel->setObjectName("newMarkNameLabel");
        newMarkNameLabel->setGeometry(QRect(250, 460, 351, 21));
        newMarkNameLabel->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        newModelNameLabel = new QLabel(deleteGroupBox);
        newModelNameLabel->setObjectName("newModelNameLabel");
        newModelNameLabel->setGeometry(QRect(750, 460, 351, 21));
        newModelNameLabel->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        editMarkButton_a = new QPushButton(deleteGroupBox);
        editMarkButton_a->setObjectName("editMarkButton_a");
        editMarkButton_a->setEnabled(false);
        editMarkButton_a->setGeometry(QRect(460, 510, 101, 31));
        editMarkButton_a->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:14px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        editModelButton_a = new QPushButton(deleteGroupBox);
        editModelButton_a->setObjectName("editModelButton_a");
        editModelButton_a->setEnabled(false);
        editModelButton_a->setGeometry(QRect(960, 510, 101, 31));
        editModelButton_a->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-size:14px;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid #007f00;\n"
"    border-left: 2px solid #007f00;\n"
"background-color:#262626;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid #007f00;\n"
"    border-bottom: 2px solid #007f00;\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(1870, 0, 51, 31));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"font-size:18px;\n"
"border:2px solid black;\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#C1002E;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color:#FF545E\n"
"}\n"
"\n"
""));
        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");
        undoButton->setGeometry(QRect(0, 0, 41, 31));
        undoButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:28px;\n"
"color:rgb(202, 153, 186);\n"
"background-color:#262626;\n"
"outline: none;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
"\n"
""));
        redoButton = new QPushButton(centralwidget);
        redoButton->setObjectName("redoButton");
        redoButton->setGeometry(QRect(40, 0, 41, 31));
        redoButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:28px;\n"
"color:rgb(202, 153, 186);\n"
"background-color:#262626;\n"
"outline: none;\n"
"border-right: 2px solid rgb(31, 8, 41);\n"
"    border-bottom: 2px solid rgb(31, 8, 41);\n"
"    border-top: 2px solid rgb(145, 110, 133);\n"
"    border-left: 2px solid rgb(145, 110, 133);\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#3a3a3a;\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"	background-color:#131313;\n"
"    border-top: 2px solid rgb(153, 47, 47);\n"
"    border-left: 2px solid rgb(153, 47, 47);}\n"
"QPushButton::pressed {\n"
"    border-right: 2px solid rgb(145, 110, 133);\n"
"    border-bottom: 2px solid rgb(145, 110, 133);\n"
"    border-top: 2px solid rgb(31, 8, 41);\n"
"    border-left: 2px solid rgb(31, 8, 41);\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        addGroupBox->raise();
        deleteGroupBox->raise();
        mainGroupBox->raise();
        closeButton->raise();
        redoButton->raise();
        undoButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy2);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        statusbar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        addMarkButton->setDefault(false);
        deleteMarkButton->setDefault(false);
        deleteModelButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mainGroupBox->setTitle(QString());
        showButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        comboBoxModel->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));

        labelModel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        comboBoxVehicleType->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxVehicleType->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\320\260\321\217", nullptr));
        comboBoxVehicleType->setItemText(2, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273", nullptr));
        comboBoxVehicleType->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272", nullptr));

        comboBoxVehicleType->setCurrentText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxMark->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));

        labelMark->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260:", nullptr));
        labelVehicleType->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        headerMainBox->setTitle(QString());
        showAddGroupBox->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        showDeleteGroupBox->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\274\320\260\321\200\320\272\321\203\n"
" \320\270\320\273\320\270 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        prevPageButton->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        nextPageButton->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        pageLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        infoGroupBox->setTitle(QString());
        imageInfoLabel->setText(QString());
        closeInfoButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        produceYearLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        factoryPriceLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        horsepowerLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        seatsAndLoadLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        CapacityLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        engineTypeLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        fuelVolumeLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        colorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        editInfoPage->setTitle(QString());
        inputGroupBoxEdit->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\277\320\276\320\273\321\217:", nullptr));
        labelImageEdit->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265<br/>\320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265</p></body></html>", nullptr));
        selectImageButtonEdit->setText(QCoreApplication::translate("MainWindow", "\342\236\225", nullptr));
        imageLabelNameEdit->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275</p></body></html>", nullptr));
        cancelImageButtonEdit->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        acceptChanges->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        addGroupBox->setTitle(QCoreApplication::translate("MainWindow", "box2", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\320\260\321\217", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272", nullptr));

        comboBoxVehicleTypeAddBox->setCurrentText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxMarkAddBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        addObjectConfirmed->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        labelVehicleTypeOnAddPage->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260:", nullptr));
        labelMarkOnAddPage->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260:", nullptr));
        inputGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\277\320\276\320\273\321\217:", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265<br/>\320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265</p></body></html>", nullptr));
        selectImageButton->setText(QCoreApplication::translate("MainWindow", "\342\236\225", nullptr));
        imageLabelName->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275</p></body></html>", nullptr));
        cancelImageButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        comboBoxModelAddBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        headerMainBoxAddBox->setTitle(QString());
        returnToMainPage->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        delMarkAndModelButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\274\320\260\321\200\320\272\321\203\n"
" \320\270\320\273\320\270 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        labelModelOnAddPage->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214:", nullptr));
        selectMarkLl->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\260\321\200\320\272\321\203:", nullptr));
        addMarkButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        typeSelectComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        typeSelectComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\320\260\321\217", nullptr));
        typeSelectComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272", nullptr));
        typeSelectComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273", nullptr));

        selectTypeLl->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277:", nullptr));
        markSelectComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        enterModelLl->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 </p><p>\320\274\320\276\320\264\320\265\320\273\320\270:</p></body></html>", nullptr));
        addMarkLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\321\200\320\272\321\203:", nullptr));
        addNewModelButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteGroupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        headerDeleteBox->setTitle(QString());
        returnToMainPageFromDel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        returnToAddPage->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteMarkButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        editMarkButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        editModelButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        deleteModelButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        comboBoxMarkToEditModel->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        labelMarkDelPage->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260:", nullptr));
        labelModelDelPage->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214:", nullptr));
        comboBoxTypeToEditModel->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxTypeToEditModel->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\320\260\321\217", nullptr));
        comboBoxTypeToEditModel->setItemText(2, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273", nullptr));
        comboBoxTypeToEditModel->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272", nullptr));

        comboBoxTypeToEditModel->setCurrentText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        labelTypeLDelPage->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260:", nullptr));
        comboBoxModelToEdit->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        comboBoxMarkToEdit->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        selectMarkLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\260\321\200\320\272\321\203 \320\264\320\273\321\217</p><p>\321\200\320\260\320\261\320\276\321\202\321\213 \321\201 \320\275\320\265\320\271:</p></body></html>", nullptr));
        selectModelLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\260\321\200\320\272\321\203, \321\202\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260,  \320\260 \320\267\320\260\321\202\320\265\320\274 \320\274\320\276\320\264\320\265\320\273\321\214</p><p> \320\264\320\273\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \321\201 \320\275\320\265\320\271:</p></body></html>", nullptr));
        newMarkNameLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\260\321\200\320\272\320\270: </p></body></html>", nullptr));
        newModelNameLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\270: </p></body></html>", nullptr));
        editMarkButton_a->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        editModelButton_a->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "\342\255\240", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "\342\255\242", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
