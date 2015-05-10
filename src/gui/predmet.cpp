/**
* @author xkondr01 xkucha20
* @file predmet.cpp
* @brief Nastaveni graficke podoby predmetu
*/
#include "predmet.h"
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;

Predmet::Predmet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

}

void Predmet::vykresliPredmet(int cislo){
    //setRect(100,100,50,50);
    if(cislo == 0)setPixmap(QPixmap(":/images/p0.png"));
    else if(cislo == 1)setPixmap(QPixmap(":/images/p1.png"));
    else if(cislo == 2)setPixmap(QPixmap(":/images/p2.png"));
    else if(cislo == 3)setPixmap(QPixmap(":/images/p3.png"));
    else if(cislo == 4)setPixmap(QPixmap(":/images/p4.png"));
    else if(cislo == 5)setPixmap(QPixmap(":/images/p5.png"));
    else if(cislo == 6)setPixmap(QPixmap(":/images/p6.png"));
    else if(cislo == 7)setPixmap(QPixmap(":/images/p7.png"));
    else if(cislo == 8)setPixmap(QPixmap(":/images/p8.png"));
    else if(cislo == 9)setPixmap(QPixmap(":/images/p9.png"));
    else if(cislo == 10)setPixmap(QPixmap(":/images/p10.png"));
    else if(cislo == 11)setPixmap(QPixmap(":/images/p11.png"));
    else if(cislo == 12)setPixmap(QPixmap(":/images/p12.png"));
    else if(cislo == 13)setPixmap(QPixmap(":/images/p13.png"));
    else if(cislo == 14)setPixmap(QPixmap(":/images/p14.png"));
    else if(cislo == 15)setPixmap(QPixmap(":/images/p15.png"));
    else if(cislo == 16)setPixmap(QPixmap(":/images/p16.png"));
    else if(cislo == 17)setPixmap(QPixmap(":/images/p17.png"));
    else if(cislo == 18)setPixmap(QPixmap(":/images/p18.png"));
    else if(cislo == 19)setPixmap(QPixmap(":/images/p19.png"));
    else if(cislo == 20)setPixmap(QPixmap(":/images/p20.png"));
    else if(cislo == 21)setPixmap(QPixmap(":/images/p21.png"));
    else if(cislo == 22)setPixmap(QPixmap(":/images/p22.png"));
    else if(cislo == 23)setPixmap(QPixmap(":/images/p23.png"));
}


