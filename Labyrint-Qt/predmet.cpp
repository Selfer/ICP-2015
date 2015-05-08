#include "predmet.h"
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;

Predmet::Predmet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

}

void Predmet::vykresliPredmet(int cislo){
    //setRect(100,100,50,50);
    if(cislo == 0)setPixmap(QPixmap(":/images/p0.png"));
    else if(cislo == 1)setPixmap(QPixmap(":/predmety/predmety/p1.png"));
    else if(cislo == 2)setPixmap(QPixmap(":/predmety/predmety/p2.png"));
    else if(cislo == 3)setPixmap(QPixmap(":/predmety/predmety/p3.png"));
    else if(cislo == 4)setPixmap(QPixmap(":/predmety/predmety/p4.png"));
    else if(cislo == 5)setPixmap(QPixmap(":/predmety/predmety/p5.png"));
    else if(cislo == 6)setPixmap(QPixmap(":/predmety/predmety/p6.png"));
    else if(cislo == 7)setPixmap(QPixmap(":/predmety/predmety/p7.png"));
    else if(cislo == 8)setPixmap(QPixmap(":/predmety/predmety/p8.png"));
    else if(cislo == 9)setPixmap(QPixmap(":/predmety/predmety/p9.png"));
    else if(cislo == 10)setPixmap(QPixmap(":/predmety/predmety/p10.png"));
    else if(cislo == 11)setPixmap(QPixmap(":/predmety/predmety/p11.png"));
    else if(cislo == 12)setPixmap(QPixmap(":/predmety/predmety/p12.png"));
    else if(cislo == 13)setPixmap(QPixmap(":/predmety/predmety/p13.png"));
    else if(cislo == 14)setPixmap(QPixmap(":/predmety/predmety/p14.png"));
    else if(cislo == 15)setPixmap(QPixmap(":/predmety/predmety/p15.png"));
    else if(cislo == 16)setPixmap(QPixmap(":/predmety/predmety/p16.png"));
    else if(cislo == 17)setPixmap(QPixmap(":/predmety/predmety/p17.png"));
    else if(cislo == 18)setPixmap(QPixmap(":/predmety/predmety/p18.png"));
    else if(cislo == 19)setPixmap(QPixmap(":/predmety/predmety/p19.png"));
}


