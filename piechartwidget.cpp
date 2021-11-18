#include "piechartwidget.h"

#include<QPainter>
#include <cmath>
# define PI           3.14159265358979323846

PieChartWidget::PieChartWidget(QWidget *parent) :
    QWidget(parent)
{

}
void PieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
       QRectF size;
       painter.setPen(QPen(Qt::black, 2));

       if (this->height() > this->width()) {
          size = QRectF(50, 5, this->width() - 10, this->width() - 10);// x=50 y=5
       } else {
          size = QRectF(50, 5, this->height() - 5, this->height() - 10);
       }

       double sum = 0.0, startAng = 0.0;
       double angle, endAng;
       double percent;
       int qvValues [2]={2,4};
       sum=6;
              for (int i = 0; i < 2; i++) {
                 percent = qvValues[i] / sum;
                 angle = percent * 360.0;
                 endAng = startAng + angle;
               if (i==0)
                 painter.setBrush(Qt::darkBlue);
               if (i==1)
                 painter.setBrush(Qt::darkGray);
                 painter.drawPie(size, static_cast<int>(startAng * 16),
                                 static_cast<int>(angle * 16));
                 startAng = endAng;
                 if (percent != 0) {
                               if (i==1)
                         painter.drawText(745 , 145, QString::number(percent * 100) + "%");

                                if (i==0)
                         painter.drawText(745 , 65, QString::number(percent * 100) + "%");


                                              }
              }

                  QRect rect = QRect(885, 120, 70, 40);
                  painter.drawText(rect, Qt::AlignCenter,
                                    "homme");
                  painter.setBrush(Qt::darkGray);
                  painter.drawRect(QRect(835,120, 40, 40));



                  QRect rectt = QRect(885, 40, 70, 40);
                  painter.drawText(rectt, Qt::AlignCenter,
                                          "femme");
                  painter.setBrush(Qt::darkBlue);
                  painter.drawRect(QRect(835, 40, 40, 40));
                  /* double draw_x =this-> width() / 2 +
                                   cos(PI* (endAng / 180.0 - angle / 360.0)) * this->width() / 4.0;
                   double draw_y = this->height() / 2 +
                                   sin(PI * (endAng / 180.0 - angle / 360.0)) * this->width() / 4.0;
                  */


       }

