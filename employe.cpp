#include "employe.h"
#include<QSqlQuery>
#include <QtDebug>

Employe::Employe()
{
    nom="";
    prenom="";
    sexe="";
    adresse="";
    mail="";
    date_de_naissance="";
    id=0;
    cin=0;
    num_de_tel=0;

}
Employe::Employe(QString nom,QString prenom,QString mail,QString sexe,QString adresse,QString date_de_naissance,int id,int cin,int num_de_tel)
{ this->cin=cin;
    this->id=id;
    this->num_de_tel=num_de_tel;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->adresse=adresse;
    this->mail=mail;
    this->date_de_naissance=date_de_naissance;}

int Employe::getcin(){return cin;}
int Employe::getnum_de_tel(){return num_de_tel;}
int Employe::getid(){return id;}
QString Employe:: getnom(){return nom;}
QString Employe:: getprenom(){return prenom;}
QString Employe::getsexe(){return sexe;}
QString Employe::getdate_de_naissance(){return date_de_naissance;}
QString Employe:: getmail(){return mail;}
QString Employe ::getadresse(){return adresse;}

void Employe:: setcin(int cin){this->cin=cin;}
void Employe:: setnum_de_tel(int num_de_tel){this->num_de_tel=num_de_tel;}
void Employe::setid(int id){this->id=id;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe:: setprenom(QString prenom){this->prenom=prenom;}
void Employe:: setsexe(QString sexe){this->sexe=sexe;}
void Employe:: setdate_de_naissance(QString date_de_naissance){this->date_de_naissance=date_de_naissance;}
void Employe::setmail(QString mail){this->mail=mail;}
void Employe::setadresse(QString adresse){this->adresse=adresse;}

bool Employe::ajouter_employe()
{
QString id_string=QString::number(id);
QString cin_string=QString::number(cin);
QString num_de_tel_string=QString::number(num_de_tel);

    QSqlQuery query;
          query.prepare("INSERT INTO employe (id, nom, prenom,adresse,mail,date_de_naissance,num_de_tel,sexe,cin) "
                        "VALUES (:id, :nom, :prenom, :adresse, :mail,:date_de_naissance,:num_de_tel,:sexe,:cin)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", "nom");
          query.bindValue(":prenom", "prenom");
          query.bindValue(":mail", "mail");
          query.bindValue(":adresse", "adresse");
          query.bindValue(":date_de_naissance", "date_de_naissance");
          query.bindValue(":num_de_tel", num_de_tel_string);
          query.bindValue(":cin", cin_string);
          query.bindValue(":sexe", "sexe");
         return query.exec();

}
QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_de_tel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("date_de_naissance"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("sexe"));
return model;

}
bool Employe :: supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

              query.prepare("Delete from employe where ID=:id");

              query.bindValue(":id", res);

              return query.exec();
}
