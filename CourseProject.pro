QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car.cpp \
    combo_box_controller.cpp \
    duplicate_mark_exception.cpp \
    duplicate_model_exception.cpp \
    file_manager.cpp \
    filtermanager.cpp \
    main.cpp \
    mainwindow.cpp \
    mark.cpp \
    mark_container_manager.cpp \
    mark_manager.cpp \
    model.cpp \
    model_container_manager.cpp \
    model_manager.cpp \
    moto_manager.cpp \
    moto_show_display.cpp \
    motorbike.cpp \
    open_file_exception.cpp \
    p_car_manager.cpp \
    p_car_show_display.cpp \
    paginator.cpp \
    passenger_car.cpp \
    text_validation_exception..cpp \
    transport_loader.cpp \
    truck.cpp \
    truck_manager.cpp \
    truck_show_display.cpp \
    vehicle.cpp

HEADERS += \
    car.h \
    combo_box_controller.h \
    duplicate_mark_exception.h \
    duplicate_model_exception.h \
    file_manager.h \
    filter_manager.h \
    ids_container.h \
    mainwindow.h \
    mark.h \
    mark_container_manager.h \
    mark_manager.h \
    model.h \
    model_container_manager.h \
    model_manager.h \
    moto_manager.h \
    moto_show_display.h \
    motorbike.h \
    open_file_exception.h \
    p_car_manager.h \
    p_car_show_display.h \
    paginator.h \
    passenger_car.h \
    text_validation_exception.h \
    transport_loader.h \
    truck.h \
    truck_manager.h \
    truck_show_display.h \
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

RESOURCES += \
    resources.qrc
