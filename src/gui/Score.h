#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    /**
    * Vypise pocet bodu hrace
    * @param hrac cislo hrace(int)
    * @param skore pocet bodu hrace (int)
    */
    void vypis(int,int);
private:
    int score;
};

#endif
