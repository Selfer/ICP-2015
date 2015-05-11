#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    /**
    * Vykresli hrace
    * @param index cislo hrace(int)
    */
    Player(int index, QGraphicsItem * parent=0);
};

#endif
