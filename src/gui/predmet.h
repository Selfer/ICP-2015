#ifndef PREDMET_H
#define PREDMET_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Predmet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Predmet(QGraphicsItem * parent=0);
    void vykresliPredmet(int cislo);
};

#endif // PREDMET_H
