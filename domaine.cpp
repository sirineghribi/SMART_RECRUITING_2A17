#include "domaine.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
Domaine::Domaine()

{
   ref=0;
   nom=" ";
   hours=0;
}
    Domaine::Domaine(QString nom,int ref,int hours)
{ this->nom=nom;this->ref=ref; this->hours=hours;}

    QString Domaine::getNom(){return nom;}
   int Domaine::getRef(){return ref; }
   int Domaine::getHours(){return hours;}
   void Domaine::setNom(QString n){nom=n;}
   void Domaine::setRef(int ref){this->ref=ref;}
   void Domaine::setHours(int hours){this->hours=hours;}

bool Domaine::ajouter()
{
    QSqlQuery query;
    QString ref_string=QString::number(ref);
    QString hours_string=QString::number(hours);
    query.prepare("INSERT INTO GS_DOMAINE ( ref,nom,hours) "
        "VALUES (:ref, :nom, :hours)");


        query.bindValue(":ref", ref_string);
        query.bindValue(":nom", nom);
        query.bindValue(":hours", hours_string);
        return query.exec();
}
bool Domaine::supprimer(int ref)
{
    QSqlQuery query;
    query.prepare("Delete from GS_DOMAINE where ref=:ref");
        query.bindValue(0, ref);
        return query.exec();
}
QSqlQueryModel* Domaine::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM GS_DOMAINE");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("hours"));
     return model;

}
bool Domaine::modifier( )
{

    QSqlQuery query;
     query.prepare("UPDATE GS_DOMAINE set ref=:ref, nom=:nom,hours=:hours where ref= :ref");

     query.bindValue(":ref", ref);
     query.bindValue(":nom", nom);
     query.bindValue(":hours", hours);
        return query.exec();
}
QSqlQueryModel* Domaine::rechercher(int ref )
{
    QString ref_string= QString::number(ref);

    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from GS_DOMAINE where ref=:ref ");
    query.addBindValue(ref_string);
    query.exec();

        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("hours"));

    return model;
}

