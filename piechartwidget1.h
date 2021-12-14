#ifndef PIECHARTWIDGET1_H
#define PIECHARTWIDGET1_H
#include <QWidget>

class PieChartWidget1 :public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget1(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // PIECHARTWIDGET1_H
