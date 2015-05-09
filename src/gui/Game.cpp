#include "Game.h"
#include "button.h"

Game::Game(QWidget *parent){
    running = false;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setBackgroundBrush(QBrush(QImage(":/images/pozadi.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

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
            updateGame();
            historie.push("A");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_B) {
        posunuto = plan.posun("B", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("B");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_C) {
        posunuto = plan.posun("C", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("C");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_D) {
        posunuto = plan.posun("D", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("D");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_E) {
        posunuto = plan.posun("E", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("E");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_I) {
        posunuto = plan.posun("I", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("I");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_J) {
        posunuto = plan.posun("J", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("J");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_K) {
        posunuto = plan.posun("K", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("K");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_L) {
        posunuto = plan.posun("L", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("L");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_M) {
        posunuto = plan.posun("M", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("M");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_O) {
        posunuto = plan.posun("O", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("O");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_P) {
        posunuto = plan.posun("P", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("P");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_Q) {
        posunuto = plan.posun("Q", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("Q");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_R) {
        posunuto = plan.posun("R", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("R");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_S) {
        posunuto = plan.posun("S", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("S");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_U) {
        posunuto = plan.posun("U", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("U");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_V) {
        posunuto = plan.posun("V", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("V");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_W) {
        posunuto = plan.posun("W", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("W");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_X) {
        posunuto = plan.posun("X", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("X");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_Y) {
        posunuto = plan.posun("Y", hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            scene->clear();
            updateGame();
            historie.push("Y");
            historie.push(vPolicko);
        }
    }
    else if (event->key() == Qt::Key_Left){
        int x;
        int y;
        plan.pohyb_hrace("l",velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        int posunx = 30;
        int posuny = 30;
        if(hracNaTahu == 1) {
            posunx = 40;
            posuny = 40;
        }
        else if(hracNaTahu == 2) posuny = 40;
        else if(hracNaTahu == 3) posunx = 40;
        hrac_gui[hracNaTahu]->setPos(posuny+y*52,posunx+x*52);
        qDebug() << "Jdu na pozici " << x << ", " << y;
    }
    else if (event->key() == Qt::Key_Right){
        int x;
        int y;
        plan.pohyb_hrace("p",velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        int posunx = 30;
        int posuny = 30;
        if(hracNaTahu == 1) {
            posunx = 40;
            posuny = 40;
        }
        else if(hracNaTahu == 2) posuny = 40;
        else if(hracNaTahu == 3) posunx = 40;
        hrac_gui[hracNaTahu]->setPos(posuny+y*52,posunx+x*52);
        qDebug() << "Jdu na pozici " << x << ", " << y;
    }
    else if (event->key() == Qt::Key_Up){
        int x;
        int y;
        plan.pohyb_hrace("n",velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        int posunx = 30;
        int posuny = 30;
        if(hracNaTahu == 1) {
            posunx = 40;
            posuny = 40;
        }
        else if(hracNaTahu == 2) posuny = 40;
        else if(hracNaTahu == 3) posunx = 40;
        hrac_gui[hracNaTahu]->setPos(posuny+y*52,posunx+x*52);
        qDebug() << "Jdu na pozici " << x << ", " << y;
    }
    else if (event->key() == Qt::Key_Down){
        int x;
        int y;
        plan.pohyb_hrace("d",velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        int posunx = 30;
        int posuny = 30;
        if(hracNaTahu == 1) {
            posunx = 40;
            posuny = 40;
        }
        else if(hracNaTahu == 2) posuny = 40;
        else if(hracNaTahu == 3) posunx = 40;
        hrac_gui[hracNaTahu]->setPos(posuny+y*52,posunx+x*52);
        qDebug() << "Jdu na pozici " << x << ", " << y;
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        hracNaTahu++;
        if(hracNaTahu == pocetHracu) {
            hracNaTahu = 0;
        }
        qDebug() << "Dalsi hrac: " << hracNaTahu << hrac[hracNaTahu].hledany_predmet();
    }
    else if (event->key() == Qt::Key_Control) {
        predmet = new Predmet();
        predmet->vykresliPredmet(hrac[hracNaTahu].hledany_predmet());
        predmet->setPos(65+(velikost*52),170);
        scene->addItem(predmet);
        qDebug() << "Dalsi hrac: " << hracNaTahu << hrac[hracNaTahu].hledany_predmet();
    }
    else if (event->key() == Qt::Key_Escape) {
        if(running) showInGameMenu();
    }
}
void Game::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Control) {
        updateGame();
    }
}

void Game::rotate() {
    plan.otoc();
    int druh = plan.vrat_druh(-1,-1);
    int otoceni = plan.vrat_otoceni(-1,-1);
    int cPredmetu = plan.vrat_predmet(-1,-1);
    volna_chodba->vykresliChodbu(druh,otoceni);
}

void Game::showMainMenu(){
    scene->clear();
    Button *play_btn = new Button(QString("Nova hra"));
    int x = scene->width()/2 - play_btn->boundingRect().width()/2;
    int y = 250;
    play_btn->setPos(x, y);
    connect(play_btn, SIGNAL(clicked()), this, SLOT(startGame()));
    scene->addItem(play_btn);

    Button *exit_btn = new Button(QString("Konec"));
    x = scene->width()/2 - exit_btn->boundingRect().width()/2;
    y = 500;
    exit_btn->setPos(x, y);
    connect(exit_btn, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(exit_btn);
}

void Game::showInGameMenu(){
    int n = scene->items().size();
    for(int i = 0; i < n; i++) {
        scene->items()[i]->setEnabled(false);
    }
    drawPanel(0, 0, 1024, 768, QColor(Qt::gray), 0.65);
    drawPanel(0,0,400,600,QColor(Qt::cyan), 1);

    Button *resume_btn = new Button(QString("Vratit do hry"));
    int x = scene->width()/2 - resume_btn->boundingRect().width()/2;
    int y = 250;
    resume_btn->setPos(x, y);
    connect(resume_btn, SIGNAL(clicked()), this, SLOT(updateGame()));
    scene->addItem(resume_btn);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush br;
    br.setStyle(Qt::SolidPattern);
    br.setColor(color);
    panel->setBrush(br);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::updateGame(){
    scene->clear();
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
            chodba->setPos(20+j*52,20+i*52);
            scene->addItem(chodba);
            if(cPredmetu >= 0){
                predmet = new Predmet();
                predmet->vykresliPredmet(cPredmetu);
                predmet->setPos(35+j*52,35+i*52);
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
        predmet->setPos(65+(velikost*52),115);
        scene->addItem(predmet);
    }
    hrac_gui.clear();
    for(int i = 0; i < pocetHracu; i++){
        int radek;
        int sloupec;
        hrac_gui << new Player(i);
        hrac[i].vrat_pozici(&radek,&sloupec);
        int posunx = 30;
        int posuny = 30;
        if(i == 1) {
            posunx = 40;
            posuny = 40;
        }
        else if(i == 2) posuny = 40;
        else if(i == 3) posunx = 40;
        hrac_gui[i]->setPos(posuny+sloupec*52,posunx+radek*52);
        scene->addItem(hrac_gui[i]);

        score = new Score();
        score->vypis(i,hrac[i].pocet_bodu());
        score->setPos(900,i*25);
        scene->addItem(score);
    }

}

void Game::startGame(int size){
    scene->clear();
    running = true;
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
        plan.prirad_predmet(&hrac[i]);
    }
    updateGame();
    show();
}

