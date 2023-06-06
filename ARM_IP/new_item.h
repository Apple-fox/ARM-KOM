#ifndef NEW_ITEM_H
#define NEW_ITEM_H

#include <QDialog>

namespace Ui {
class new_item;
}

class new_item : public QDialog
{
    Q_OBJECT

public:
    explicit new_item(QWidget *parent = nullptr, QString name = "");
    ~new_item();

private slots:

    void on_add_btn_clicked();

    void on_to_back_btn_clicked();

private:
    Ui::new_item *ui;
    QString name_cell;
};

#endif // NEW_ITEM_H
