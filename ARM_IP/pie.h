#ifndef PIE_H
#define PIE_H
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
namespace Ui { class Pie; }
class Pie: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pie(QObject *parent = 0);
    Pie(double a, double b, int r, int t, QString n);

public:
    QGraphicsScene* scene;
    int radius = 100;
    double startAngle;
    double span;
    int x, y;
    QString name;
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PIE_H
