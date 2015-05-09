#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Game.h"

Player::Player(int index, QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    switch(index) {
        case 0:
            setPixmap(QPixmap(QString(":/images/hrac0.png")));
            break;
        case 1:
            setPixmap(QPixmap(QString(":/images/hrac1.png")));
            break;
        case 2:
            setPixmap(QPixmap(QString(":/images/hrac2.png")));
            break;
        case 3:
            setPixmap(QPixmap(QString(":/images/hrac3.png")));
            break;
    }
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
}

