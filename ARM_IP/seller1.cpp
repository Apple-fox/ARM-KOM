#include "seller1.h"
#include <QDialog>
#include "ui_seller.h"

seller::seller(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seller)
{
    ui->setupUi(this);
}

seller::~seller()
{
    delete ui;
}
