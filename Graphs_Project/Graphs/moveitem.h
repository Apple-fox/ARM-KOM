#ifndef MOVEITEM_H
#define MOVEITEM_H
#include <QMainWindow>
#include <QVector>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include<QGraphicsScene>
#include "edge.h"
#include "graphs.h"
namespace Ui { class MoveItem; }
class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem(QObject *parent = 0);
    MoveItem(int si, QGraphicsScene *scene1, QVector<Edge *> * eL);
    ~MoveItem();

private:
    int n;
    QGraphicsScene* scene;
    QVector<Edge *> * edgeList;
    //Graphs *graph;
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

};

#endif // MOVEITEM_H
