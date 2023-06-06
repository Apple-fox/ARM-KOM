#include "Arm_win.h"
#include "ui_Arm_win.h"

ARM_WIN::ARM_WIN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ARM_WIN)
{
    ui->setupUi(this);
}

ARM_WIN::~ARM_WIN()
{
    delete ui;
}

