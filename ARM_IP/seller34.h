#ifndef SELLER34_H
#define SELLER34_H

#include <QWidget>

namespace Ui {
class seller;
}

class seller : public QWidget
{
    Q_OBJECT

public:
    explicit seller(QWidget *parent = nullptr);
    ~seller();

private:
    Ui::seller *ui;
};

#endif // SELLER34_H
