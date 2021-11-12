#include "gestionrdv.h"
#include "ui_gestionrdv.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

#include <QPrinter>
#include <QPainter>


gestionrdv::gestionrdv(QWidget *parent) :  // constructeur du mainwindow (gestionrdv)
    QDialog(parent),
    ui(new Ui::gestionrdv)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999, this));
    ui->tab_rdv->setModel(r.afficher());
    ui->tab_tri_rech->setModel(r.afficher());
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

    //Rdv r;

    bool test=r.supprimer(id);
    if(test)
    {
          //  ui->tab_rdv->setModel(r.afficher());
         QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression failed.\n"
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

void gestionrdv::on_pb_rechercher_clicked()
{
    int id=ui->le_recherche->text().toInt();

    bool test=r.recherche(id);
    if(test==1)
    {
            ui->tab_rdv->setModel(r.afficher());
         QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("id existant : recherche successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("id non existant : recherche failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}


/*
void gestionrdv::on_pb_generer_pdf_clicked()
{

    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tab_rdv->model()->rowCount();
                        const int columnCount = ui->tab_rdv->model()->columnCount();

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Liste des promotions </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_rdv->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_rdv->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tab_rdv->isColumnHidden(column)) {
                                    QString data = ui->tab_rdv->model()->data(ui->tab_rdv->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table> </center>\n"
                            "</body>\n"
                            "</html>\n";

                  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                   QPrinter printer (QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                  printer.setOutputFileName(fileName);

                   QTextDocument doc;
                    doc.setHtml(strStream);
                    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                    doc.print(&printer);

                    */


int gestionrdv::on_pb_generer_pdf_clicked()

    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("gestionRdvPDF.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              return 1;
          }
          painter.drawText(10, 10, "gestion Rdv PDF");
          painter.drawText(10, 30, "feuille 1")
          if (! printer.newPage()) {
              qWarning("failed in flushing page to disk, disk full?");
              return 1;
          }
          painter.drawText(10, 10, "gestion Rdv PDF");
          painter.end();

}
