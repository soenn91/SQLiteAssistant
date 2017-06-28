#-------------------------------------------------
#
# Project created by QtCreator 2017-06-06T13:09:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Database
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tablecreation.cpp \
    edittable.cpp

HEADERS  += mainwindow.h \
    tablecreation.h \
    edittable.h

FORMS    += mainwindow.ui \
    tablecreation.ui \
    edittable.ui
