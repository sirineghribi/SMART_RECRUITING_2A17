#include "gestionrdv.h"
#include "ui_gestionrdv.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

gestionrdv::gestionrdv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionrdv)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999, this));
    ui->tab_rdv->setModel(r.afficher());
}

gestionrdv::~gestionrdv()
{
    delete ui;
}

void gestionrdv::on_pb_ajouter_clicked()
{
    int id_rdv=ui->le_id->text().toInt();
    QString date_rdv=ui->le_date->text();
    QString heure_rdv=ui->le_heure->text();
    QString region=ui->le_region->text();
    Rdv r(id_rdv, date_rdv, heure_rdv, region);
    bool test=r.ajouter();
    QMessageBox msgBox;

    if (test) // si requete executé
    {
        msgBox.setText("Ajout avec succes.");
        ui->tab_rdv->setModel(r.afficher()); // refresh actualiser l'affichage
    }
    else
        msgBox.setText("Echec de l'ajout.");
        msgBox.exec();

}



void gestionrdv::on_pb_supp_clicked()
{

    int id=ui->le_id_supp->text().toInt();

    Rdv r;

    bool test=r.supprimer(id);
    if(test)
    {
            ui->tab_rdv->setModel(r.afficher());
         QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression failedd.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void gestionrdv::on_pb_modifier_clicked()
{
    /*
    int id=ui->le_id_modifier->text().toInt();
    QString date_rdv=ui->le_date_modifier->text();
    QString heure_rdv=ui->le_heure_modifier->text();
    QString region=ui->le_region_modifier->text();
    Rdv r(id, date_rdv, heure_rdv, region); */

    int id_rdv=ui->le_id->text().toInt();
    QString date_rdv=ui->le_date->text();
    QString heure_rdv=ui->le_heure->text();
    QString region=ui->le_region->text();
    Rdv r(id_rdv, date_rdv, heure_rdv, region);

    bool test=r.modifier();

        if(test)
        {
            ui->tab_rdv->setModel(r.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("update successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}
