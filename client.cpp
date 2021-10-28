#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
Client::Client()
{
    nom=" "; prenom=" "; adresse=" "; domaine=" "; sexe=" "; mail=" "; cin=0; numero=0;
}
Client::Client(QString nom,QString prenom,QString adresse,QString domaine,QString sexe,QString mail,int cin,int numero,QString date)
{
   this->nom=nom;
   this->prenom=prenom;
   this->adresse=adresse;
   this->domaine=domaine;
   this->sexe=sexe;
   this->mail=mail;
   this->cin=cin;
   this->numero=numero;
   this->domaine=domaine;
   this->date=date;
}

int Client::getCin(){return cin;}
QString Client ::getNom(){return nom;}
QString Client ::getPrenom(){return prenom;}
QString Client ::getDomaine(){return domaine;}
void Client::setCin(int c){this->cin=c;}
void Client::setNom(QString n){this->nom=n;}
void Client::setPrenom(QString p){this->prenom=p;}
void Client::setDomaine(QString d){this->domaine=d;}
 bool Client::ajouter()
 {

     QSqlQuery query;
     QString cin_string= QString::number(cin);
     QString numero_string= QString::number(numero);

           query.prepare("INSERT INTO client (nom,prenom,adresse,domaine,sexe,mail,cin,numero,date) "
                         "VALUES (:nom, :prenom, :adresse, :domaine, :sexe, :mail, :cin, :numero, :date)");

           query.bindValue(":cin",cin);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":date",date);
           query.bindValue(":sexe",sexe);
           query.bindValue(":numero", numero);
           query.bindValue(":mail",mail);
           query.bindValue(":adresse",adresse);
           query.bindValue(":domaine", domaine);
           return query.exec();



 }

 QSqlQueryModel * Client::afficher()
 {
     //to do
 }
 bool Client::supprimer(int cin)
 {
     // to do
 }
 bool Client::modifier(int cin)
 {
     //to do
 }
