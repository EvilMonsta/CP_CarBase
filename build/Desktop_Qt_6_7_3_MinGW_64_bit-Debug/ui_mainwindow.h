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
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QGroupBox *headerMainBox;
    QPushButton *showAddGroupBox;
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
    QPushButton *addMarkButton;
    QLineEdit *addMarkField;
    QLabel *addMarkLabel;
    QComboBox *comboBoxModelAddBox;
    QGroupBox *headerMainBoxAddBox;
    QPushButton *returnToMainPage;
    QPushButton *addModelButton;
    QGroupBox *addModelGroupBox;
    QComboBox *markSelectComboBox;
    QComboBox *typeSelectComboBox;
    QLineEdit *newModelField;
    QPushButton *addNewModelButton;
    QGroupBox *headerMainBoxModelAddBox;
    QPushButton *returToMainPageFromModel;
    QPushButton *returnToAddPage;
    QLabel *selectMarkLl;
    QLabel *selectTypeLl;
    QLabel *enterModelLl;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainGroupBox = new QGroupBox(centralwidget);
        mainGroupBox->setObjectName("mainGroupBox");
        mainGroupBox->setGeometry(QRect(-1, -21, 1921, 1101));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainGroupBox->sizePolicy().hasHeightForWidth());
        mainGroupBox->setSizePolicy(sizePolicy);
        mainGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: white;\n"
"}"));
        showButton = new QPushButton(mainGroupBox);
        showButton->setObjectName("showButton");
        showButton->setGeometry(QRect(900, 270, 151, 51));
        comboBoxModel = new QComboBox(mainGroupBox);
        comboBoxModel->addItem(QString());
        comboBoxModel->setObjectName("comboBoxModel");
        comboBoxModel->setGeometry(QRect(620, 270, 151, 51));
        labelModel = new QLabel(mainGroupBox);
        labelModel->setObjectName("labelModel");
        labelModel->setGeometry(QRect(620, 240, 49, 16));
        comboBoxVehicleType = new QComboBox(mainGroupBox);
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->addItem(QString());
        comboBoxVehicleType->setObjectName("comboBoxVehicleType");
        comboBoxVehicleType->setGeometry(QRect(440, 270, 151, 51));
        comboBoxVehicleType->setStyleSheet(QString::fromUtf8(""));
        comboBoxMark = new QComboBox(mainGroupBox);
        comboBoxMark->addItem(QString());
        comboBoxMark->setObjectName("comboBoxMark");
        comboBoxMark->setGeometry(QRect(260, 270, 151, 51));
        labelMark = new QLabel(mainGroupBox);
        labelMark->setObjectName("labelMark");
        labelMark->setGeometry(QRect(260, 240, 71, 16));
        labelVehicleType = new QLabel(mainGroupBox);
        labelVehicleType->setObjectName("labelVehicleType");
        labelVehicleType->setGeometry(QRect(440, 240, 121, 16));
        label = new QLabel(mainGroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(1110, 170, 161, 151));
        label->setStyleSheet(QString::fromUtf8("font-size:40px;\n"
"border: 2px solid red;\n"
""));
        gridLayoutWidget = new QWidget(mainGroupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(260, 420, 1351, 531));
        vehicleGrid = new QGridLayout(gridLayoutWidget);
        vehicleGrid->setSpacing(5);
        vehicleGrid->setObjectName("vehicleGrid");
        vehicleGrid->setContentsMargins(5, 5, 5, 5);
        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_7, 2, 3, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName("pushButton_8");
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_8, 1, 3, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName("pushButton_10");
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_10, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName("pushButton_11");
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_11, 3, 2, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName("pushButton_12");
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_12, 3, 3, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_9, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setStyleSheet(QString::fromUtf8("font-size:64px"));

        vehicleGrid->addWidget(pushButton_4, 1, 2, 1, 1);

        headerMainBox = new QGroupBox(mainGroupBox);
        headerMainBox->setObjectName("headerMainBox");
        headerMainBox->setGeometry(QRect(0, -20, 1931, 151));
        headerMainBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-size:200%;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(91, 5, 67),stop:1 rgb(125, 69, 255));\n"
"color:white\n"
"}\n"
""));
        showAddGroupBox = new QPushButton(headerMainBox);
        showAddGroupBox->setObjectName("showAddGroupBox");
        showAddGroupBox->setGeometry(QRect(1410, 60, 91, 51));
        addGroupBox = new QGroupBox(centralwidget);
        addGroupBox->setObjectName("addGroupBox");
        addGroupBox->setEnabled(true);
        addGroupBox->setGeometry(QRect(-1, -21, 1921, 1101));
        sizePolicy.setHeightForWidth(addGroupBox->sizePolicy().hasHeightForWidth());
        addGroupBox->setSizePolicy(sizePolicy);
        addGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: white;\n"
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
        addObjectConfirmed->setGeometry(QRect(1460, 720, 151, 51));
        labelVehicleTypeOnAddPage = new QLabel(addGroupBox);
        labelVehicleTypeOnAddPage->setObjectName("labelVehicleTypeOnAddPage");
        labelVehicleTypeOnAddPage->setGeometry(QRect(440, 240, 121, 16));
        labelMarkOnAddPage = new QLabel(addGroupBox);
        labelMarkOnAddPage->setObjectName("labelMarkOnAddPage");
        labelMarkOnAddPage->setGeometry(QRect(260, 240, 71, 16));
        inputGroupBox = new QGroupBox(addGroupBox);
        inputGroupBox->setObjectName("inputGroupBox");
        inputGroupBox->setGeometry(QRect(260, 340, 641, 431));
        inputGroupBox->setAutoFillBackground(false);
        inputGroupBox->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-style:Arial;\n"
