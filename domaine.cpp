#include "domaine.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
#include<QSqlRecord>
#include<QTextStream>
#include<QFile>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QVariant>

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
   int Domaine::gethours(){return hours;}
   void Domaine::setNom(QString n){nom=n;}
   void Domaine::setRef(int ref){this->ref=ref;}
   void Domaine::sethours(int hours){this->hours=hours;}

bool Domaine::ajouter()
{
    QSqlQuery query;
    QString ref_string=QString::number(ref);
    QString hours_string=QString::number(hours);
    query.prepare("INSERT INTO DOMAINE ( ref,nom,hours) "
        "VALUES (:ref, :nom, :hours)");


        query.bindValue(":ref", ref_string);
        query.bindValue(":nom", nom);
        query.bindValue(":hours", hours_string);
        return query.exec();
}
bool Domaine::supprimer(int ref)
{
    QSqlQuery query;
    query.prepare("Delete from DOMAINE where ref=:ref");
        query.bindValue(0, ref);
        return query.exec();
}
QSqlQueryModel* Domaine::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM DOMAINE");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("hours"));
     return model;

}
bool Domaine::modifier( )
{

    QSqlQuery query;
     query.prepare("UPDATE DOMAINE set ref=:ref, nom=:nom,hours=:hours where ref= :ref");

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
    query.prepare("select * from DOMAINE where ref=:ref ");
    query.addBindValue(ref_string);
    query.exec();

        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("hours"));

    return model;
}
QSqlQueryModel *Domaine::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from DOMAINE order by nom ASC") ;
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("hours"));



    return  model ;

}
void Domaine::PrintTable( QPrinter* printer, QSqlQuery&  Query )
{
    QString strStream;
      QTextStream out(&strStream);

      const int rowCount = Query.size();
      const int columnCount = Query.record().count();

      out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("TITLE OF TABLE")
          <<  "</head>\n"
          "<body bgcolor=#ffffff link=#5000A0>\n"
          "<table border=1 cellspacing=0 cellpadding=2>\n";

      // headers
      out << "<thead><tr bgcolor=#f0f0f0>";
      for (int column = 0; column < columnCount; column++)
        out << QString("<th>%1</th>").arg(Query.record().fieldName(column));
      out << "</tr></thead>\n";

      while (Query.next()) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
          QString data = Query.value(column).toString();
          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
      }

      out <<  "</table>\n"
          "</body>\n"
          "</html>\n";

      QTextDocument document;
      document.setHtml(strStream);
      document.print(printer);
}
void Domaine::exporter_PDF()
{

   QPrinter printer(QPrinter::HighResolution);
     printer.setOrientation(QPrinter::Portrait);
     printer.setPageSize(QPrinter::A4);
     printer.setOutputFormat(QPrinter::PdfFormat);

     printer.setOutputFileName("Domaines.pdf");
    QPrintDialog dlg(&printer, 0);

     QSqlQuery query;
      query.prepare("SELECT * from DOMAINE");
       query.exec();
     PrintTable(&printer, query);

}
QSqlQueryModel *Domaine::list_clients(QString val)
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT  CLIENT.cin,DOMAINE.ref,DOMAINE.nom FROM DOMAINE FULL JOIN CLIENT ON CLIENT.cin=DOMAINE.cin WHERE DOMAINE.nom LIKE '"+val+"'");
   return model;
}
QSqlQueryModel *Domaine::list_partenaires(QString val)
{
   QSqlQueryModel * model=new QSqlQueryModel();
   int v=val.toInt();
   QSqlQuery q;
    q.prepare("SELECT  PARTENAIRE.id,DOMAINE.ref,DOMAINE.nom FROM DOMAINE FULL JOIN PARTENAIRE ON PARTENAIRE.id=DOMAINE.id WHERE DOMAINE.id = :val");
    q.bindValue(":val",v);
    q.exec();
    model->setQuery(q);
    return model;
}




