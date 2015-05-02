#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T15:27:34
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ICP-2015
TEMPLATE = app


SOURCES += main.cpp\
        labyrintmain.cpp \
    herni_plan.cpp \
    hrac.cpp \
    labyrint.cpp

HEADERS  += labyrintmain.h \
    herni_plan.h \
    hrac.h \
    labyrint.h

FORMS    += labyrintmain.ui