"background-color: #f2f2f2;\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"}"));
        labelImage = new QLabel(inputGroupBox);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(460, 80, 91, 61));
        labelImage->setTabletTracking(false);
        labelImage->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        selectImageButton = new QPushButton(inputGroupBox);
        selectImageButton->setObjectName("selectImageButton");
        selectImageButton->setGeometry(QRect(440, 140, 131, 131));
        imageLabelName = new QLabel(inputGroupBox);
        imageLabelName->setObjectName("imageLabelName");
        imageLabelName->setGeometry(QRect(410, 270, 191, 101));
        imageLabelName->setTabletTracking(false);
        imageLabelName->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        imageLabelName->setStyleSheet(QString::fromUtf8(""));
        cancelImageButton = new QPushButton(inputGroupBox);
        cancelImageButton->setObjectName("cancelImageButton");
        cancelImageButton->setEnabled(true);
        cancelImageButton->setGeometry(QRect(550, 140, 21, 21));
        addMarkButton = new QPushButton(addGroupBox);
        addMarkButton->setObjectName("addMarkButton");
        addMarkButton->setEnabled(false);
        addMarkButton->setGeometry(QRect(440, 170, 31, 31));
        addMarkButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font-size:24px;\n"
"align:center;\n"
"padding-bottom:6px;\n"
"border: 2px solid #007f00; \n"
"background-color: #00ff00;\n"
"}\n"
"QPushButton::hover {\n"
"        border: 2px solid #007f00; \n"
"        background-color: #eaffea;\n"
"}\n"
"QPushButton::active {\n"
"border: 2px solid #005f00;\n"
"}"));
        addMarkButton->setAutoDefault(false);
        addMarkButton->setFlat(false);
        addMarkField = new QLineEdit(addGroupBox);
        addMarkField->setObjectName("addMarkField");
        addMarkField->setGeometry(QRect(260, 170, 151, 31));
        addMarkField->setStyleSheet(QString::fromUtf8("width: 150px;\n"
"height: 30px;\n"
"font: bold 10pt 'Arial';\n"
"border: 2px solid #4CAF50;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-size: 14px;\n"
"color: #333;\n"
"background-color: #F9F9F9;\n"
""));
        addMarkLabel = new QLabel(addGroupBox);
        addMarkLabel->setObjectName("addMarkLabel");
        addMarkLabel->setGeometry(QRect(260, 130, 101, 31));
        comboBoxModelAddBox = new QComboBox(addGroupBox);
        comboBoxModelAddBox->addItem(QString());
        comboBoxModelAddBox->setObjectName("comboBoxModelAddBox");
        comboBoxModelAddBox->setGeometry(QRect(620, 270, 151, 51));
        headerMainBoxAddBox = new QGroupBox(addGroupBox);
        headerMainBoxAddBox->setObjectName("headerMainBoxAddBox");
        headerMainBoxAddBox->setGeometry(QRect(-10, 0, 1931, 131));
        headerMainBoxAddBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-size:200%;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(91, 5, 67),stop:1 rgb(125, 69, 255));\n"
"color:white\n"
"}\n"
""));
        returnToMainPage = new QPushButton(headerMainBoxAddBox);
        returnToMainPage->setObjectName("returnToMainPage");
        returnToMainPage->setGeometry(QRect(1420, 40, 91, 51));
        addModelButton = new QPushButton(headerMainBoxAddBox);
        addModelButton->setObjectName("addModelButton");
        addModelButton->setGeometry(QRect(1300, 40, 91, 51));
        comboBoxVehicleTypeAddBox->raise();
        comboBoxMarkAddBox->raise();
        addObjectConfirmed->raise();
        labelVehicleTypeOnAddPage->raise();
        labelMarkOnAddPage->raise();
        addMarkButton->raise();
        addMarkField->raise();
        addMarkLabel->raise();
        inputGroupBox->raise();
        comboBoxModelAddBox->raise();
        headerMainBoxAddBox->raise();
        addModelGroupBox = new QGroupBox(centralwidget);
        addModelGroupBox->setObjectName("addModelGroupBox");
        addModelGroupBox->setGeometry(QRect(-1, -21, 1921, 1051));
        addModelGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: white;\n"
