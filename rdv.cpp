#include "rdv.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QPrinter>

#include <QTextDocument>

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




























