#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    setRect(0,0,200,60);
    QBrush br;
    br.setStyle(Qt::SolidPattern);
    br.setColor(Qt::lightGray);
    setBrush(br);


    text = new QGraphicsTextItem(name, this);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    int y = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(x, y);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}
