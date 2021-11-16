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

bool Employe::ajouter()
{QSqlQuery query;
QString res=QString::number(cin);
QString res1=QString::number(id);
QString res2=QString::number(num_de_tel);



     query.prepare("INSERT INTO employe (cin, nom,prenom,mail,adresse,date_de_naissance,id,sexe, num_de_tel) "
                        "VALUES (:cin, :nom, :prenom, :mail, :adresse,:date_de_naissance,:id,:sexe,:num_de_tel)");
          query.bindValue(":cin", res);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":mail", mail);
          query.bindValue(":adresse", adresse);
          query.bindValue(":date_de_naissance",date_de_naissance);
          query.bindValue(":id", res1);
          query.bindValue(":sexe", sexe);
          query.bindValue(":num_de_tel", res2);

         return query.exec();

}

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_de_naissance"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("num_de_tel"));
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
bool Employe:: modifier()
{
    QSqlQuery query;
    query.prepare("update employe set nom=:nom,prenom=:prenom,mail=:mail,num_de_tel=:num_de_tel,adresse=:adresse,date_de_naissance=:date_de_naissance,cin=:cin,sexe=:sexe where id=:id");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":num_de_tel", num_de_tel);
    query.bindValue(":adresse", adresse);
    query.bindValue(":date_de_naissance", date_de_naissance);
    query.bindValue(":id", id);
    query.bindValue(":sexe",sexe);
    return    query.exec();
}

QSqlQueryModel * Employe::rechercher(int id )

{
    QString id_string= QString::number(id);

    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from employe where ID=:id ");
    query.addBindValue(id_string);
    query.exec();

        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("sexe"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_de_naissance"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("num_de_tel"));
    return model;
}
   QSqlQueryModel * Employe ::trier( )
   {

   }
