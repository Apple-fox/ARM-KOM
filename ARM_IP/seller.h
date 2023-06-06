#ifndef SELLER_H
#define SELLER_H

#include <QDialog>

namespace Ui {
class seller;
}

class seller : public QDialog
{
    Q_OBJECT

public:
    explicit seller(QWidget *parent = nullptr, QString login= "");
    void update_tab_prod();
    void update_tab_order();
    bool delete_order(QString name);
    ~seller();
private slots:
    void on_pushButton_clicked();
    void confirm_btn();
    void delete_btn();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_update_btn_clicked();

    void on_exit_btn_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::seller *ui;
    QString log;
};

#endif // SELLER_H
