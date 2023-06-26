QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "$${PWD}/co2mon/libco2mon/include/"

SOURCES += \
    co2mon/libco2mon/src/co2mon.c \
    main.cpp \
    qcustomplot.cpp \
    widget.cpp

HEADERS += \
    co2mon/libco2mon/include/co2mon.h \
    qcustomplot.h \
    widget.h

FORMS += \
    widget.ui


