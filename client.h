#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
  private:
    QString nom , prenom , sexe , domaine, adresse , mail,date;
    int numero,cin;
    // QDate date(int j,int m, int an);
public:
    //constructeurs
    Client();
    Client(QString,QString,QString,QString,QString,QString,int,int,QString);


    //getters
    QString getNom();
    QString getPrenom();
    QString getDomaine();
    int getCin();

    //setters
    void setNom(QString n);
    void setPrenom(QString p);
    void setDomaine(QString d);
    void setCin(int c);

    //fonctionalites
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);


};

#endif // CLIENT_H
