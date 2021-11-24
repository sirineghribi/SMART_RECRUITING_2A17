#include "rdv.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QPrinter>

#include <QTextDocument>




/*
#include<QWidget>
#include "gestionrdv.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "ui_gestionrdv.h"
*/


Rdv::Rdv()
{
    id_rdv=0; date_rdv=""; heure_rdv=""; region= ""; id_p=0; id_c=0;
}


Rdv::Rdv(int id, QString date, QString heure, QString region, int id_p, int id_c)
{
    this->id_rdv=id; this->date_rdv=date; this->heure_rdv=heure; this->region=region; this->id_p=id_p; this->id_c=id_c;
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
    QString id_string_c= QString::number(id_c);
    QString id_string_p= QString::number(id_p);


          query.prepare("INSERT INTO GS_RDV (ID_RDV, DATE_RDV, HEURE_RDV, REGION, ID_P, ID_C) "
                        "VALUES (:ID_RDV, :DATE_RDV, :HEURE_RDV, :REGION, :ID_P, :ID_C)");

   /* query.prepare("INSERT INTO GS_RDV (ID_RDV, DATE_RDV, HEURE_RDV, REGION, ID_P, ID_C) "
                            "VALUES (:ID_RDV, :DATE_RDV, :HEURE_RDV, :REGION, :ID_P, :ID_C)"
                  "INNER JOIN GS_PARTENAIRE ON GS_RDV.ID_P = GS_PARTENAIRE.ID INNER JOIN GS_CLIENT ON GS_RDV.ID_C = GS_CLIENT.CIN ");*/

    //query.prepare("INSERT INTO GS_RDV ( ID_RDV, DATE_RDV, HEURE_RDV, REGION, ID_P, ID_C) SELECT * FROM GS_RDV p INNER JOIN GS_CLIENT c ON c.CIN = p.ID_C INNER JOIN GS_PARTENAIRE n ON p.ID_P = n.ID");


          query.bindValue(":ID_RDV", id_string);
          query.bindValue(":DATE_RDV", date_rdv);
          query.bindValue(":HEURE_RDV", heure_rdv);
          query.bindValue(":REGION", region);
          query.bindValue(":ID_P", id_string_p);
          query.bindValue(":ID_C", id_string_c);

          return query.exec();
}


QSqlQueryModel* Rdv::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          //model->setQuery("SELECT* FROM GS_RDV");
          model->setQuery("SELECT* FROM GS_RDV INNER JOIN GS_PARTENAIRE ON GS_RDV.ID_P = GS_PARTENAIRE.ID INNER JOIN GS_CLIENT ON GS_RDV.ID_C = GS_CLIENT.CIN");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));   //Pour modifier les textes d'en-tête, appelez setHeaderData() sur le modèle.
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_P"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_C"));





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

    query.prepare("update  GS_RDV SET DATE_RDV=:DATE_RDV, HEURE_RDV=:HEURE_RDV, REGION=:REGION , ID_P=:ID_P , ID_C=:ID_C WHERE ID_RDV=:ID_RDV");

    query.bindValue(":ID_RDV",id_rdv);
    query.bindValue(":DATE_RDV",date_rdv);
    query.bindValue(":HEURE_RDV",heure_rdv);
    query.bindValue(":REGION",region);
    query.bindValue(":ID_P", id_p);
    query.bindValue(":ID_C", id_c);

    return query.exec();
}

QSqlQueryModel* Rdv::recherche(int id)
{
    QString id_string= QString::number(id);

    QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from GS_RDV where ID_RDV = :id  ");
        query.addBindValue(id_string);
        query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_P"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_C"));
    return model;

}

QSqlQueryModel* Rdv::trier_rdv_id()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from GS_RDV ORDER BY DATE_RDV ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));   //Pour modifier les textes d'en-tête, appelez setHeaderData() sur le modèle.
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
    /*model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_P"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_C"));*/
    return model;
}

QSqlQueryModel* Rdv::trier_rdv_decroi_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from GS_RDV ORDER BY DATE_RDV DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));   //Pour modifier les textes d'en-tête, appelez setHeaderData() sur le modèle.
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
    /*model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_P"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_C"));*/
    return model;
}

QSqlQueryModel* Rdv::afficher_partenaire()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT* FROM GS_RDV INNER JOIN GS_PARTENAIRE ON GS_RDV.ID_P = GS_PARTENAIRE.ID");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_P"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_C"));


          return model;

}


QSqlQueryModel* Rdv::pdf()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM GS_RDV");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));   //Pour modifier les textes d'en-tête, appelez setHeaderData() sur le modèle.
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_P"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_C"));


          return model;
}


QSqlQueryModel * Rdv::statistic()
{
    QSqlQueryModel * model=new QSqlQueryModel();


        model->setQuery("SELECT DISTINCT ID_RDV FROM GS_RDV");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));
        //model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

       return model;

}
























