#include "labyrintmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LabyrintMain w;
    w.show();

    return a.exec();
}
