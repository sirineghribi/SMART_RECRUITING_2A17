#include "login.h"
#include "ui_login.h"

#include "QMessageBox"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}




void login::on_pb_login_clicked()
{
    QString username = ui->le_username->text();
    QString mdp = ui->le_mdp->text();
    if (username=="amine"&& mdp=="amine")
    {

    gestionrdv gestion;
    gestion.setModal(true);
    gestion.exec();
    }
    else {
    QMessageBox::warning(this,"Login","username and password are incorrect");
    }


}


