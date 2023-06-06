#ifndef ARM_WIN_H
#define ARM_WIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ARM_WIN; }
QT_END_NAMESPACE

class ARM_WIN : public QMainWindow
{
    Q_OBJECT

public:
    ARM_WIN(QWidget *parent = nullptr);
    ~ARM_WIN();

private:
    Ui::ARM_WIN *ui;
};
#endif // ARM_WIN_H
