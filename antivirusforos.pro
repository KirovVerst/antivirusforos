#-------------------------------------------------
#
# Project created by QtCreator 2014-11-26T10:46:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = antivirusforos
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    checkFile.cpp \
    GetHash.cpp
win32:RC_FILE = antivirusforos.rc
HEADERS  += mainwindow.h \
    checkFile.h \
    GetHash.h

FORMS    += mainwindow.ui
