#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "reclamation.h"
#include <QMainWindow>

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

    void on_radioButton_id_clicked();

    void on_pb_modi_rec_clicked();

    void on_pb_afficher_clicked();

private:
 Ui::MainWindow *ui;
 Employe Etmp;
reclamation R;
};


#endif // MAINWINDOW_H
