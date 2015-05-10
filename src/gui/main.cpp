/**
* @author xkondr01 xkucha20
* @file main.cpp
*/
#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    srand(time(0));
    game = new Game();
    game->show();
    game->showMainMenu();

    return a.exec();
}
