#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T11:06:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Labyrint
TEMPLATE = app


SOURCES += main.cpp \
    Score.cpp \
    Player.cpp \
    Game.cpp \
    predmet.cpp \
    chodba.cpp \
    ../herni_plan.cpp \
    ../hrac.cpp \
    button.cpp \
    labelitem.cpp

HEADERS  += \
    Score.h \
    Player.h \
    Game.h \
    predmet.h \
    chodba.h \
    ../herni_plan.h \
    ../hrac.h \
    button.h \
    labelitem.h

RESOURCES += \
    res.qrc
