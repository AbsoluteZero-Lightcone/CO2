QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    load_param.cpp \
    main.cpp \
    mainwindow.cpp \
    physics_system.cpp \
    sliders.cpp

HEADERS += \
    load_param.h \
    mainwindow.h \
    physics_system.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    CO2_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/arrow.qrc
