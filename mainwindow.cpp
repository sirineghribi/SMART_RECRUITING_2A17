#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->la_ref->setValidator(new QIntValidator(1,99999,this));
    ui->tab_domaine->setModel(D.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    int ref=ui->la_ref->text().toInt();

    int hours=ui->les_heurs->text().toInt();
    Domaine D(nom,ref,hours);
    D.ajouter();
    bool test=D.ajouter();
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("added successfully!");
        //refresh
       ui->tab_domaine->setModel(D.afficher());

    }
else
    msgBox.setText("failed to add.");
    msgBox.exec();
}


void MainWindow::on_supp_button_clicked()
{
    Domaine D1; D1.setRef(ui->ref_supp->text().toInt());
    bool test=D1.supprimer(D1.getRef());
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("deleted successfully!");

    //refresh
        ui->tab_domaine->setModel(D.afficher());

    }
else
    msgBox.setText("failed to delete.");
    msgBox.exec();
}

void MainWindow::on_modify_button_clicked()
{

}
