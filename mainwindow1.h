#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "reclamation.h"
#include "prime.h"
#include <QMainWindow>
#include "arduino.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajoutersirine_clicked();
    void on_pb_suppsirine_clicked();
    void on_pb_modifiersirine_clicked();


    void on_pb_recherchersirine_clicked();

    void on_pb_ajout_recsirine_clicked();

    void on_TAB_EMPLOYE_clicked(const QModelIndex &index);

    void on_pb_modi_recsirine_clicked();

    void on_pb_croisirine_clicked();

    void on_pb_decrsirine_clicked();
    void on_pb_supprimersirine_rec_clicked();

    void on_tab_reclsirine_clicked(const QModelIndex &index);

    void on_pushButton_2sirine_clicked();

    void on_pb_reinsirine_clicked();

    void on_pb_rein_recsirine_clicked();

    void on_pb_affectersirine_clicked();

    void on_pb_rein_psirine_clicked();

    void on_pb_calculsirine_clicked();

    void on_pbnbh_suppsirine_clicked();

    void on_pb_excelsirine_clicked();
   void on_pb_codesirine_clicked();

    void on_radioButton_joursirine_toggled(bool checked);

    void on_radioButton_nuitsirine_toggled(bool checked);

    //void on_pb_chercher_recsirine_clicked();

private:
Ui::MainWindow *ui;
Employe Etmp;
reclamation R;
prime p;

// arduino A;
};


#endif // MAINWINDOW_H
