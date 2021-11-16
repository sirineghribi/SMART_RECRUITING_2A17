#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class reclamation
{
public:
    reclamation();
    reclamation(int,QString,QString,QString);
    int getid_r();
    QString getdate_r();
    QString getsujet();
    QString getetat();

    void setid_r(int);
    void setdate_r(QString);
    void setsujet(QString);
    void setetat(QString);

    bool ajouter_rec();
    QSqlQueryModel * afficher_rec();
    bool modifier_rec();
    QSqlQueryModel *chercher_reclamation(int id_r);



private:
    int id_r;
    QString date_r ;
    QString sujet;
    QString etat;

};

#endif // RECLAMATION_H
