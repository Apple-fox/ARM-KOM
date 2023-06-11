#include "graphs.h"
#include "ui_graphs.h"
#include "question.h"
#include "moveitem.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QQueue>
#include <QGraphicsView>

#include <QDebug>

Graphs::Graphs(QWidget *parent): QMainWindow(parent), ui(new Ui::Graphs)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
        scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
        ui->graphs_view->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
        ui->graphs_view->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
        ui->graphs_view->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
        ui->graphs_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
        ui->info_line->setText("");
}

Graphs::~Graphs()
{
    delete ui;
}

int getHighScore(QVector<QVector<int>> matrix, int posi, int posj,int n){
    int minj = matrix[posi][0];
    int mini = matrix[0][posj];
    for(int j=1;j<n;j++)
    {
        if(j!=posj && matrix[posi][j]<minj)
        {
            minj = matrix[posi][j];
        }
    }
    for(int i=1;i<n;i++)
    {
        if(i!=posi && matrix[i][posj]<mini)
        {
            mini = matrix[i][posj];
        }
    }
    return mini + minj;
}

bool Graphs::pathExist(Vertex* f, Vertex* s){//Существует ребро между двумя вершинами или нет?
    for(int i = 0; i < edgeList.size(); i++){
        if(edgeList[i]->sourceVertex()->idx == f->idx && edgeList[i]->destVertex()->idx == s->idx) return true;
    }
    return false;
}

void Graphs::init(int** r){
    for(int i=0;i<vertexList.size();i++)
    {
        for(int j=0;j<vertexList.size();j++)
        {
            r[i][j]=-1;
        }
    }
}


QString Graphs::travellingSalesman(int vertexIndex)//Задача Коммивояжера
{
    QVector<QPair<int,int>> res;
    ui->info_label->setText(" ");
    QVector<QVector<int>> matrix;
    for(int i=0;i<vertexList.size();i++)
    {
        QVector<int> vec;
        matrix.push_back(vec);
        for(int j=0;j<vertexList.size();j++)
        {
            matrix[i].push_back(0);
        }
    }
    int minRow[vertexList.size()];
    int minCol[vertexList.size()];
    int** HighScoreMatrix = new int*[vertexList.size()];
    for(int i = 0; i < vertexList.size(); i++){
        HighScoreMatrix[i] = new int[vertexList.size()];
    }
    init(HighScoreMatrix);
    for(int i=0;i<vertexList.size();i++)
    {
        for(int j=0;j<vertexList.size();j++)
        {
            if(i==j || !pathExist(vertexList[i], vertexList[j]))
            {
                matrix[i][j]=100000000;
            }
            else
            {
                matrix[i][j]=find_weight(vertexList[i], vertexList[j]);
            }
        }
    }
    for(int k=0;k<vertexList.size();k++)
    {
        init(HighScoreMatrix);
        for(int i=0;i<vertexList.size();i++)
        {
            minRow[i]=matrix[i][0];
            for(int j=1;j<vertexList.size();j++)
            {
                if(matrix[i][j]<minRow[i])
                {
                    minRow[i]=matrix[i][j];
                }
            }
            if(minRow[i]==100000000)
            {
                minRow[i]=0;
            }
        }
        for(int i=0;i<vertexList.size();i++)
        {
            for(int j=0;j<vertexList.size();j++)
            {
                if(matrix[i][j]!=100000000)
                {
                    matrix[i][j]-=minRow[i];
                }
            }
        }
        for(int i=0;i<vertexList.size();i++)
        {
            minCol[i]=matrix[0][i];
            for(int j=1;j<vertexList.size();j++)
            {
                if(matrix[j][i]<minCol[i])
                {
                    minCol[i]=matrix[j][i];
                }
            }
            if(minCol[i]==100000000)
            {
                minCol[i]=0;
            }
        }
        for(int i=0;i<vertexList.size();i++)
        {
            for(int j=0;j<vertexList.size();j++)
            {
                if(matrix[j][i]!=100000000)
                {
                    matrix[j][i]-=minCol[i];
                }
            }
        }
        for(int i=0;i<vertexList.size();i++)
        {
            for(int j=0;j<vertexList.size();j++)
            {
                if(matrix[i][j]==0)
                {
                    HighScoreMatrix[i][j] = getHighScore(matrix,i,j,vertexList.size());
                }
            }
        }
        int maxNull = -1;
        int maxNulli = 0;
        int maxNullj = 0;
        for(int i=0;i<vertexList.size();i++)
        {
            for(int j=0;j<vertexList.size();j++)
            {
                if(HighScoreMatrix[i][j]!=-1 && HighScoreMatrix[i][j]>maxNull)
                {
                    maxNull = HighScoreMatrix[i][j];
                    maxNulli = i;
                    maxNullj = j;
                }
            }
        }
        for(int i=0;i<vertexList.size();i++)
        {
            matrix[i][maxNullj] = 100000000;
        }
        for(int j=0;j<vertexList.size();j++)
        {
            matrix[maxNulli][j] = 100000000;
        }
        matrix[maxNullj][maxNulli] = 100000000;
        QPair<int,int> p;
        p.first=maxNulli;
        p.second=maxNullj;
        res.push_back(p);
    }
    int path[vertexList.size()+1];
    for(int i=0;i<vertexList.size()+1;i++)
    {
        path[i]=0;
    }
    path[0]=vertexIndex;
    int curr = vertexIndex;
    for(int i=0;i<vertexList.size();i++)
    {
        for(int j=0;j<vertexList.size();j++)
        {
            if(res[j].first==curr)
            {
                curr = res[j].second;
                path[i+1]=curr;
                break;
            }
        }
    }
    int sum=0;
    for(int i=0;i<vertexList.size();i++)
    {
        sum += find_weight(vertexList[path[i]], vertexList[path[i+1]]);
    }
    QString str;
    str+= QString::number(path[0]);
    for(int i=1;i<vertexList.size()+1;i++)
    {
        str+= " -> " + QString::number(path[i]);
    }
    str += ". Итоговый путь составил " + QString::number(sum);
    return str;
}
void Graphs::on_travel_btn_clicked()//кнопка для задачи комма
{
    QString name = ui->info_line->text();
    ui->info_line->setText("");
    ui->info_label->setText(" ");
    if(name.split(" ").size() > 1 || name.isEmpty()){
        ui->info_label->setText("Некорректный ввод!");
        return;
    }
    QString str = travellingSalesman(name.toInt());
    ui->info_label->setText(str);
}


