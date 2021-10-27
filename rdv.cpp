#include "rdv.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Rdv::Rdv()
{
    id=0; date=0; heure=0;     region= "";  domaine= "";
}


Rdv::Rdv(int id, int date, int heure, QString region,QString domaine)
{
    this->id=id; this->date=date; this->heure=heure; this->region=region; this->domaine=domaine;
}


int Rdv::get_date(){return date;}

int Rdv::get_heure(){return heure;}

int Rdv::get_id(){return id;}

QString Rdv::get_region(){return region;}

QString Rdv::get_domaine(){return domaine;}

void Rdv::set_date(int date){this->date=date;}

void Rdv::set_heure(int heure){this->heure=heure;}

void Rdv::set_id(int id){this->id=id;}

void Rdv::set_region(QString region){this->region=region;}

void Rdv::set_domaine(QString domaine){this->domaine=domaine;}

bool Rdv::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);
    QString date_string= QString::number(date);
    QString heure_string= QString::number(heure);

          query.prepare("INSERT INTO rdv (id, date, heure, region, domaine) "
                        "VALUES (:id, :date, :heure, :region, :domaine)");
          query.bindValue(":id", id_string);
          query.bindValue(":date", date_string);
          query.bindValue(":heure", heure_string);
          query.bindValue(":region", region);
          query.bindValue(":domaine", domaine);

          return query.exec();
}


QSqlQueryModel* Rdv::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM Rdv");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Heure"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Region"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Domaine"));

          return model;
}

bool Rdv::supprimer(int)
{
    QSqlQuery query;

          query.prepare("Delete from rdv where id=:id");

          query.bindValue(":id", id);

          return query.exec();

}




