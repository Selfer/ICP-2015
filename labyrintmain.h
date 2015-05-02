#ifndef LABYRINTMAIN_H
#define LABYRINTMAIN_H

#include <QMainWindow>

namespace Ui {
class LabyrintMain;
}

class LabyrintMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit LabyrintMain(QWidget *parent = 0);
    ~LabyrintMain();

private:
    Ui::LabyrintMain *ui;
};

#endif // LABYRINTMAIN_H
