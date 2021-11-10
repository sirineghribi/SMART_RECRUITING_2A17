#ifndef RDV_H
#define RDV_H
#include <QString>
#include "QSqlQueryModel"
class Rdv
{
public:
    Rdv();

    Rdv(int, QString , QString , QString);

    QString get_date();
    QString get_heure();
    int get_id();
    QString get_region();

    void set_date(QString);
    void set_heure(QString);
    void set_id(int);
    void set_region(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

private:
    int id_rdv;
    QString date_rdv, heure_rdv, region;

};




#endif // RDV_H
