#include "stat_categorie.h"
#include "ui_stat_categorie.h"

stat_categorie::stat_categorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_categorie)
{
    ui->setupUi(this);
}

stat_categorie::~stat_categorie()
{
    delete ui;
}

void stat_categorie::choix_pie()
{

    vector<QString> liste_cat;  //classe QVector est une classe modèle qui fournit un tableau dynamique
    vector<qreal> count;
    QSqlQuery q1,q2;
    qreal tot=0,c;
    q1.prepare("SELECT DISTINCT REGION FROM GS_RDV");    //Pour éviter des redondances dans les résultats il faut simplement ajouter DISTINCT après le mot SELECT
    q1.exec();
    while (q1.next()){
        liste_cat.push_back(q1.value(0).toString());
    }

    q1.prepare("SELECT * FROM GS_RDV");
    q1.exec();
    while (q1.next()){
        tot++;
    }

    for (auto i = liste_cat.begin(); i != liste_cat.end(); ++i) {
         q2.prepare("SELECT * FROM GS_RDV where REGION = :m");
         q2.bindValue(":m", *i);
         q2.exec();
         c=0;
         while (q2.next()){c++;}
         count.push_back(c/tot);

    }


// Define slices and percentage of whole they take up
QPieSeries *series = new QPieSeries();
for(unsigned int i = 0; i < liste_cat.size(); i++)
series->append(liste_cat[i] ,count[i]);




// Create the chart widget
QChart *chart = new QChart();

// Add data to chart with title and show legend
chart->addSeries(series);
chart->legend()->show();


// Used to display the chart
chartView = new QChartView(chart,ui->label);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}
