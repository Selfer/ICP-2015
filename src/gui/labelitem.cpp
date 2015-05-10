#include "labelitem.h"
#include <QFont>

LabelItem::LabelItem(QString text, qreal x, qreal y){
    setPlainText(text);
    setPos(x, y);
    setFont(QFont("times",18));
}