"}"));
        markSelectComboBox = new QComboBox(addModelGroupBox);
        markSelectComboBox->addItem(QString());
        markSelectComboBox->setObjectName("markSelectComboBox");
        markSelectComboBox->setGeometry(QRect(260, 270, 151, 51));
        typeSelectComboBox = new QComboBox(addModelGroupBox);
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->addItem(QString());
        typeSelectComboBox->setObjectName("typeSelectComboBox");
        typeSelectComboBox->setGeometry(QRect(440, 270, 151, 51));
        newModelField = new QLineEdit(addModelGroupBox);
        newModelField->setObjectName("newModelField");
        newModelField->setGeometry(QRect(260, 370, 151, 31));
        addNewModelButton = new QPushButton(addModelGroupBox);
        addNewModelButton->setObjectName("addNewModelButton");
        addNewModelButton->setGeometry(QRect(440, 370, 91, 31));
        headerMainBoxModelAddBox = new QGroupBox(addModelGroupBox);
        headerMainBoxModelAddBox->setObjectName("headerMainBoxModelAddBox");
        headerMainBoxModelAddBox->setGeometry(QRect(0, 0, 1931, 131));
        headerMainBoxModelAddBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-size:200%;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(91, 5, 67),stop:1 rgb(125, 69, 255));\n"
"color:white\n"
"}\n"
""));
        returToMainPageFromModel = new QPushButton(headerMainBoxModelAddBox);
        returToMainPageFromModel->setObjectName("returToMainPageFromModel");
        returToMainPageFromModel->setGeometry(QRect(1410, 40, 91, 51));
        returnToAddPage = new QPushButton(headerMainBoxModelAddBox);
        returnToAddPage->setObjectName("returnToAddPage");
        returnToAddPage->setGeometry(QRect(1290, 40, 91, 51));
        sizePolicy.setHeightForWidth(returnToAddPage->sizePolicy().hasHeightForWidth());
        returnToAddPage->setSizePolicy(sizePolicy);
        selectMarkLl = new QLabel(addModelGroupBox);
        selectMarkLl->setObjectName("selectMarkLl");
        selectMarkLl->setGeometry(QRect(260, 230, 121, 31));
        selectTypeLl = new QLabel(addModelGroupBox);
        selectTypeLl->setObjectName("selectTypeLl");
        selectTypeLl->setGeometry(QRect(440, 230, 121, 31));
        enterModelLl = new QLabel(addModelGroupBox);
        enterModelLl->setObjectName("enterModelLl");
        enterModelLl->setGeometry(QRect(260, 330, 151, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        addMarkButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mainGroupBox->setTitle(QString());
        showButton->setText(QCoreApplication::translate("MainWindow", "SHOW", nullptr));
        comboBoxModel->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));

        labelModel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        comboBoxVehicleType->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));
        comboBoxVehicleType->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\321\213\320\265", nullptr));
        comboBoxVehicleType->setItemText(2, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273\321\213", nullptr));
        comboBoxVehicleType->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272\320\270", nullptr));

        comboBoxVehicleType->setCurrentText(QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));
        comboBoxMark->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\321\213\320\265", nullptr));

        labelMark->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260:", nullptr));
        labelVehicleType->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        label->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\221\320\230\320\237\320\232\320\230", nullptr));
        headerMainBox->setTitle(QString());
        showAddGroupBox->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        addGroupBox->setTitle(QCoreApplication::translate("MainWindow", "box2", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\320\260\321\217", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273", nullptr));
        comboBoxVehicleTypeAddBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272", nullptr));

        comboBoxVehicleTypeAddBox->setCurrentText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        comboBoxMarkAddBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        addObjectConfirmed->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        labelVehicleTypeOnAddPage->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        labelMarkOnAddPage->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260:", nullptr));
        inputGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\277\320\276\320\273\321\217:", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265<br/>\320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265</p></body></html>", nullptr));
        selectImageButton->setText(QCoreApplication::translate("MainWindow", "+img", nullptr));
        imageLabelName->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275</p></body></html>", nullptr));
        cancelImageButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        addMarkButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        addMarkLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\321\200\320\272\321\203:", nullptr));
        comboBoxModelAddBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        headerMainBoxAddBox->setTitle(QString());
        returnToMainPage->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        addModelButton->setText(QCoreApplication::translate("MainWindow", "+\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        addModelGroupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        markSelectComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        typeSelectComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        typeSelectComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\321\213\320\265", nullptr));
        typeSelectComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\270\320\272\320\270", nullptr));
        typeSelectComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\234\320\276\321\202\320\276\321\206\320\270\320\272\320\273\321\213", nullptr));

        addNewModelButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        headerMainBoxModelAddBox->setTitle(QString());
        returToMainPageFromModel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        returnToAddPage->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        selectMarkLl->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\260\321\200\320\272\321\203:", nullptr));
        selectTypeLl->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277:", nullptr));
        enterModelLl->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\270:", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
