#include "gestionrdv.h"
#include "ui_gestionrdv.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPrinter>
#include <QPainter>
#include <QFileInfo>
#include <QTextStream>
#include <qfiledialog.h>
#include <QTextDocument>
#include <QPrintDialog>

#include <QtPrintSupport/QPrinter>
#include <QPixmap>
#include "QMessageBox"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>

#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>

gestionrdv::gestionrdv(QWidget *parent) :  // constructeur du mainwindow (gestionrdv)
    QDialog(parent),
    ui(new Ui::gestionrdv)
{
    ui->setupUi(this);

    // controle de saisie //
    ui->le_region->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->le_id->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_id_p->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_id_c->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_date->setValidator(new QRegExpValidator(QRegExp("[0-9 -]{10}")));
    ui->le_heure->setValidator(new QRegExpValidator(QRegExp("[0-9 :]{5}")));



    ui->tab_rdv->setModel(r.afficher());
    ui->tab_tri_rech->setModel(r2.afficher());
    ui->tab_afficher_partenaire->setModel(r2.afficher_partenaire());
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
    int id_p=ui->le_id_p->text().toInt();
    int id_c=ui->le_id_c->text().toInt();
    Rdv r(id_rdv, date_rdv, heure_rdv, region, id_p, id_c);
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

    //Rdv r;

    bool test=r.supprimer(id);
    if(test)
    {

         QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tab_rdv->setModel(r.afficher());

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestionrdv::on_pb_modifier_clicked()
{

    int id_rdv=ui->le_id->text().toInt();
    QString date_rdv=ui->le_date->text();
    QString heure_rdv=ui->le_heure->text();
    QString region=ui->le_region->text();
    int id_p=ui->le_id_p->text().toInt();
    int id_c=ui->le_id_c->text().toInt();
    Rdv r(id_rdv, date_rdv, heure_rdv, region, id_p, id_c);

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


void gestionrdv::on_pb_rechercher_clicked()
{
    int id=ui->le_recherche->text().toInt();
    ui->tab_tri_rech->setModel(r2.recherche(id));
}


void gestionrdv::on_pb_tri_asc_clicked()
{
        //Rdv r;
        ui->tab_tri_rech->setModel(r2.trier_rdv_id());
}



void gestionrdv::on_pb_tri_desc_clicked()
{
        ui->tab_tri_rech->setModel(r2.trier_rdv_decroi_id());
}



void gestionrdv::on_pb_generer_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream); //outsignifie que l' initialisation d'une valeur est effectuée dans une fonction



                const int rowCount = ui->tab_rdv->model()->rowCount();  //retourner le nombre de ligne affecter a la requete
                const int columnCount = ui->tab_rdv->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tab_rdv->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_rdv->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_rdv->isColumnHidden(column)) {
                            QString data = ui->tab_rdv->model()->data(ui->tab_rdv->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;

}



void gestionrdv::on_pb_stat_clicked()
{  
    third = new stat_categorie(this); // pour ouvrir la fenetre contenant stat
    third->choix_pie();
    third->show();

}


void gestionrdv::on_pb_aff_partenai_clicked()
{
    ui->tab_afficher_partenaire->setModel(r2.afficher_partenaire());
}
