#include "rdv.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>


#include <QTextDocument>

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

bool Rdv::recherche(int id)
{

    QString id_string= QString::number(id);
    QSqlQuery query;
    query.prepare("select * from GS_RDV where ID_RDV=:id");
    query.bindValue(":id",id_string);
    query.exec();
    if(query.next())
    {
        return true;
    }

    return false;
}



void Rdv::pdf(QString filename,int id,QString filepath)
{
    /*
  //  LE_ID_SUPP
    Rdv r;
    r.modifier();
    //qDebug<< p.Get_nom().toString;
    qDebug()<<QString(this->get_id());
    QString id_string= QString::number(id);
    //QString s = QDate::currentDate().toString();
    qDebug()<<QString(r.get_id());
    QString html =
            "<html>"
    "<head>"
        "<meta charset='utf-8' />"
    "</head>"
"<style>"
".wrapper{position:relative;}"

".arrow{position:absolute;right:0px;bottom:0px;}"
"</style>"

    "<div align=right>"
       +id_string+
    "</div>"
    "<div align=left>"

       "id : "+ r.get_id()+"<br>"
    "</div>"
    "<h1 align=center>Description du rdv:" + r.get_id()+" </h1>"
    "<h3 align=justify>"
+r.get_date()+
    "</h4>"
    "<div align=right>"
"heure: "
+QString (r.get_heure())+
            "<br>"
"region: "
+QString (r.get_region())+
"</div>"
"<div class='wrapper'>"
"<div class='arrow'>"
"<img  src='pics/asset9.png' width='100' height='100'/>"
"</div>"
"</div>"


;

    QTextDocument document;
    document.setHtml(html);






    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filepath+"/"+filename);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);
        */

}

