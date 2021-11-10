#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QValidator>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->lineEditid->setValidator(new QIntValidator(100, 9999, this));
ui->TAB_EMPLOYE->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
  int cin=ui->lineEditcin->text().toInt();
  QString nom=ui->lineEditnom->text();
  QString prenom=ui->lineEditprenom->text();
  QString mail=ui->lineEditmail->text();
  QString adresse=ui->lineEditadresse->text();
  QString date_de_naissance=ui->l_date->text();
  int  id=ui->lineEditid->text().toInt();
  QString sexe=ui->lineEditsexe->text();
  int num_de_tel=ui->lineEdittel->text().toInt();

 Employe E (nom,prenom,sexe,date_de_naissance,mail,adresse,id,cin,num_de_tel);

bool test=E.ajouter();
if(test)
{ ui->TAB_EMPLOYE->setModel(Etmp.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("ajout effectué \n"
                             "click Cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("ajout non effectué.\n"
                               "click Cancel to exit."  ),QMessageBox::Cancel);


}
void MainWindow::on_pb_supp_clicked()
{
    int id=ui->l_supp_id->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                 "click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                             QObject::tr("suppression non effectué.\n"
                                   "click Cancel to exit."  ),QMessageBox::Cancel);

}



void MainWindow::on_pb_modifier_clicked()
{
    int cin=ui->lineEditcin->text().toInt();
    QString nom=ui->lineEditnom->text();
    QString prenom=ui->lineEditprenom->text();
    QString mail=ui->lineEditmail->text();
    QString adresse=ui->lineEditadresse->text();
    QString date_de_naissance=ui->l_date->text();
    int  id=ui->lineEditid->text().toInt();
    QString sexe=ui->lineEditsexe->text();
    int num_de_tel=ui->lineEdittel->text().toInt();

   Employe E (nom,prenom,sexe,date_de_naissance,mail,adresse,id,cin,num_de_tel);
   bool test=E.modifier();

   if(test)
           {
              ui->TAB_EMPLOYE->setModel(Etmp.afficher());
               QMessageBox::information(nullptr, QObject::tr("ok"),
                           QObject::tr("update successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("update failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

