#include "reclamation.h"
#include <QString>
#include<QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
reclamation::reclamation()
{
id_r=0;
date_r="";
sujet="";
etat="";
}
reclamation::reclamation(int id_r, QString date_r,QString sujet,QString etat)
{
    this->id_r=id_r;
    this->date_r=date_r;
    this->sujet=sujet;
    this->etat=etat;

}
int reclamation::getid_r(){return id_r;}
QString reclamation::getdate_r(){return date_r;}
QString reclamation::getsujet(){return sujet;}
QString reclamation::getetat(){return etat;}

void reclamation:: setid_r(int id_r){this->id_r=id_r;}
void reclamation:: setdate_r(QString date_r){this->date_r=date_r;}
void reclamation::setsujet(QString sujet){this->sujet=sujet;}
void reclamation::setetat(QString etat){this->etat=etat;}

bool reclamation::ajouter_rec()
{
    QSqlQuery query;
    QString res=QString::number(id_r);

query.prepare("INSERT INTO reclamation (id_r, date_r,sujet,etat) "
                        "VALUES (:id_r , :date , :sujet , :etat)");
          query.bindValue(":id_r", res);
          query.bindValue("date_r", date_r);
          query.bindValue("sujet", sujet);
          query.bindValue("etat", etat);
          return query.exec();

}

QSqlQueryModel * reclamation::afficher_rec()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reclamation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("sujet"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("etat"));
    return model;

}
bool reclamation:: modifier_rec()
{
    QSqlQuery query;
    query.prepare("update reclamation set date_r=:date_r,sujet=:sujet,etat=:etat where id_r=:id_r");
    query.bindValue(":id_r", id_r);
    query.bindValue(":date_r", date_r);
    query.bindValue(":sujet", sujet);
    query.bindValue(":etat", etat);
    return    query.exec();
}
 QSqlQueryModel *chercher_reclamation(int id_r)
    {
        QSqlQueryModel * model = new QSqlQueryModel();
            QSqlQuery query;
            query.prepare("select * from reclamation where id_r= ? ");
            query.addBindValue(id_r);
            query.exec();
            model->setQuery(query);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_r"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_r"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("sujet"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));



          return model;
    }
