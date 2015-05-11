#ifndef CHODBA_H
#define CHODBA_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Chodba: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Chodba(QGraphicsItem * parent=0);
    /**
    * Vykresleni chodby
    * @param druh druh chodby(int)
    * @param otoceni otoceni chodby(int)
    */
    void vykresliChodbu(int druh, int otoceni);

};

#endif // CHODBA_H
