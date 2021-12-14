#ifndef PARTENAIRES_H
#define PARTENAIRES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
#include <QTextDocument>
#include <QPrinter>
#include <QTableView>
#include <QFileDialog>
#include <QFileInfo>
#include <QCoreApplication>
#include <QTextStream>


class partenaires
{
public:
    partenaires();
        partenaires(QString ,int ,QString ,int,QString ,int );
        //getters
        int getIDENTIFIANT(){return IDENTIFIANT;};
        QString getNom(){return NOM;};
        QString getPERIODE_P() { return PERIODE_P; };
        QString getMail() { return MAIL; };
        int getNumTel() { return NUM_TEL; };
        int getNbInter() { return NB_INTERACTION; };

        //setters
        void setIDENTIFIANT(int identifiant){IDENTIFIANT=identifiant;}
        void setNom(QString nom){NOM=nom;}
        void setPERIODE_P(QString periode_p) { PERIODE_P = periode_p; }
        void setMail(QString mail) { MAIL = mail; }
        void setNumTel(int num_tel) { NUM_TEL = num_tel; }
        void setNbInter(int nbinter) { NB_INTERACTION = nbinter; }

        //fonctions
        bool ajouter();
        bool supprimer(int identifiant);
        QSqlQueryModel *afficher();
        QSqlQueryModel * rechercher(QString);
        QSqlQueryModel * trier_id();
        QSqlQueryModel * trier_nom();
        void imprimerpdf(QTableView* );
        void exporter(QTableView *);
        QVector<double> getData();
        int calculInter(int);

    private:
        QString NOM;
        int IDENTIFIANT;
        QString PERIODE_P;
        int NUM_TEL;
        QString MAIL;
        int NB_INTERACTION;
};

#endif // PARTENAIRES_H
