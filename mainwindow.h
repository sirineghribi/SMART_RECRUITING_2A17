#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "reclamation.h"
#include "prime.h"
#include <QMainWindow>

#include <QSound>
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
    void on_pb_ajouter_clicked();
    void on_pb_supp_clicked();
    void on_pb_modifier_clicked();


    void on_pb_rechercher_clicked();

    void on_pb_ajout_rec_clicked();

    void on_TAB_EMPLOYE_clicked(const QModelIndex &index);

    void on_pb_modi_rec_clicked();

    void on_pb_croi_clicked();

    void on_pb_decr_clicked();
    void on_pb_supprimer_rec_clicked();

    void on_tab_recl_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pb_rein_clicked();

    void on_pb_rein_rec_clicked();

    void on_pb_affecter_clicked();

    void on_pb_rein_p_clicked();

    void on_pb_calcul_clicked();

    void on_pbnbh_supp_clicked();




    void on_pb_excel_clicked();



    void on_pb_code_clicked();

private:
Ui::MainWindow *ui;
Employe Etmp;
reclamation R;
prime p;
QSound *son;
};


#endif // MAINWINDOW_H
