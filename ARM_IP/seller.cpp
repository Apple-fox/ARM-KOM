#include "seller.h"
#include "ui_seller.h"
#include "new_item.h"
#include "del_prod.h"
#include "login_password.h"
#include <QPushButton>
#include <QObject>
#include <QThread>
#include <QTime>
#include <QTextStream>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include <cmath>
#include "pie.h"


seller::seller(QWidget *parent, QString login) :
    QDialog(parent),
    ui(new Ui::seller)
{
    ui->setupUi(this);
    log = login;
}

void seller::update_tab_prod(){
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTableWidget* table = ui->table_products;
    while (table->rowCount() > 0)
    {
        table->removeRow(0);
    }
    int count = 0;
    QFile file("C:/Project_Qt1/ARM_IP/Products.csv");
        if ( !file.open(QFile::ReadOnly) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList item = line.split(";");
                if (item[4] == log){
                    table->setRowCount(table->rowCount() + 1);
                    for(int i = 0; i < 4; i++){
                        QTableWidgetItem* table_item = new QTableWidgetItem();
                        table_item->setText(item[i]);
                        table->setItem(count, i, table_item);
                    }
                    count++;
                }
            }
            file.close();
            }
}

void seller::update_tab_order(){
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTableWidget* table = ui->table_orders;
    while (table->rowCount() > 0)
    {
        table->removeRow(0);
    }
    int count = 0;
    QFile file("C:/Project_Qt1/ARM_IP/Orders.csv");
        if ( !file.open(QFile::ReadOnly) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList item = line.split(";");
                if (item[3] == log){
                    table->setRowCount(table->rowCount() + 1);
                    for(int i = 0; i < 3; i++){
                        QTableWidgetItem* table_item = new QTableWidgetItem();
                        table_item->setText(item[i]);
                        table->setItem(count, i, table_item);
                    }
                    QPushButton * btn = new QPushButton();
                    btn->setText("Подтвердить");
                    btn->setObjectName(QString::number(count));
                    connect(btn, SIGNAL(clicked()), this, SLOT(confirm_btn()));
                    table->setCellWidget(count, 3, btn );
                    QPushButton * btn1 = new QPushButton();
                    btn1->setText("Удалить");
                    btn1->setObjectName(QString::number(count));
                    connect(btn1, SIGNAL(clicked()), this, SLOT(delete_btn()));
                    table->setCellWidget(count, 4, btn1 );
                    count++;
                }
            }
            file.close();
            }
}

seller::~seller()
{
    delete ui;
}

void seller::on_pushButton_clicked()
{
    new_item* ni = new new_item(nullptr, log);
    ni->show();
}


void seller::on_pushButton_2_clicked()
{
    update_tab_prod();
}

