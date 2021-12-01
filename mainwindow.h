#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "arduino.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_ajouter2_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_rechercher_2_clicked();
    void on_trier_2_clicked();
    void on_PDF_clicked();
    void on_ok_clicked();
    void on_ok2_clicked();
    void on_pushButton_3_clicked();


    //arduino
    //void on_pushButton_clicked();   // bouton medecine
    //void on_pushButton_2_clicked(); // bouton inegieurie





    void on_bibi_clicked();

    void on_ING_clicked();

private:
    Ui::MainWindow *ui;
    Client C;
      QByteArray data;
    Arduino A;
};
#endif // MAINWINDOW_H
