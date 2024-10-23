QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car.cpp \
    file_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    mark.cpp \
    mark_manager.cpp \
    moto_manager.cpp \
    motorbike.cpp \
    p_car_manager.cpp \
    passenger_car.cpp \
    truck.cpp \
    truck_manager.cpp \
    vehicle.cpp

HEADERS += \
    car.h \
    file_manager.h \
    mainwindow.h \
    mark.h \
    mark_manager.h \
    moto_manager.h \
    motorbike.h \
    p_car_manager.h \
    passenger_car.h \
    truck.h \
    truck_manager.h \
    vehicle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    motorbikes \
    passenger_cars \
    trucks