void Graphs::on_add_rib_btn_clicked()//создание ребра
{
    QStringList in = (ui->info_line->text()).split(" ");
    ui->info_line->setText("");
    ui->info_label->setText(" ");
    if(in.size() < 3){
        ui->info_label->setText("Некорректный ввод!");
        return;
    }
    QString fir = in[0], sec = in[1], wei = in[2];
    Vertex * source, * dest;
    for(int i = 0; i < vertexList.size(); i++){
        if(vertexList[i]->idx == fir.toInt()) source = vertexList[i];
        if (vertexList[i]->idx == sec.toInt()) dest = vertexList[i];
    }
    QString n;
    int y = find_weight(dest, source);
    if (y != -1) n = "down";
    else n = "up";
    Edge* ed = new Edge(source, dest, wei.toDouble(), n);
    edgeList.append(ed);
    scene->addItem(ed);
}
void Graphs::del_rib(QString f, QString s){//удаление ребра
    Vertex * first, * second;
    for(int i = 0; i < vertexList.size(); i++){
        if (vertexList[i]->idx == f.toInt()) first = vertexList[i];
        if(vertexList[i]->idx == s.toInt()) second = vertexList[i];
    }
    Edge * line;
    int idx;
    for(int i = 0; i < edgeList.size(); i++){
        if(edgeList[i]->sourceVertex() == first && edgeList[i]->destVertex() == second){ line = edgeList[i]; idx = i;}
    }
    scene->removeItem(line);
    delete line;
    edgeList.remove(idx);
}
void Graphs::on_del_rib_btn_clicked(){//кнопка удаления ребра
    QStringList in = (ui->info_line->text()).split(" ");
    ui->info_line->setText("");
    ui->info_label->setText(" ");
    if(in.size() > 2 || in.size() < 2){
        ui->info_label->setText("Некорректный ввод!");
        return;
    }
    if (pathExist(find_vert(in[0]), find_vert(in[1]))) del_rib(in[0], in[1]);
    else{
        ui->info_label->setText("Ребра между этими вершинами нет!");
    }
}
int Graphs::find_weight(Vertex* f, Vertex* s){//функция для нахождения веса ребра между двумя вершинами
    for(int i = 0; i< edgeList.size(); i++){
        if (edgeList[i]->sourceVertex() == f && edgeList[i]->destVertex() == s) return edgeList[i]->getWeight();
    }
    return -1;
}

