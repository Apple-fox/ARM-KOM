#ifndef SELLER1_H
#define SELLER1_H

#include <QMainWindow>
#include <QDialog>

namespace Ui {
class seller;
}

class seller : public QDialog
{
    Q_OBJECT

public:
    explicit seller(QWidget *parent = nullptr);
    ~seller();

private:
    Ui::seller *ui;
};

#endif // SELLER1_H
