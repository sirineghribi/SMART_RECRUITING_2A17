#include "gestionrdv.h"
#include "ui_gestionrdv.h"

gestionrdv::gestionrdv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionrdv)
{
    ui->setupUi(this);
}

gestionrdv::~gestionrdv()
{
    delete ui;
}
