#ifndef PIECHARTWIDGET2_H
#define PIECHARTWIDGET2_H
#include <QWidget>

class PieChartWidget2 :public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget2(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // PIECHARTWIDGET2_H
