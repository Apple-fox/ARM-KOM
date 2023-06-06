#include "registr.h"
#include "ui_registr.h"
#include "login_password.h"
#include <QFile>
#include <QDebug>

registr::registr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registr)
{
    ui->setupUi(this);
}

registr::~registr()
{

    delete ui;
}

void registr::on_registr_button_clicked()
{
    QString log, pas, pas_rep, pok_or_pro;
    bool personal = true;
    log = ui->login_reg->text();
    pas = ui->pass_reg->text();
    pas_rep = ui->pass_repeat->text();
    if (pas != pas_rep) {
        ui->warning->setText("Пароли не совпадают!");
    }
    else{
        ui->warning->setText("");
        QFile file("C:/Project_Qt1/ARM_IP/Accounts.csv");
            if ( !file.open(QFile::ReadOnly) ) {
                qDebug() << "File not exists";
            } else {
                QTextStream in(&file);
                while (!in.atEnd() && personal)
                {
                    QString line = in.readLine();
                    QStringList item = line.split(";");
                    if (item[0] == log) personal = false;
                }
                file.close();
            }
        if (personal){
            QFile file("C:/Project_Qt1/ARM_IP/Accounts.csv");
                if ( !file.open(QFile::Append) ) {
                    qDebug() << "File not exists";
                } else {
                    QTextStream out(&file);
                    if (ui->radio_prod->isChecked()) pok_or_pro = "pro";
                    else pok_or_pro = "pok";
                    out << log << ";" << pas << ";" << pok_or_pro << endl;
                    file.close();
                }
            this->close();
            login_password* lp = new class login_password(nullptr);
            lp->show();
        }
        else ui->warning->setText("Логин " + log + " занят");
    }
}


void registr::on_exit_but_clicked()
{
    this->close();
    login_password* lp = new login_password(nullptr);
    lp->show();
}
