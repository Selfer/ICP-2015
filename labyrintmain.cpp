#include "labyrintmain.h"
#include "labyrint.h"
#include "hrac.h"
#include "herni_plan.h"
#include "ui_labyrintmain.h"

#include <QtWidgets>
#include <QtCore/qstate.h>


LabyrintMain::LabyrintMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LabyrintMain)
{
    ui->setupUi(this);
    HerniPlan HP(VELIKOST);
}

LabyrintMain::~LabyrintMain()
{
    delete ui;
}
