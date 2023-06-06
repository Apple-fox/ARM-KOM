#ifndef REGISTR1_H
#define REGISTR1_H

#include <QWidget>

namespace Ui {
class registr;
}

class registr : public QWidget
{
    Q_OBJECT

public:
    explicit registr(QWidget *parent = nullptr);
    ~registr();

private slots:
    void on_registr_button_clicked();

    void on_exit_but_clicked();

private:
    Ui::registr *ui;
};

#endif // REGISTR1_H
