#ifndef LOGIN_PASSWORD_H
#define LOGIN_PASSWORD_H

#include <QWidget>

namespace Ui {
class login_password;
}

class login_password : public QWidget
{
    Q_OBJECT

public:
    explicit login_password(QWidget *parent = nullptr);
    ~login_password();
private slots:
    void on_vhod_butt_clicked();

    void on_reg_butt_clicked();

private:
    Ui::login_password *ui;
};

#endif // LOGIN_PASSWORD_H
