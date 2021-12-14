#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H
#include "client.h"

#include <QWidget>

class PieChartWidget :public QWidget
{
    Client C;
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // PIECHARTWIDGET_H
