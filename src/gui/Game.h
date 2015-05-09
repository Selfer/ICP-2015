#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "qobject.h"
#include "Player.h"
#include "Score.h"
#include "chodba.h"
#include "predmet.h"
#include "../herni_plan.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void gameUpdate();
    void keyPressEvent(QKeyEvent * event);
    void rotate();
    QGraphicsScene * scene;
    Score * score;
    Chodba * chodba;
    Chodba * volna_chodba;
    Predmet * predmet;
private:
    HerniPlan plan;
    QList<Hrac> hraci;
    Hrac *hrac;
    int pocetHracu;
    int velikost;
    bool posunuto;
public slots:
    void startGame(int size = 7);
};

#endif
