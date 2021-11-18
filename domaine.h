#ifndef DOMAINE_H
#define DOMAINE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtPrintSupport/QPrinter>

class Domaine
{
    QString nom;
    int ref,hours;
public:
    //constructeurs
    Domaine();
    Domaine(QString,int,int);
    //getters
    QString getNom();
   int getRef();
   int gethours();
   //setters
   void setNom(QString n);
   void setRef(int ref);
   void sethours(int hours);
   //functionality
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier();
   QSqlQueryModel * rechercher(int);
   QSqlQueryModel* trier();
   void PrintTable( QPrinter* printer, QSqlQuery&  Query );
   void exporter_PDF();

   QSqlQueryModel *list_clients(QString val);
    QSqlQueryModel *list_partenaires(QString val);
};


#endif // DOMAINE_H
