#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
  private:
    QString  nom, prenom ,date_n,sexe,adresse,domaine,mail;
    int numero,cin;
    // QDate date(int j,int m, int an);
public:
    //constructeurs
    Client();
    Client(int,QString,QString,QString,QString,QString,QString,QString,int);


    //getters
    QString getNom();
     QString getMail();
      QString getAdresse();
       QString getSexe();
    QString getPrenom();
    QString getDomaine();
     QString getDate();
    int getCin();
    int getNumero();

    //setters
    void setNom(QString n);
    void setPrenom(QString p);
    void setDomaine(QString d);
    void setMail(QString m);
    void setAdresse(QString a);
    void setSexe(QString s);
    void setDate(QString date);

    void setCin(int c);
    void setNumero(int num);

    //fonctionalites
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();


};

#endif // CLIENT_H
