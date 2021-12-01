#ifndef STAT_CATEGORIE_H
#define STAT_CATEGORIE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <iostream>
#include <vector>
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


using namespace std;

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_categorie;
}

class stat_categorie : public QDialog
{
    Q_OBJECT

public:
    explicit stat_categorie(QWidget *parent = nullptr);
    ~stat_categorie();

    QChartView *chartView;
    void choix_pie();

private:
    Ui::stat_categorie *ui;
};

#endif // STAT_CATEGORIE_H
