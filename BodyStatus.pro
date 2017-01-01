#-------------------------------------------------
#
# Project created by QtCreator 2017-01-01T14:04:28
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BodyStatus
TEMPLATE = app
DEFINES += CHARTDIR_HIDE_OBSOLETE _CRT_SECURE_NO_WARNINGS
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    qchartviewer.cpp \
    sleepresult.cpp \
    style.cpp \
    sleep.cpp \
    sleepinput.cpp \
    db.cpp

HEADERS  += mainwindow.h \
    qchartviewer.h \
    sleepresult.h \
    style.h \
    sleep.h \
    sleepinput.h \
    db.h

INCLUDEPATH += $$PWD/include
win32:LIBS += $$PWD/lib/chartdir60.lib

RESOURCES += \
    res.qrc
