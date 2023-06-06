#include "pie.h"
#include <QRandomGenerator>
#include <QDebug>
Pie::Pie(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Pie::Pie(double a, double b, int r, int t, QString n){
    startAngle = a;
    span = b;
    x = r;
    y = t;
    name = n;
}
QRectF Pie::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Pie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor (0, 0, 0));
    QRandomGenerator generator;
    int a = rand() % 255;
    int b = rand() % 255;
    int c = rand() % 255;
    painter->setBrush((QColor (a, b, c)));
    QRect rect( -radius, -radius, radius*2, radius*2);
    painter->drawRect(x, y, 17, 17);
    painter->drawText(x+20, y+15, name);
    painter->drawPie( rect, startAngle*16, span*16 );
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
