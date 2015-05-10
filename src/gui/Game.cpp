#include "Game.h"
#include "button.h"
#include "labelitem.h"

Game::Game(QWidget *parent){
    running = false;
    hrac_posunul = false;
    menu = false;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setBackgroundBrush(QBrush(QImage(":/images/pozadi.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

}

void Game::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    if (key == Qt::Key_Space){
        rotate();
    }
    else if (key == Qt::Key_A || key == Qt::Key_B || key == Qt::Key_C || key == Qt::Key_D ||
             key == Qt::Key_E || key == Qt::Key_I || key == Qt::Key_J || key == Qt::Key_K ||
             key == Qt::Key_L || key == Qt::Key_M || key == Qt::Key_O || key == Qt::Key_P ||
             key == Qt::Key_Q || key == Qt::Key_R || key == Qt::Key_S || key == Qt::Key_U ||
             key == Qt::Key_V || key == Qt::Key_W || key == Qt::Key_X || key == Qt::Key_Y) {
        insertStone(event->text().toUpper().toStdString().c_str());
    }
    else if (key == Qt::Key_Left){
        movePlayer("l");
    }
    else if (key == Qt::Key_Right){
        movePlayer("p");
    }
    else if (key == Qt::Key_Up){
        movePlayer("n");
    }
    else if (key == Qt::Key_Down){
        movePlayer("d");
    }
    else if (key == Qt::Key_Enter || key == Qt::Key_Return) {
        hracNaTahu++;
        if(hracNaTahu == pocetHracu) {
            hracNaTahu = 0;
        }
        qDebug() << "Dalsi hrac: " << hracNaTahu << hrac[hracNaTahu].hledany_predmet();
        hrac_posunul = false;
        posunuto = false;
        updateGame();
    }
    else if (key == Qt::Key_Control) {
        predmet = new Predmet();
        predmet->vykresliPredmet(hrac[hracNaTahu].hledany_predmet());
        predmet->setPos(125+(velikost*52),170);
        scene->addItem(predmet);
        qDebug() << "Dalsi hrac: " << hracNaTahu << hrac[hracNaTahu].hledany_predmet();
    }
    else if (key == Qt::Key_Escape) {
        if(running && !menu) showInGameMenu();
        else if(menu) updateGame();
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

void Game::insertStone(const char *index)
{
    if(!posunuto) {
        posunuto = plan.posun(index, hrac, pocetHracu);
        string vPolicko = plan.vlozene_policko();
        if(posunuto == false) {
            cout << "Nelze vsunout policko na tohle misto" << endl;
        }
        else {
            hrac_posunul = true;
            scene->clear();
            updateGame();
            historie.push(index);
            historie.push(vPolicko);
        }
    }
}

void Game::movePlayer(const char *dir){
    if (hrac_posunul) {
        int x;
        int y;
        plan.pohyb_hrace(dir,velikost,&hrac[hracNaTahu],hracNaTahu,&historie);
        hrac[hracNaTahu].vrat_pozici(&x, &y);
        int posunx = 70;
        int posuny = 70;
        if(hracNaTahu == 1) {
            posunx = 80;
            posuny = 80;
        }
        else if(hracNaTahu == 2) posuny = 80;
        else if(hracNaTahu == 3) posunx = 80;
        hrac_gui[hracNaTahu]->setPos(posuny+y*52,posunx+x*52);
        qDebug() << "Jdu na pozici " << x << ", " << y;
    }
}

void Game::showMainMenu(){
    scene->clear();
    Button *play_btn = new Button(QString("Nova hra"));
    int x = scene->width()/2 - play_btn->boundingRect().width()/2;
    int y = 250;
    play_btn->setPos(x, y);
    connect(play_btn, SIGNAL(clicked()), this, SLOT(showNewGameMenu()));
    scene->addItem(play_btn);

    Button *exit_btn = new Button(QString("Konec"));
    x = scene->width()/2 - exit_btn->boundingRect().width()/2;
    y = 500;
    exit_btn->setPos(x, y);
    connect(exit_btn, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(exit_btn);
}

void Game::showNewGameMenu(){
    scene->clear();

    QGraphicsTextItem *players_lbl = new QGraphicsTextItem(QString("Pocet hracu:"));
    players_lbl->setPos(350, 270);
    scene->addItem(players_lbl);

    players_cbox = new QComboBox;
    players_cbox->addItem(QString("2"));
    players_cbox->addItem(QString("3"));
    players_cbox->addItem(QString("4"));
    players_cbox->move(430, 270);
    scene->addWidget(players_cbox);

    QGraphicsTextItem *board_size_lbl = new QGraphicsTextItem(QString("Velikost desky:"));
    board_size_lbl->setPos(490, 270);
    scene->addItem(board_size_lbl);

    size_cbox = new QComboBox;
    size_cbox->addItem(QString("5"));
    size_cbox->addItem(QString("7"));
    size_cbox->addItem(QString("9"));
    size_cbox->addItem(QString("11"));
    size_cbox->setCurrentIndex(1);
    size_cbox->move(570, 270);
    scene->addWidget(size_cbox);


    Button *play_btn = new Button(QString("Zacit"));
    int x = scene->width()/2 - play_btn->boundingRect().width()/2;
    int y = 360;
    play_btn->setPos(x, y);
    connect(play_btn, SIGNAL(clicked()), this, SLOT(startGame()));
    scene->addItem(play_btn);

    Button *back_btn = new Button(QString("Zpet"));
    x = scene->width()/2 - back_btn->boundingRect().width()/2;
    y += 75;
    back_btn->setPos(x, y);
    connect(back_btn, SIGNAL(clicked()), this, SLOT(showMainMenu()));
    scene->addItem(back_btn);
}

void Game::showInGameMenu(){
    menu = true;
    int n = scene->items().size();
    for(int i = 0; i < n; i++) {
        scene->items()[i]->setEnabled(false);
    }
    drawPanel(0, 0, 1024, 768, QColor(Qt::gray), 0.65);
    drawPanel(1024/2 - 200,200,400,400,QColor(Qt::cyan), 0.85);

    Button *resume_btn = new Button(QString("Vratit do hry"));
    int x = scene->width()/2 - resume_btn->boundingRect().width()/2;
    int y = 250;
    resume_btn->setPos(x, y);
    connect(resume_btn, SIGNAL(clicked()), this, SLOT(updateGame()));
    scene->addItem(resume_btn);

    Button *save_game_btn = new Button(QString("Ulozit hru"));
    x = scene->width()/2 - save_game_btn->boundingRect().width()/2;
    y += 75;
    save_game_btn->setPos(x, y);
    //connect(save_game_btn, SIGNAL(clicked()), this, SLOT(showMainMenu()));
    scene->addItem(save_game_btn);

    Button *back_to_menu_btn = new Button(QString("Vratit do menu"));
    x = scene->width()/2 - back_to_menu_btn->boundingRect().width()/2;
    y += 75;
    back_to_menu_btn->setPos(x, y);
    connect(back_to_menu_btn, SIGNAL(clicked()), this, SLOT(showMainMenu()));
    scene->addItem(back_to_menu_btn);

    Button *exit_btn = new Button(QString("Konec"));
    x = scene->width()/2 - exit_btn->boundingRect().width()/2;
    y += 75;
    exit_btn->setPos(x, y);
    connect(exit_btn, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(exit_btn);
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

void Game::createTopLabels() {
    if(labels_num >= 2) {
        QGraphicsTextItem *lbl_a = new LabelItem("A", 125, 25);
        scene->addItem(lbl_a);
        QGraphicsTextItem *lbl_b = new LabelItem("B", 230, 25);
        scene->addItem(lbl_b);
    }
    if(labels_num >= 3) {
        QGraphicsTextItem *lbl_c = new LabelItem("C", 335, 25);
        scene->addItem(lbl_c);
    }
    if(labels_num >= 4) {
        QGraphicsTextItem *lbl_d = new LabelItem("D", 440, 25);
        scene->addItem(lbl_d);
    }
    if(labels_num >= 5) {
        QGraphicsTextItem *lbl_e = new LabelItem("E", 545, 25);
        scene->addItem(lbl_e);
    }
}

void Game::createRightLabels() {
    if(labels_num >= 2) {
        QGraphicsTextItem *lbl_i = new LabelItem("I", 75+velikost*52, 120);
        scene->addItem(lbl_i);
        QGraphicsTextItem *lbl_j = new LabelItem("J", 75+velikost*52, 220);
        scene->addItem(lbl_j);
    }
    if(labels_num >= 3) {
        QGraphicsTextItem *lbl_k = new LabelItem("K", 75+velikost*52, 325);
        scene->addItem(lbl_k);
    }
    if(labels_num >= 4) {
        QGraphicsTextItem *lbl_l = new LabelItem("L", 75+velikost*52, 430);
        scene->addItem(lbl_l);
    }
    if(labels_num >= 5) {
        QGraphicsTextItem *lbl_m = new LabelItem("M", 75+velikost*52, 535);
        scene->addItem(lbl_m);
    }
}

void Game::createBottomLabels() {
    if(labels_num >= 2) {
        QGraphicsTextItem *lbl_s = new LabelItem("S", 125, 70+velikost*52);
        scene->addItem(lbl_s);
        QGraphicsTextItem *lbl_r = new LabelItem("R", 225, 70+velikost*52);
        scene->addItem(lbl_r);
    }
    if(labels_num >= 3) {
        QGraphicsTextItem *lbl_q = new LabelItem("Q", 330, 70+velikost*52);
        scene->addItem(lbl_q);
    }
    if(labels_num >= 4) {
        QGraphicsTextItem *lbl_p = new LabelItem("P", 435, 70+velikost*52);
        scene->addItem(lbl_p);
    }
    if(labels_num >= 5) {
        QGraphicsTextItem *lbl_o = new LabelItem("O", 540, 70+velikost*52);
        scene->addItem(lbl_o);
    }
}

void Game::createLeftLabels() {
    if(labels_num >= 2) {
        QGraphicsTextItem *lbl_y = new LabelItem("Y", 25, 125);
        scene->addItem(lbl_y);
        QGraphicsTextItem *lbl_x = new LabelItem("X", 25, 230);
        scene->addItem(lbl_x);
    }
    if(labels_num >= 3) {
        QGraphicsTextItem *lbl_w = new LabelItem("W", 25, 335);
        scene->addItem(lbl_w);
    }
    if(labels_num >= 4) {
        QGraphicsTextItem *lbl_v = new LabelItem("V", 25, 440);
        scene->addItem(lbl_v);
    }
    if(labels_num >= 5) {
        QGraphicsTextItem *lbl_u = new LabelItem("U", 25, 545);
        scene->addItem(lbl_u);
    }
}

void Game::createLabels() {
    createTopLabels();
    createRightLabels();
    createBottomLabels();
    createLeftLabels();
}

void Game::updateGame(){
    scene->clear();
    menu = false;
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
            chodba->setPos(60+j*52,60+i*52);
            scene->addItem(chodba);
            if(cPredmetu >= 0){
                predmet = new Predmet();
                predmet->vykresliPredmet(cPredmetu);
                predmet->setPos(75+j*52,75+i*52);
                scene->addItem(predmet);
            }
        }
    }
    createLabels();
    druh = plan.vrat_druh(-1,-1);
    otoceni = plan.vrat_otoceni(-1,-1);
    cPredmetu = plan.vrat_predmet(-1,-1);

    volna_chodba = new Chodba();
    volna_chodba->vykresliChodbu(druh,otoceni);
    volna_chodba->setPos(110+(velikost*52),100);
    scene->addItem(volna_chodba);

    if(cPredmetu >= 0){
        predmet = new Predmet();
        predmet->vykresliPredmet(cPredmetu);
        predmet->setPos(125+(velikost*52),115);
        scene->addItem(predmet);
    }
    hrac_gui.clear();
    drawPanel(820, 0, 160, pocetHracu * 28, QColor(Qt::gray), 0.90);
    int y_pos;
    switch (hracNaTahu) {
        case 0:
            y_pos = 3;
            break;
        case 1:
            y_pos = 28;
            break;
        case 2:
            y_pos = 54;
            break;
        case 3:
            y_pos = 78;
            break;
    }

    drawPanel(820,y_pos, 160, 25, QColor(Qt::lightGray), 0.90);
    for(int i = 0; i < pocetHracu; i++){
        int radek;
        int sloupec;
        hrac_gui << new Player(i);
        hrac[i].vrat_pozici(&radek,&sloupec);
        int posunx = 70;
        int posuny = 70;
        if(i == 1) {
            posunx = 80;
            posuny = 80;
        }
        else if(i == 2) posuny = 80;
        else if(i == 3) posunx = 80;
        hrac_gui[i]->setPos(posuny+sloupec*52,posunx+radek*52);
        scene->addItem(hrac_gui[i]);

        score = new Score();
        score->vypis(i,hrac[i].pocet_bodu());
        score->setPos(850,i*25);
        scene->addItem(score);
    }

}

void Game::startGame(int size, int players){
    pocetHracu = players_cbox->currentText().toInt();
    velikost = size_cbox->currentText().toInt();
    switch(velikost) {
        case 5:
            labels_num = 2;
            break;
        case 7:
            labels_num = 3;
            break;
        case 9:
            labels_num = 4;
            break;
        case 11:
            labels_num = 5;
            break;
    }

    scene->clear();
    running = true;
    //vylosovani zacinajiciho hrace
    hracNaTahu = rand() % pocetHracu;
    posunuto = false;
    plan.inicializace(velikost);
    hrac = new Hrac[pocetHracu];
    for(int i = 0; i < pocetHracu; i++){
        hrac[i] = Hrac(i, velikost);
        plan.prirad_predmet(&hrac[i]);
    }
    updateGame();
    show();
}

