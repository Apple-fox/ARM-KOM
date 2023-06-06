#ifndef ARCWIDGET_H
#define ARCWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QMap>

class ArcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ArcWidget(QWidget *parent = 0);
    ~ArcWidget();

protected:
    void paintEvent(QPaintEvent *e);

private:
    QString getPercentInt(const QString &percentStr);


private:
    QMap<QString, int> m_answerMap;
    QList<int> m_numList;
    QList<QString> m_answerStrList;
    int m_nPeopleCount;
    qreal m_pi = 3.1415;

};
#endif // ARCWIDGET_H
