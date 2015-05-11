#ifndef GAME_H
#define GAME_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QBrush>
#include <QImage>
#include <QList>
#include <QKeyEvent>
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
    /**
    * Rotace volne chodby
    */
    void rotate();
    /**
    * Pohyb hrace
    * @param dir smer pohybu hrace(char *)
    */
    void movePlayer(const char *dir);
    /**
    * Vykresleni herniho menu
    */
    void showInGameMenu();
    /**
    * Vykresleni panelu
    * @param x x-pozice(int)
    * @param y y-pozice(int)
    * @param width sirka panelu(int)
    * @param height vyska panelu(int)
    * @param color barva panelu(QColor)
    * @param opacity pruhlednost panelu(double)
    */
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    /**
    * Vsunuti chodby
    * @param index misto, kde bylo zasunuto(char *)
    */
    void insertStone(const char *index);
    bool isEvenBorder(int x, int y);
    /**
    * Vypise horni popisky
    */
    void createTopLabels();
    /**
    * Vypise dolni popisky
    */
    void createBottomLabels();
    /**
    * Vypise levou stranu popisku
    */
    void createLeftLabels();
    /**
    * Vypise pravou stranu popisku
    */
    void createRightLabels();
    /**
    * Vypise popisky k hernimu planu
    */
    void createLabels();
    /**
    * Vykresli menu po konci hry
    * @param player_id cislo viteze(int)
    */
    void showGameOverMenu(int player_id);
public slots:
    void startGame(int size = 7, int players = 2);
    void updateGame();
    void showMainMenu();
    void showNewGameMenu();
};

#endif
