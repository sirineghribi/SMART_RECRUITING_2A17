#ifndef DOMAINE_H
#define DOMAINE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtPrintSupport/QPrinter>

class Domaine
{
    QString nom;
    int ref,nbclient;
public:
    //constructeurs
    Domaine();
    Domaine(QString,int,int);
    //getters
    QString getNom();
   int getRef();
   int getnbclient();
   //setters
   void setNom(QString n);
   void setRef(int ref);
   void setnbclient(int nbclient);
   //functionality
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier();
   QSqlQueryModel * rechercher(int);
   QSqlQueryModel* trier();
   void PrintTable( QPrinter* printer, QSqlQuery&  Query );
   void exporter_PDF();
   //QSqlQueryModel *Domaine::list_clients(QString val);
//QSqlQueryModel *Domaine::list_partenaires(QString val)
};


#endif // DOMAINE_H
