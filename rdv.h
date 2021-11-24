#ifndef RDV_H
#define RDV_H
#include <QString>
#include "QSqlQueryModel"
class Rdv
{
public:
    Rdv();

    Rdv(int, QString , QString , QString, int, int);

    QString get_date();
    QString get_heure();
    int get_id();
    QString get_region();
    int get_id_p();
    int get_id_c();

    void set_date(QString);
    void set_heure(QString);
    void set_id(int);
    void set_region(QString);
    void set_id_p(int);
    void set_id_c(int);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

    //bool recherche(int);
    QSqlQueryModel* recherche(int);
    QSqlQueryModel* trier_rdv_id();
    QSqlQueryModel* trier_rdv_decroi_id();

    QSqlQueryModel* afficher_partenaire();

    QSqlQueryModel* pdf();

    QSqlQueryModel * statistic();
    //void choix_stat();

private:
    int id_rdv, id_p, id_c;
    QString date_rdv, heure_rdv, region;

};




#endif // RDV_H
