#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QBrush>
#include <QImage>
#include "labyrint.h"
#include "hrac.h"
#include "herni_plan.h"

Game::Game(QWidget *parent){
    int velikost = VELIKOST;
    int pocetHracu = 4;
    //vylosovani zacinajiciho hrace
    int hracNaTahu = rand() % pocetHracu;
    int vyhral = 0;
    bool posunuto = false;
    string prikaz;
    string posunuti;
    HerniPlan plan;
    plan.inicializace(velikost);
    int druha = plan.vrat_druh(2,1);
    Hrac hrac[pocetHracu];
    stack<string> historie;
    for(int i = 0; i < pocetHracu; i++){
        hrac[i].inicializace(i, velikost);
        plan.prirad_predmet(&hrac[i]);
    }


    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/pozadi.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    /*player = new Player();

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);*/
    int druh;
    int otoceni;
    int cPredmetu;

    for(int i = 0; i < VELIKOST; i++){
        for(int j = 0; j < VELIKOST; j++){
            druh = plan.vrat_druh(i,j);
            otoceni = plan.vrat_otoceni(i,j);
            cPredmetu = plan.vrat_predmet(i,j);

            chodba = new Chodba();
            chodba->vykresliChodbu(druh,otoceni);
            chodba->setPos(i*52,j*52);
            scene->addItem(chodba);
            if(cPredmetu >= 0){
                predmet = new Predmet();
                predmet->vykresliPredmet(cPredmetu);
                predmet->setPos(20+i*52,20+j*52);
                scene->addItem(predmet);
            }
        }      
    }
    
    druh = plan.vrat_druh(-1,-1);
    otoceni = plan.vrat_otoceni(-1,-1);
    cPredmetu = plan.vrat_predmet(-1,-1);

    chodba = new Chodba();
    chodba->vykresliChodbu(druh,otoceni);
    chodba->setPos(50+(VELIKOST*52),100);
    scene->addItem(chodba);

    if(cPredmetu >= 0){
        predmet = new Predmet();
        predmet->vykresliPredmet(cPredmetu);
        predmet->setPos(70+(VELIKOST*52),120);
        scene->addItem(predmet);
    }

    for(int i = 0; i < pocetHracu; i++){
        int radek;
        int sloupec;
        hrac[i].vrat_pozici(&radek,&sloupec);
        
        player = new Player();
        //player->setFlag(QGraphicsItem::ItemIsFocusable);
        //player->setFocus();
        player->setPos(15+radek*52,15+sloupec*52);
        scene->addItem(player);

        score = new Score();
        score->vypis(i,hrac[i].pocet_bodu());
        score->setPos(700,i*25);
        scene->addItem(score);
    }

    show();
}
