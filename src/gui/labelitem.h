#ifndef LABELITEM
#define LABELITEM

#include <QGraphicsTextItem>

class LabelItem: public QGraphicsTextItem {
public:
    LabelItem(QString text, qreal x, qreal y);
};

#endif // LABELITEM

