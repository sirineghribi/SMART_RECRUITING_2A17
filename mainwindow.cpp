#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->la_ref->setValidator(new QIntValidator(1,99999,this));
    ui->tab_domaine->setModel(D.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    int ref=ui->la_ref->text().toInt();

    int hours=ui->les_heurs->text().toInt();
    Domaine D(nom,ref,hours);

    bool test=D.ajouter();
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("added successfully!");
        //refresh
       ui->tab_domaine->setModel(D.afficher());

    }
else
    msgBox.setText("failed to add.");
    msgBox.exec();
}


void MainWindow::on_supp_button_clicked()
{
    Domaine D1; D1.setRef(ui->ref_supp->text().toInt());
    bool test=D1.supprimer(D1.getRef());
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("deleted successfully!");

    //refresh
        ui->tab_domaine->setModel(D.afficher());

    }
else
    msgBox.setText("failed to delete.");
    msgBox.exec();
}

void MainWindow::on_modify_button_clicked()
{
    QString nom=ui->le_nom->text();
    int ref=ui->la_ref->text().toInt();

    int hours=ui->les_heurs->text().toInt();
    Domaine D(nom,ref,hours);

    bool test=D.modifier();
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("modified successfully!");
        //refresh
       ui->tab_domaine->setModel(D.afficher());
    }
else
    msgBox.setText("failed to modify.");
    msgBox.exec();

}

void MainWindow::on_search_button_clicked()
{
    int ref=ui->ref_searchinput->text().toInt();
     ui->search_tab->setModel(D.rechercher(ref));
}

void MainWindow::on_Tri_button_clicked()
{
    ui->tab_domaine->setModel(D.trier());

}


void MainWindow::on_pdf_generate_clicked()
{
    D.exporter_PDF();
}

void MainWindow::on_stats_button_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

   ui->tableView->setModel(D.list_clients(ui->lineEdit->text()));

}

void MainWindow::on_partner_button_clicked()
{
    ui->tableView_2->setModel(D.list_partenaires(ui->lineEdit_2->text()));
}
