#ifndef DOMAINE_H
#define DOMAINE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

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
   int getHours();
   //setters
   void setNom(QString n);
   void setRef(int ref);
   void setHours(int hours);
   //functionality
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier();

};


#endif // DOMAINE_H
