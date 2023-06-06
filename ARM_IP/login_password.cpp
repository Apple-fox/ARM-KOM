#include "login_password.h"
#include "seller.h"
#include "shopper.h"
#include "registr.h"
#include <QTextCodec>
#include "ui_login_password.h"
#include <QDebug>
#include <QFile>

login_password::login_password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_password)
{
    ui->setupUi(this);
    ui->vhod_lineEdit_pas->setEchoMode(QLineEdit::Password);

}
login_password::~login_password()
{
    delete ui;
}

void login_password::on_vhod_butt_clicked()
{
    QString login, pass, login_1, pass_1;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    login = ui->vhod_lineEdit_log->text();
    pass = ui->vhod_lineEdit_pas->text();
    bool authorization=false, bad_pass = false, pro = false;
    ui->warning->setText("Вход выполнен " + login + " " + pass);
    QFile file("C:/Project_Qt1/ARM_IP/Accounts.csv");
        if ( !file.open(QFile::ReadOnly) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd() && !authorization)
            {
                QString line = in.readLine();
                QStringList item = line.split(";");
                login_1 = item[0];
                pass_1 = item[1];
                if(login==login_1){
                    if(pass!=pass_1)bad_pass = true;
                    else{
                        authorization = true;
                        if(item[2] == "pro") pro = true;
                    }
                }
            }
            file.close();
            if(bad_pass) ui->warning->setText("Неверный пароль!");
            else if (!authorization) ui->warning->setText("Пользователь с таким логином не найден!");
            else{
                if (pro){
                    this->close();
                    seller* seller = new class seller(nullptr, login);
                    seller->show();
                }
                else{
                    this->close();
                    shopper* shopper = new class shopper(nullptr, login);
                    shopper->show();
                }
            }
        }

}


void login_password::on_reg_butt_clicked()
{
    registr* reg = new registr(nullptr);
    reg->show();
}

