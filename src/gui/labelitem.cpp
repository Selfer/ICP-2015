/**
* @author xkondr01 xkucha20
* @file labelitem.cpp
* @brief Vypisovani textu na souradnice
*/
#include "labelitem.h"
#include <QFont>

LabelItem::LabelItem(QString text, qreal x, qreal y){
    setPlainText(text);
    setPos(x, y);
    setFont(QFont("times",18));
}
