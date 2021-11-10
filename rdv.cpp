#include "rdv.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Rdv::Rdv()
{
    id_rdv=0; date_rdv=""; heure_rdv=""; region= "";
}


Rdv::Rdv(int id, QString date, QString heure, QString region)
{
    this->id_rdv=id; this->date_rdv=date; this->heure_rdv=heure; this->region=region;
}


QString Rdv::get_date(){return date_rdv;}

QString Rdv::get_heure(){return heure_rdv;}

int Rdv::get_id(){return id_rdv;}

QString Rdv::get_region(){return region;}

void Rdv::set_date(QString date_rdv){this->date_rdv=date_rdv;}

void Rdv::set_heure(QString heure_rdv){this->heure_rdv=heure_rdv;}

void Rdv::set_id(int id_rdv){this->id_rdv=id_rdv;}

void Rdv::set_region(QString region){this->region=region;}

bool Rdv::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id_rdv);

          query.prepare("INSERT INTO GS_RDV (ID_RDV, DATE_RDV, HEURE_RDV, REGION) "
                        "VALUES (:ID_RDV, :DATE_RDV, :HEURE_RDV, :REGION)");
          query.bindValue(":ID_RDV", id_string);
          query.bindValue(":DATE_RDV", date_rdv);
          query.bindValue(":HEURE_RDV", heure_rdv);     // les info ecrit dans les le_edit ne seront pas envoyée directement
                                                         // la requete au niveau de la base donnée on aura une liaison avant
                                                        // de faire l'execution grace au binding (bindvalue)
          query.bindValue(":REGION", region);

          return query.exec();
}


QSqlQueryModel* Rdv::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM GS_RDV");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));   //Pour modifier les textes d'en-tête, appelez setHeaderData() sur le modèle.
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));

          return model;
}

bool Rdv::supprimer(int id)
{
    QSqlQuery query;
QString id_string= QString::number(id);
          query.prepare("Delete from GS_RDV where ID_RDV=:id");

          query.bindValue(":id", id_string);

          return query.exec();

}

bool Rdv::modifier()
{

    QSqlQuery query;

    query.prepare("update  GS_RDV SET DATE_RDV=:DATE_RDV, HEURE_RDV=:HEURE_RDV, REGION=:REGION WHERE ID_RDV=:ID_RDV");

    query.bindValue(":ID_RDV",id_rdv);
    query.bindValue(":DATE_RDV",date_rdv);
    query.bindValue(":HEURE_RDV",heure_rdv);
    query.bindValue(":REGION",region);

    return query.exec();

}




