#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T11:06:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Labyrint
TEMPLATE = app


SOURCES += main.cpp \
    Score.cpp \
    Player.cpp \
    Health.cpp \
    Game.cpp \
    labyrint.cpp \
    hrac.cpp \
    herni_plan.cpp \
    predmet.cpp \
    chodba.cpp

HEADERS  += \
    Score.h \
    Player.h \
    Health.h \
    Game.h \
    labyrint.h \
    hrac.h \
    herni_plan.h \
    predmet.h \
    chodba.h

RESOURCES += \
    res.qrc
