#include "Game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QBrush>
#include <QImage>
#include <QList>
#include <QKeyEvent>
#include <QDebug>

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setBackgroundBrush(QBrush(QImage(":/images/pozadi.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    /*player = new Player();

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);*/

}

void Game::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
        rotate();
    }
    else if (event->key() == Qt::Key_A) {
        posunuto = plan.posun("A", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            gameUpdate();
            historie.push("A");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_Left){
        int x;
        int y;
        plan.pohyb_hrace("l",velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        hrac_gui[hracNaTahu]->setPos(40+x*52,40+y*52);
        qDebug() << "Jdu do leva";
    }
    else if (event->key() == Qt::Key_Right){
        int x;
        int y;
        plan.pohyb_hrace("p",velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        hrac_gui[hracNaTahu]->setPos(40+x*52,40+y*52);
        qDebug() << "Jdu do prava";
    }
}
void Game::rotate() {
    plan.otoc();
    int druh = plan.vrat_druh(-1,-1);
    int otoceni = plan.vrat_otoceni(-1,-1);
    int cPredmetu = plan.vrat_predmet(-1,-1);
    volna_chodba->vykresliChodbu(druh,otoceni);
}

void Game::gameUpdate()
{

    int druh;
    int otoceni;
    int cPredmetu;

    for(int i = 0; i < velikost; i++){
        for(int j = 0; j < velikost; j++){
            druh = plan.vrat_druh(i,j);
            otoceni = plan.vrat_otoceni(i,j);
            cPredmetu = plan.vrat_predmet(i,j);

            chodba = new Chodba();
            chodba->vykresliChodbu(druh,otoceni);
            chodba->setPos(20+i*52,20+j*52);
            scene->addItem(chodba);
            if(cPredmetu >= 0){
                predmet = new Predmet();
                predmet->vykresliPredmet(cPredmetu);
                predmet->setPos(40+i*52,40+j*52);
                scene->addItem(predmet);
            }
        }
    }

    druh = plan.vrat_druh(-1,-1);
    otoceni = plan.vrat_otoceni(-1,-1);
    cPredmetu = plan.vrat_predmet(-1,-1);

    volna_chodba = new Chodba();
    volna_chodba->vykresliChodbu(druh,otoceni);
    volna_chodba->setPos(50+(velikost*52),100);
    scene->addItem(volna_chodba);

    if(cPredmetu >= 0){
        predmet = new Predmet();
        predmet->vykresliPredmet(cPredmetu);
        predmet->setPos(70+(velikost*52),120);
        scene->addItem(predmet);
    }

    for(int i = 0; i < pocetHracu; i++){
        int radek;
        int sloupec;
        hrac[i].vrat_pozici(&radek,&sloupec);

        hrac_gui[i]->setPos(15+radek*52,15+sloupec*52);
        scene->addItem(hrac_gui[i]);

        score = new Score();
        score->vypis(i,hrac[i].pocet_bodu());
        score->setPos(700,i*25);
        scene->addItem(score);
    }

}

void Game::startGame(int size){
    velikost = size;
    pocetHracu = 4;
    //vylosovani zacinajiciho hrace
    hracNaTahu = rand() % pocetHracu;
    int vyhral = 0;
    bool posunuto = false;
    string prikaz;
    string posunuti;
    plan.inicializace(velikost);
    stack<string> historie;
    hrac = new Hrac[pocetHracu];
    for(int i = 0; i < pocetHracu; i++){
        hrac[i] = Hrac(i, velikost);
        hrac_gui << new Player(i);
        plan.prirad_predmet(&hrac[i]);
    }
    gameUpdate();
    show();
}

