#include "chodba.h"
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;

Chodba::Chodba(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

}

void Chodba::vykresliChodbu(int druh, int otoceni){
    //setRect(100,100,50,50);
    if(druh == 0)setPixmap(QPixmap(":/images/lcesta.jpg"));
    else if(druh == 1)setPixmap(QPixmap(":/images/tcesta.jpg"));
    else if(druh == 2)setPixmap(QPixmap(":/images/icesta.jpg"));
    setTransformOriginPoint(25,25);
    setRotation(otoceni*90);
}

