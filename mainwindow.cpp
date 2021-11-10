#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionrdv.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_login_clicked()
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
