#include "del_prod.h"
#include "ui_del_prod.h"
#include <QFile>
#include <QDebug>
#include <QTextCodec>
Del_prod::Del_prod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Del_prod)
{
    ui->setupUi(this);
}

Del_prod::~Del_prod()
{
    delete ui;
}

void Del_prod::on_pushButton_clicked()
{
    bool f = false;
    QString con = ui->lineEdit->text();
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
                        if(con != item[0]) out << item[0] << ";" << item[1] << ";" << item[2] << ";" << item[3] << ";" << item[4] << ";" << item[5] <<"\n";
                        else f = true;
                    }
                    file1.close();
                  }
            file1.remove();
            file.rename("C:/Project_Qt1/ARM_IP/Products.csv");
            file.close();
        }
        if(f) this->close();
        else ui->info_label->setText("Данный товар не найден!");
}