void Graphs::on_add_vert_btn_clicked(){//добавление с проверкой на повтор индексов
    int vertexIndex = vertexList.size();
    ui->info_label->setText(" ");
    bool f = false;
    for(int i = 0; i < vertexList.size() && vertexIndex == vertexList.size(); i++){
        for(int j = 0; j < vertexList.size(); j++){
            if (i == vertexList[j]->idx) f = true;
        }
        if (!f) vertexIndex = i;
        f = false;
    }
    vertexList.append(new Vertex(scene, vertexIndex, &edgeList));
}
void Graphs::on_del_vert_btn_clicked()//удаление вершины
{
    QString name = ui->info_line->text();
    ui->info_line->setText("");
    QTextStream(stdout) << name.split(" ").size() << " " << name << '\n';
    if(name.split(" ").size() > 1 || name.isEmpty()){
        ui->info_label->setText("Некорректный ввод!");
        return;
    }
    ui->info_label->setText(" ");
    for(int j = 0; j < vertexList.size(); j++){
        if(QString::number(vertexList[j]->idx) == name){
            for(int i = 0; i < edgeList.size(); i++){
                if(edgeList[i]->sourceVertex()->idx == name.toInt()){
                    del_rib(name, QString::number(edgeList[i]->destVertex()->idx));
                    i--;
                }
                else if(edgeList[i]->destVertex()->idx == name.toInt()){
                    del_rib(QString::number(edgeList[i]->sourceVertex()->idx),name);
                    i--;
                }
            }
            scene->removeItem(vertexList[j]->vert);
            delete vertexList[j]->vert;
            vertexList.remove(j);
        }
    }
}
QVector<Vertex * > Graphs::find_neigh(Vertex * ver){//функция для нахождения соседей вершины
    QVector<Vertex * > neibors;
    for(int i = 0; i < edgeList.size(); i++){
        if(edgeList[i]->sourceVertex() == ver) neibors.append(edgeList[i]->destVertex());
    }
    return neibors;
}
Vertex * Graphs::find_vert(QString id){//функция находит вершину по индексу. Возвращает объект типа Vertex*(пользовательский класс)
    for(int i = 0; i < vertexList.size(); i++){
        if (vertexList[i]->idx == id.toInt()) return vertexList[i];
    }
    return NULL;
}

void Graphs::DFS(Vertex* start, bool *visit){//обход в глубину
    if (ui->info_label->text() != "") ui->info_label->setText(ui->info_label->text() + " -> " + QString::number(start->idx));
    else ui->info_label->setText(QString::number(start->idx));
    visit[start->idx] = true;
    QVector<Vertex * > neighbors = find_neigh(start);
    for(int i = 0; i < neighbors.size(); i++){
        if (!visit[neighbors[i]->idx]){
            DFS(neighbors[i], visit);
        }
    }

}
void Graphs::BFS(Vertex * start, bool * visit, QQueue<Vertex *> vert_queue){//обход в ширину
    if(!visit[start->idx]){
        vert_queue.enqueue(start);
        if (ui->info_label->text() != "") ui->info_label->setText(ui->info_label->text() + " -> " + QString::number(start->idx));
        else ui->info_label->setText(QString::number(start->idx));
        visit[start->idx] = true;
    }
    QTextStream(stdout) << "vert - " << start->idx << "\n";
    QVector<Vertex * > neighbors = find_neigh(start);
    for( int i = 0; i < neighbors.size(); i++) QTextStream(stdout) << neighbors[i]->idx << " ";
    vert_queue.dequeue();
    QTextStream(stdout) << "\n";
    for(int i = 0; i < neighbors.size(); i++){
        if(!visit[neighbors[i]->idx]){
            //QTextStream(stdout) << neighbors[i]->idx << "\n";
            vert_queue.enqueue(neighbors[i]);
            visit[neighbors[i]->idx] = true;
            ui->info_label->setText(ui->info_label->text() + " -> " + QString::number(neighbors[i]->idx));
        }
    }
    if(vert_queue.isEmpty()){
        return;
    }
    BFS(vert_queue.front(), visit, vert_queue);
}

void Graphs::on_dfs_btn_clicked(){//кнопка обхода в глубину
    QString name = ui->info_line->text();
    ui->info_line->setText("");
    ui->info_label->setText(" ");
    if(name.split(" ").size() > 1 || name.isEmpty()){
        ui->info_label->setText("Некорректный ввод!");
        return;
    }
    Vertex * start = find_vert(name);
    ui->info_label->setText("");
    bool* visit = new bool[vertexList.size()];
    DFS(start, visit);
}
void Graphs::on_bfs_btn_clicked()//кнопка обхода в ширину
{
    QString name = ui->info_line->text();
    ui->info_line->setText("");
    ui->info_label->setText(" ");
    if(name.split(" ").size() > 1 || name.isEmpty()){
        ui->info_label->setText("Некорректный ввод!");
        return;
    }
    Vertex * start = find_vert(name);
    bool* visit = new bool[vertexList.size()];
    QQueue<Vertex *> t;
    BFS(start, visit, t);
    ui->info_label->setText("Некорректный ввод!");
    return;
}

void Graphs::on_question_btn_clicked()//справка
{
    ui->info_label->setText(" ");
    Question * q = new Question(nullptr);
    q->show();
}
