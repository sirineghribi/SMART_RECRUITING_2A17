#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Client::Client()
{
    nom=" "; prenom=" "; adresse=" "; domaine=" "; sexe=" "; mail=" "; cin=0; numero=0,date_n="";
}
Client::Client(int cin,QString nom,QString prenom,QString date_n,QString sexe,QString adresse,QString domaine,QString mail,int numero)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->date_n=date_n;
    this->sexe=sexe;
    this->adresse=adresse;
    this->domaine=domaine;
    this->mail=mail;
    this->numero=numero;

}

int Client::getCin(){return cin;}
QString Client ::getNom(){return nom;}
QString Client ::getPrenom(){return prenom;}
QString Client ::getDomaine(){return domaine;}
QString Client ::getMail(){return mail;}
QString Client ::getAdresse(){return adresse;}
QString Client ::getSexe(){return sexe;}
QString Client ::getDate(){return date_n;}
int Client::getNumero(){return numero;}

void Client::setCin(int c){this->cin=c;}
void Client::setNom(QString n){this->nom=n;}
void Client::setPrenom(QString p){this->prenom=p;}
void Client::setDomaine(QString d){this->domaine=d;}
void Client::setMail(QString m){this->mail=m;}
void Client::setAdresse(QString a){this->adresse=a;}
void Client::setSexe(QString s){this->sexe=s;}
void Client::setDate(QString date){this->date_n=date;}
void Client::setNumero(int num){this->numero=num;}

 bool Client::ajouter()
 {


     QSqlQuery query;
     QString cin_string = QString::number(cin);
     QString numero_string= QString::number(numero);

           query.prepare("INSERT INTO client (cin,nom,prenom,date_n,sexe,adresse,domaine,mail,numero) "
                         "VALUES (:cin, :nom, :prenom, :date_n, :sexe, :adresse, :domaine, :mail, :numero)");

           query.bindValue(":cin",cin_string);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":date_n",date_n);
           query.bindValue(":sexe",sexe);
           query.bindValue(":adresse", adresse);
           query.bindValue(":domaine",domaine);
           query.bindValue(":mail",mail);
           query.bindValue(":numero", numero_string);
           return query.exec();



 }

 QSqlQueryModel * Client::afficher()
 {
      QSqlQueryModel* model=new  QSqlQueryModel();

            model->setQuery("SELECT* FROM client");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_n"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("domaine"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("numero"));




      return model;
 }
 bool Client::supprimer(int cin)
 {
     QSqlQuery query;
     query.prepare("Delete from client where cin=:cin");
     query.bindValue(0,cin);
     return query.exec();
 }
 bool Client::modifier()
{
    QSqlQuery query;


  query.prepare("UPDATE client set  cin=:cin,nom=:nom,prenom=:prenom ,date_n=:date_n,sexe=:sexe,adresse=:adresse,domaine=:domaine,mail=:mail,numero=:numero where cin=:cin");


      query.bindValue(":cin", cin);
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":date_n", date_n);
      query.bindValue(":sexe", sexe);
      query.bindValue(":adresse",adresse);
      query.bindValue(":domaine", domaine);
      query.bindValue(":mail",mail);
      query.bindValue(":numero", numero);
      return query.exec();

}
