#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include "arduino.h"
//s
class Client
{
  private:
    QString  cin,nom, prenom ,date_n,sexe,adresse,domaine,mail;
    int numero;

 Arduino A;
 QByteArray Data;
    // QDate date(int j,int m, int an);
public:
    //constructeurs
    Client();

    Client(QString,QString,QString,QString,QString,QString,QString,QString,int);


    //getters
    QString getNom();
     QString getMail();
      QString getAdresse();
       QString getSexe();
    QString getPrenom();
    QString getDomaine();
     QString getDate();
    QString getCin();
    int getNumero();

    //setters
    void setNom(QString n);
    void setPrenom(QString p);
    void setDomaine(QString d);
    void setMail(QString m);
    void setAdresse(QString a);
    void setSexe(QString s);
    void setDate(QString date);

    void setCin(QString c);
    void setNumero(int num);

    //fonctionalites
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * rechercher(QString );
    QSqlQueryModel * trier(QString);
    void PDF();
    void PrintTable( QPrinter* printer, QSqlQuery&  Query );
    QSqlQueryModel * liste_reclamation (QString );
    QSqlQueryModel * liste_clients (QString,QString  );
  void  update_ard ();
  void  update_ard_1 ();
  int nbrclient ();
   int nbrfemme ();
    int nbrhomme();
   // bool liste_reclamation();
   // bool rechercher (QString);
     //QSqlQueryModel * somme_client();


};

#endif // CLIENT_H