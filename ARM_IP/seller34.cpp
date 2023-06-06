#include "seller34.h"
#include "ui_seller.h"

seller::seller(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seller)
{
    ui->setupUi(this);
}

seller::~seller()
{
    delete ui;
}
