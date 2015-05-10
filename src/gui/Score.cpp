/**
* @author xkondr01 xkucha20
* @file Score.cpp
* @brief Vypisovani textu informujici o skore hry
*/

#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

}

void Score::vypis(int hrac, int skore){
    setPlainText(QString("Hrac ") + QString::number(hrac+1) + QString(":\t") + QString::number(skore));
    if(hrac == 0) setDefaultTextColor(Qt::red);
    else if(hrac == 1) setDefaultTextColor(Qt::green);
    else if(hrac == 2) setDefaultTextColor(Qt::blue);
    else if(hrac == 3) setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

int Score::getScore(){
    return score;
}
