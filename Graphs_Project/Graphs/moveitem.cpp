#include "moveitem.h"
#include "edge.h"
#include <QRgb>
#include <QGraphicsTextItem>
MoveItem::MoveItem(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}
MoveItem::MoveItem(int si, QGraphicsScene *scene1, QVector<Edge *> * eL){
    n = si;
    scene = scene1;
    edgeList = eL;
    //graph = g;
}
MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::darkBlue);
    painter->setBrush(Qt::lightGray);
    painter->drawEllipse(-10,-10,30,30);
    QString size = QString::number(n);
    painter->drawText( QRect(-10, -10 , 30, 30), Qt::AlignCenter|Qt::AlignVCenter, size);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}
QVariant MoveItem::itemChange(GraphicsItemChange change, const QVariant &value){
    for(int i = 0; i < edgeList->size(); i++){
        Edge * edge = (*edgeList)[i];
        edge->adjust();
    }
    return QGraphicsItem::itemChange(change, value);
}
void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемент
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
