#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "reclamation.h"
#include <QMessageBox>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);

     ui->l_supp_id->setValidator(new QIntValidator(100, 9999, this));
     ui->lineEditnom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEditprenom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEditsexe->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEditid->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
     ui->l_date->setValidator(new QRegExpValidator(QRegExp("[0-9 /]{10}")));
     ui->lineEditcin->setValidator(new QRegExpValidator(QRegExp("[0-9 :]{8}")));
     ui->lineEdittel->setValidator(new QRegExpValidator(QRegExp("[0-9 :]{8}")));

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
    {ui->TAB_EMPLOYE->setModel(Etmp.afficher());
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

   if(test )
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
void MainWindow::on_TAB_EMPLOYE_clicked(const QModelIndex &index)
{
 QString  id=ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),6)).toString();
        ui ->l_supp_id->setText(id);

}

void MainWindow::on_pb_rechercher_clicked()
{
    int id=ui->l_rechercher->text().toInt();
    ui->TAB_EMPLOYE->setModel(Etmp.rechercher(id));



}

void MainWindow::on_radioButton_id_clicked()
{

}


//reclamation//
void MainWindow::on_pb_ajout_rec_clicked()
{
    int  id_r=ui->l_id_rec->text().toInt();
    QString date_r=ui->l_date->text();
    QString sujet=ui->l_sujet->text();
    QString etat=ui->l_etat->text();

   reclamation R (id_r,date_r,sujet,etat);

  bool test=R.ajouter_rec();
  if(test)
  {
      QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("ajout effectué \n"
                               "click Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("ajout non effectué.\n"
                                 "click Cancel to exit."  ),QMessageBox::Cancel);


}

void MainWindow::on_pb_modi_rec_clicked()
{
    int  id_r=ui->l_id_rec->text().toInt();
    QString date_r=ui->l_date->text();
    QString sujet=ui->l_sujet->text();
    QString etat=ui->l_etat->text();

   reclamation R (id_r,date_r,sujet,etat);

  bool test=R.modifier_rec();
  if(test)
  {
      QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("modification effectué \n"
                               "click Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("modification non effectué.\n"
                                 "click Cancel to exit."  ),QMessageBox::Cancel);
}

void MainWindow::on_pb_afficher_clicked()
{

}
