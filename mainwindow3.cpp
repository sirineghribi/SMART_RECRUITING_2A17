#include "mainwindow3.h"
#include "ui_mainwindow3.h"

#include "QMessageBox"

MainWindow3::MainWindow3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
}

MainWindow3::~MainWindow3()
{
    delete ui;
}




void MainWindow3::on_pb_login_clicked()
{
    QString username = ui->le_username->text();
    QString mdp = ui->le_mdp->text();
    if (username=="amine"&& mdp=="amine")
    {

    //gestionrdv gestion;
    gestion.setModal(true);
    gestion.exec();
    }
    else {
    QMessageBox::warning(this,"Login","username and password are incorrect");
    }


}
