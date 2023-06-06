#ifndef GRAPHS_H
#define GRAPHS_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include "vertex.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Graphs; }
QT_END_NAMESPACE

class Graphs : public QMainWindow
{
    Q_OBJECT

public:
    Graphs(QWidget *parent = nullptr);
    ~Graphs();
private:
    void insertVertex();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void del_rib(QString f, QString s);
    void DFS(Vertex* start, bool * visit);
    void BFS(Vertex * start, bool * visit, QQueue<Vertex *> vert_queue);
    Vertex * find_vert(QString id);
    QVector<Vertex * > find_neigh(Vertex * ver);
    int find_weight(Vertex* f, Vertex* s);
    bool pathExist(Vertex* f, Vertex* s);
    QString travellingSalesman(int vertexIndex);
private slots:
    void on_add_vert_btn_clicked();

    void on_add_rib_btn_clicked();

    void on_del_vert_btn_clicked();

    void on_del_rib_btn_clicked();

    void on_dfs_btn_clicked();

    void on_bfs_btn_clicked();

    void on_travel_btn_clicked();

    void on_question_btn_clicked();

private:
    Ui::Graphs *ui;
    QGraphicsScene *scene;
    int size = 0;
    QVector<Vertex *> vertexList;
    QVector<Edge *> edgeList;
};
#endif // GRAPHS_H
