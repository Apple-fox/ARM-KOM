#include "new_item.h"
#include "ui_new_item.h"
#include <QDebug>
#include <QFile>

new_item::new_item(QWidget *parent, QString name) :
    QDialog(parent),
    ui(new Ui::new_item)
{
    ui->setupUi(this);
    name_cell = name;
}

new_item::~new_item()
{
    delete ui;
}
bool true_false(QString name){
    bool flag = false;
    QFile file("C:/Project_Qt1/ARM_IP/Products.csv");
        if ( !file.open(QFile::ReadOnly) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while(!in.atEnd()){
                QStringList list = in.readLine().split(";");
                if(name == list[0]) flag = true;
            }
            file.close();
        }
    return flag;
}
void new_item::on_add_btn_clicked()
{
    bool f = false;
    QString name = ui->name_item->text();
    QString cell = ui->price_item->text();
    QString about = ui->about_item->text();
    QString count = ui->count_item->text();
    QFile file("C:/Project_Qt1/ARM_IP/Products.csv");
        if ( !file.open(QFile::Append) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream out(&file);
            if(!true_false(name)) {
                    out << name << ";" << cell << ";" << about << ";" << count << ";" << name_cell << ";" << "0" << endl;
                    f = true;
            }
            else{
                ui->info_label->setText("Товар с данным названием уже существует!");
            }
            file.close();
        }
   if (f) this->close();
}


void new_item::on_to_back_btn_clicked()
{
    this->close();
}

