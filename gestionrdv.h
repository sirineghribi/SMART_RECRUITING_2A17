#ifndef GESTIONRDV_H
#define GESTIONRDV_H
#include <QMainWindow>
#include "rdv.h"
#include <QDialog>
#include "stat_categorie.h"





/*
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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

#include <iostream>
#include <vector>
using namespace std;
QT_CHARTS_USE_NAMESPACE
*/





namespace Ui {
class gestionrdv;
}

class gestionrdv : public QDialog
{
    Q_OBJECT

public:
    explicit gestionrdv(QWidget *parent = nullptr);
    ~gestionrdv();






    //QChartView *chartView ; //A
    //void choix_pie();       //B








private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_generer_pdf_clicked();

    void on_pb_tri_asc_clicked();

    void on_pb_tri_desc_clicked();

    void on_pb_stat_clicked();

    void on_pb_aff_partenai_clicked();

private:
    Ui::gestionrdv *ui;
    Rdv r,r2;
    stat_categorie *third;

};

#endif // GESTIONRDV_H
