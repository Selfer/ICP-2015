#ifndef LABELITEM
#define LABELITEM

#include <QGraphicsTextItem>

class LabelItem: public QGraphicsTextItem {
public:
    /**
    * Vypise text na souradnice
    * @param text vypisovany text (QString)
    * @param x x-pozice textu (qreal)
    * @param y y-pozice textu (qreal)
    */
    LabelItem(QString text, qreal x, qreal y);
};

#endif // LABELITEM

