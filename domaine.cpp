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
   nbclient=0;
}
    Domaine::Domaine(QString nom,int ref,int nbclient)
{ this->nom=nom;this->ref=ref; this->nbclient=nbclient;}

    QString Domaine::getNom(){return nom;}
   int Domaine::getRef(){return ref; }
   int Domaine::getnbclient(){return nbclient;}
   void Domaine::setNom(QString n){nom=n;}
   void Domaine::setRef(int ref){this->ref=ref;}
   void Domaine::setnbclient(int nbclient){this->nbclient=nbclient;}

bool Domaine::ajouter()
{
    QSqlQuery query;
    QString ref_string=QString::number(ref);
    QString nbclient_string=QString::number(nbclient);
    query.prepare("INSERT INTO GS_DOMAINE ( ref,nom,nbclient) "
        "VALUES (:ref, :nom, :nbclient)");


        query.bindValue(":ref", ref_string);
        query.bindValue(":nom", nom);
        query.bindValue(":nbclient", nbclient_string);
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
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbclient"));
     return model;

}
bool Domaine::modifier( )
{

    QSqlQuery query;
     query.prepare("UPDATE GS_DOMAINE set ref=:ref, nom=:nom,nbclient=:nbclient where ref= :ref");

     query.bindValue(":ref", ref);
     query.bindValue(":nom", nom);
     query.bindValue(":nbclient", nbclient);
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
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbclient"));

    return model;
}
QSqlQueryModel *Domaine::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GS_DOMAINE order by nom ASC") ;
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbclient"));



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
      query.prepare("SELECT * from GS_DOMAINE");
       query.exec();
     PrintTable(&printer, query);

}
/*QSqlQueryModel *Domaine::list_clients(QString val)
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT  client.cin,domaine.ref,domaine.nom FROM GS_DOMAINE FULL JOIN client ON client.cin=domaine.cin");
   return model;
} */
/*QSqlQueryModel *Domaine::list_partenaires(QString val)
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT  partenaire.cin,domaine.ref,domaine.nom FROM GS_DOMAINE FULL JOIN parteniare ON partenaire.id=domaine.ref");
   return model;
} */


