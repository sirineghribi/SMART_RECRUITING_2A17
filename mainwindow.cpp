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

    int nbclient=ui->les_heurs->text().toInt();
    Domaine D(nom,ref,nbclient);

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

    int nbclient=ui->les_heurs->text().toInt();
    Domaine D(nom,ref,nbclient);

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
{/*

        //ui->stackedWidget_2->setCurrentIndex(1);
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from GS_DOMAINE where nbclient < 20 ");
        float salaire=model->rowCount();
        model->setQuery("select * from facture where nbclient  between 20 and 30 ");
        float salairee=model->rowCount();
        model->setQuery("select * from facture where nbclient >30 ");
        float salaireee=model->rowCount();
        float total=salaire+salairee+salaireee;
        QString a=QString("moins de 20 . "+QString::number((nbclient*100)/total,'D',2)+"%" );
        QString b=QString("entre 20 et 30 .  "+QString::number((nbclient*100)/total,'D',2)+"%" );
        QString c=QString("plus de 30 DT ."+QString::number((nbclient*100)/total,'D',2)+"%" );
        QPieSeries *series = new QPieSeries();
        series->append(a,nom);
        series->append(b,nom);
        series->append(c,nom);
        if (salaire!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( salairee!=0)
        {
            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            //slice1->setExploded();
            slice1->setLabelVisible();
        }
        if(nbclient!=0)
        {
            // Add labels to rest of slices
            QPieSlice *slice2 = series->slices().at(2);
            //slice1->setExploded();
            slice2->setLabelVisible();
        }
        // Create the chart widget
        QChart *chart = new QChart();
        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("nbclient Par domaine :Nombre Des clients "+ QString::number(total));
        chart->legend()->hide();
        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
        */

}
