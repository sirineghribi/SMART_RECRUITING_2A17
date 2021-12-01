#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QIntValidator>
#include <QMessageBox>
//#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 //ui->lineEdit_cin->setValidator( new QIntValidator(0, 99999999, this));
 ui->lineEdit_tel->setValidator( new QIntValidator(0, 99999999, this));

 ui->tab_client->setModel(C.afficher());
 //ui->tab_client->setModel(C.rechercher(ui->domaine2->text()));

 int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_ajouter2_clicked()
{
    QString cin=ui->lineEdit_cin->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString date_n=ui->lineEdit_date->text();
    QString sexe=ui->lineEdit_sexe->currentText();
    QString adresse=ui->lineEdit_adresse->text();
     QString domaine=ui->lineEdit_domaine->text();
     QString mail=ui->lineEdit_mail->text();
    int numero=ui->lineEdit_tel->text().toInt();

  Client C(cin,nom,prenom,date_n,sexe,adresse,domaine,mail,numero);

  bool test =C.ajouter();

  if(test)
  {
      ui->tab_client->setModel(C.afficher());
      QMessageBox::information(nullptr, QObject::tr("ok"),
                  QObject::tr("ajouter effectue\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
    {  QMessageBox::critical(nullptr, QObject::tr("not ok"),
                  QObject::tr("ajouter non effectue \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
     }

 }

void MainWindow::on_supprimer_clicked()
{
  C.setCin(ui->lineEdit_cin->text());
   bool test=C.supprimer(C.getCin());

   if(test)
   {
        ui->tab_client->setModel(C.afficher());
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("suppression effectue\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

 }
   else
     {  QMessageBox::critical(nullptr, QObject::tr("not ok"),
                   QObject::tr("suppression  non effectue \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
      }

}
void MainWindow::on_modifier_clicked()
{

    QString  cin=ui->lineEdit_cin->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString date_n=ui->lineEdit_date->text();
    QString sexe=ui->lineEdit_sexe->currentText();
    QString adresse=ui->lineEdit_adresse->text();
     QString domaine=ui->lineEdit_domaine->text();
     QString mail=ui->lineEdit_mail->text();
    int numero=ui->lineEdit_tel->text().toInt();

    Client C(cin,nom,prenom,date_n,sexe,adresse,domaine,mail,numero);

    bool test =C.modifier();


     if(test)
     {
          ui->tab_client->setModel(C.afficher());
         QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("modifier effectue\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("not ok"),
                     QObject::tr("impossible de modifier  \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void MainWindow::on_rechercher_2_clicked()
{
   //QString domaine=ui->domaine2->text();
  ui->tab_client->setModel(C.rechercher(ui->cin2->text()));


}

void MainWindow::on_trier_2_clicked()
{
   //QString domaine=ui->domaine2->text();
  ui->tab_client->setModel(C.trier(ui->ordre->currentText()));


}

void MainWindow::on_PDF_clicked()
{
  C.PDF();
}

void MainWindow::on_ok_clicked()
{
   ui->tableView1->setModel(C.liste_reclamation(ui->cin3->text()));

}

void MainWindow::on_ok2_clicked()
{
    ui->tableView2->setModel(C.liste_clients(ui->d1->text(),ui->d2->text()));
}

void MainWindow::on_pushButton_3_clicked()
{
   ui->tab_client->setModel(C.afficher());
}

/*void MainWindow::on_pushButton_clicked()
{
   A.write_to_arduino("1");
}

void MainWindow::on_pushButton_2_clicked()
{
   A.write_to_arduino("2");
}*/





void MainWindow::on_bibi_clicked()
{
    C.update_ard();
}

void MainWindow::on_ING_clicked()
{
    C.update_ard_1();
}
