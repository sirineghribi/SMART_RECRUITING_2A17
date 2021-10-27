#ifndef RDV_H
#define RDV_H
#include <QString>
#include "QSqlQueryModel"
class Rdv
{
public:
    Rdv();

    Rdv(int, int , int , QString ,QString);

    int get_date();
    int get_heure();
    int get_id();
    QString get_region();
    QString get_domaine();

    void set_date(int);
    void set_heure(int);
    void set_id(int);
    void set_region(QString);
    void set_domaine(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
    int date, heure,id;
    QString region,domaine;

};




#endif // RDV_H