void delay(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

bool seller::delete_order(QString name){
    int con = 0;
    bool f = false;
    QFile file("C:/Project_Qt1/ARM_IP/Orders1.csv");
       if ( !file.open(QFile::WriteOnly) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream out(&file);
            QFile file1("C:/Project_Qt1/ARM_IP/Orders.csv");
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
                if ( !file1.open(QFile::ReadOnly) ) {
                    qDebug() << "File not exists";
                } else {
                    QTextStream in(&file1);
                    while (!in.atEnd()){
                        QString line = in.readLine();
                        QStringList item = line.split(";");
                        if(con != name.toInt()) out << item[0] << ";" << item[1] << ";" << item[2] << ";" << item[3] <<"\n";
                        else f = true;
                        con++;
                    }
                    file1.close();
                  }
            file1.remove();
            file.rename("C:/Project_Qt1/ARM_IP/Orders.csv");
            file.close();
        }
    return f;
}
bool plus(QString name, int n){
    bool f = false;
    QFile file("C:/Project_Qt1/ARM_IP/Products1.csv");
        if ( !file.open(QFile::WriteOnly) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream out(&file);
            QFile file1("C:/Project_Qt1/ARM_IP/Products.csv");
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
                if ( !file1.open(QFile::ReadOnly) ) {
                    qDebug() << "File not exists";
                } else {
                    QTextStream in(&file1);
                    while (!in.atEnd()){
                        QString line = in.readLine();
                        QStringList item = line.split(";");
                        if(item[0] == name) {
                            if (item[3].toInt()-n >= 0) {
                                f = true;
                                out << item[0] << ";" << item[1] << ";" << item[2] << ";" << item[3].toInt()-n << ";" << item[4] << ";" << item[5].toInt()+n <<"\n";
                            }
                            else out << item[0] << ";" << item[1] << ";" << item[2] << ";" << item[3] << ";" << item[4] << ";" << item[5] <<"\n";
                        }else out << item[0] << ";" << item[1] << ";" << item[2] << ";" << item[3] << ";" << item[4] << ";" << item[5] <<"\n";
                    }
                    file1.close();
                  }
            file1.remove();
            file.rename("C:/Project_Qt1/ARM_IP/Products.csv");
            file.close();
        }
        return f;
}
void seller::confirm_btn(){
    QPushButton *click_btn = qobject_cast<QPushButton *>(sender());
    QString name = click_btn->objectName();
    QTableWidget * table = ui->table_orders;
    bool f = plus(table->item(name.toInt(), 0)->text(), table->item(name.toInt(), 1)->text().toInt());
    if (f) {
        for(int i = 0; i < table->columnCount()-2; i++){
            table->item(name.toInt(), i)->setBackground(Qt::green);
        }
        bool f = delete_order(name);
        QTextStream(stdout) << f << '\n';
        delay(2);
        update_tab_order();
    }
    else{
        for(int i = 0; i < table->columnCount()-2; i++){
            table->item(name.toInt(), i)->setBackground(Qt::darkRed);
        }
    }
}
void seller::delete_btn(){
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QPushButton *click_btn = qobject_cast<QPushButton *>(sender());
    QString name = click_btn->objectName();
    QTableWidget * table = ui->table_orders;
    for(int i = 0; i < table->columnCount()-2; i++){
        table->item(name.toInt(), i)->setBackground(Qt::red);
    }
    delete_order(name);
    delay(2);
    update_tab_order();

}
void seller::on_pushButton_3_clicked()
{
    update_tab_order();
}


void seller::on_update_btn_clicked()
{
   //QPainter* painter;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
   QGraphicsView* graph = ui->graphicsView_2;
   QGraphicsScene* scene = new QGraphicsScene(this);
   graph->setScene(scene);
   int sum = 0;
   QVector<QVector<QString>> prod;
   QFile file("C:/Project_Qt1/ARM_IP/Products.csv");
       if ( !file.open(QFile::ReadOnly) ) {
           qDebug() << "File not exists";
       } else {
           QTextStream in(&file);
           while (!in.atEnd())
           {
               QString line = in.readLine();
               QStringList item = line.split(";");
               if (item[4] == log){
                   QVector<QString> column;
                   column.append(item[0]);
                   column.append(item[5]);
                   sum += item[5].toInt();
                   prod.append(column);
               }
           }
           file.close();
           }

   double start = 0;
   sum = (double)360/sum;
   int x = -400, y = -200;
   QTextStream(stdout) << sum << "\n";
   for(int i = 0; i < prod.size(); i++){
       if(i != prod.size()-1){
           double span = (double)sum*prod[i][1].toInt();
           Pie* p = new Pie(start, span, x, y, prod[i][0]);
           scene->addItem(p);
           start += span;
           y += 30;
       }
       else{
           double span = 360-start;
           Pie* p = new Pie(start, span, x, y, prod[i][0]);
           scene->addItem(p);
       }
   }
}


void seller::on_exit_btn_clicked()
{
    login_password* lg = new login_password(nullptr);
    this->close();
    lg->show();
}


void seller::on_pushButton_4_clicked()
{
    Del_prod * dl = new Del_prod(nullptr);
    dl->show();
}

