#ifndef GAME_H
#define GAME_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QBrush>
#include <QImage>
#include <QList>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QComboBox>
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
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    QGraphicsScene * scene;
    Score * score;
    Chodba * chodba;
    Chodba * volna_chodba;
    Predmet * predmet;
private:
    HerniPlan plan;
    QList<Player*> hrac_gui;
    Hrac *hrac;
    int pocetHracu;
    int hracNaTahu;
    int velikost;
    int labels_num;
    bool running;
    bool menu;
    bool posunuto;
    bool hrac_posunul;
    bool can_move;
    stack<string> historie;
    QComboBox *size_cbox;
    QComboBox *players_cbox;
    void rotate();
    void movePlayer(const char *dir);
    void showInGameMenu();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void insertStone(const char *index);
    bool isEvenBorder(int x, int y);
    void createTopLabels();
    void createBottomLabels();
    void createLeftLabels();
    void createRightLabels();
    void createLabels();
    void showGameOverMenu(int player_id);
public slots:
    void startGame(int size = 7, int players = 2);
    void updateGame();
    void showMainMenu();
    void showNewGameMenu();
};

#endif
