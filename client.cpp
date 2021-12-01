#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlRecord>
#include <QPrintDialog>
#include<QTextStream>
#include<QFile>
#include <QVariant>
#include <QMessageBox>

Client::Client()
{
    nom=" "; prenom=" "; adresse=" "; domaine=" "; sexe=" "; mail=" "; cin=" "; numero=0,date_n="";
}
Client::Client(QString  cin,QString nom,QString prenom,QString date_n,QString sexe,QString adresse,QString domaine,QString mail,int numero)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->date_n=date_n;
    this->sexe=sexe;
    this->adresse=adresse;
    this->domaine=domaine;
    this->mail=mail;
    this->numero=numero;

}

QString Client::getCin(){return cin;}
QString Client ::getNom(){return nom;}
QString Client ::getPrenom(){return prenom;}
QString Client ::getDomaine(){return domaine;}
QString Client ::getMail(){return mail;}
QString Client ::getAdresse(){return adresse;}
QString Client ::getSexe(){return sexe;}
QString Client ::getDate(){return date_n;}
int Client::getNumero(){return numero;}

void Client::setCin(QString  c){this->cin=c;}
void Client::setNom(QString n){this->nom=n;}
void Client::setPrenom(QString p){this->prenom=p;}
void Client::setDomaine(QString d){this->domaine=d;}
void Client::setMail(QString m){this->mail=m;}
void Client::setAdresse(QString a){this->adresse=a;}
void Client::setSexe(QString s){this->sexe=s;}
void Client::setDate(QString date){this->date_n=date;}
void Client::setNumero(int num){this->numero=num;}

 bool Client::ajouter()
 {


     QSqlQuery query;
     //QString cin_string = QString::number(cin);
     QString numero_string= QString::number(numero);
     QDate Date=QDate::fromString(date_n,"MM/dd/yyyy");

           query.prepare("INSERT INTO client (cin,nom,prenom,date_n,sexe,adresse,domaine,mail,numero) "
                         "VALUES (:cin, :nom, :prenom, :date_n, :sexe, :adresse, :domaine, :mail, :numero)");

           query.bindValue(":cin",cin);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":date_n",Date);
           query.bindValue(":sexe",sexe);
           query.bindValue(":adresse", adresse);
           query.bindValue(":domaine",domaine);
           query.bindValue(":mail",mail);
           query.bindValue(":numero", numero_string);
           return query.exec();



 }

 QSqlQueryModel * Client::afficher()
 {
      QSqlQueryModel* model=new  QSqlQueryModel();

            model->setQuery("SELECT* FROM client");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_n"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("domaine"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("numero"));




      return model;
 }
 bool Client::supprimer(QString  cin)
 {
     QSqlQuery query;
     query.prepare("Delete from client where cin=:cin");
     query.bindValue(0,cin);
     return query.exec();
 }
 bool Client::modifier()
{
    QSqlQuery query;


  query.prepare("UPDATE client set  cin=:cin,nom=:nom,prenom=:prenom ,date_n=:date_n,sexe=:sexe,adresse=:adresse,domaine=:domaine,mail=:mail,numero=:numero where cin=:cin");


      query.bindValue(":cin", cin);
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":date_n", date_n);
      query.bindValue(":sexe", sexe);
      query.bindValue(":adresse",adresse);
      query.bindValue(":domaine", domaine);
      query.bindValue(":mail",mail);
      query.bindValue(":numero", numero);
      return query.exec();

}


QSqlQueryModel * Client::rechercher(QString val)
 {
     //QString cin_string = QString::number(cinn);
      QSqlQueryModel* model=new  QSqlQueryModel();

       model->setQuery("SELECT* FROM client WHERE cin LIKE'"+val+"%'");
            return model;
     //QSqlQuery *query = new QSqlQuery ;
     //query->prepare("SELECT* FROM client WHERE domaine LIKE'"+dom+"%'");
     //return query->exec();
     /*if(query->exec())
     { return true;
     }
     return false ;*/
 }

QSqlQueryModel * Client::trier(QString ordre)
 {
     //QString cin_string = QString::number(cinn);
      QSqlQueryModel* model=new  QSqlQueryModel();
      if(ordre=="A-Z")
       {
          model->setQuery("SELECT* FROM client ORDER by nom ASC");
        }
      else
         model->setQuery("SELECT* FROM client ORDER by nom DESC");

            return model;
     //QSqlQuery *query = new QSqlQuery ;
     //query->prepare("SELECT* FROM client WHERE domaine LIKE 'm%');
     //return query->exec();
     /*if(query->exec())
     { return true;
     }
     return false ;*/
 }


void Client::PrintTable( QPrinter* printer, QSqlQuery&  Query )
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
void Client::PDF()
{

    QPrinter printer(QPrinter::HighResolution);
      printer.setOrientation(QPrinter::Portrait);
      printer.setPageSize(QPrinter::A4);
      printer.setOutputFormat(QPrinter::PdfFormat);

      printer.setOutputFileName("tous_les_clients.pdf");


     QPrintDialog dlg(&printer, 0);

      QSqlQuery query;

      query.prepare("SELECT * from client");

      query.exec();
      PrintTable(&printer, query);
   //  }

}

QSqlQueryModel * Client::liste_reclamation(QString val)
{
    QSqlQueryModel* model=new  QSqlQueryModel();

          model->setQuery("SELECT client.cin ,reclamation.date_reclamation,client.nom  FROM client FULL JOIN reclamation ON client.cin=reclamation.cin_client WHERE cin LIKE'"+val+"%'");






    return model;

}

/*QSqlQueryModel * Client::somme_client()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

          model->setQuery("");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("client.cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("client.nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("reclamation.date_reclamation"));*/





    //return model;

//}

QSqlQueryModel * Client::liste_clients(QString d1, QString d2)
{
    QSqlQueryModel* model=new  QSqlQueryModel();
    //QDate date1=QDate::fromString(d1,"MM/dd/yyyy");
    //QDate date2=QDate::fromString(d2,"MM/dd/yyyy");


          model->setQuery("SELECT client.cin ,rdv.dates,client.nom,rdv.heure  FROM client FULL JOIN rdv ON client.cin=rdv.id WHERE dates BETWEEN  '"+d1+"' AND '"+d2+"'");
return model;

}


void Client::update_ard()
{



    QSqlQuery query;
       query.prepare("select * FROM domaine WHERE NOM LIKE 'medecine' " );
       if ((query.exec())&&(query.next()))
                {
                 int n=query.value(4).toInt();
                 qDebug()<<n;

       if(n<25)
       {query.prepare("update domaine set nbr_tot=:nbr_tot where NOM='medecine' ");
       query.bindValue(":nbr_tot",n+=1);
       if(query.exec())
        {QMessageBox::information(nullptr, QObject::tr("not ok"),
                             QObject::tr("ajouter non effectue \n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
       }
                 }
}


void Client::update_ard_1()
{



    QSqlQuery query;
       query.prepare("select * FROM domaine WHERE NOM LIKE 'INGENIEURIE' " );
       if ((query.exec())&&(query.next()))
                {
                 int n=query.value(4).toInt();
                 qDebug()<<n;

       if(n<25)
       {query.prepare("update domaine set nbr_tot=:nbr_tot where NOM='INGENIEURIE' ");
       query.bindValue(":nbr_tot",n+=1);
       if(query.exec())
        {QMessageBox::information(nullptr, QObject::tr("not ok"),
                             QObject::tr("ajouter non effectue \n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
       }
                 }
}




