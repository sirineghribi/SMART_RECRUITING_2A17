#ifndef GESTIONRDV_H
#define GESTIONRDV_H
#include <QMainWindow>
#include "rdv.h"
#include <QDialog>

namespace Ui {
class gestionrdv;
}

class gestionrdv : public QDialog
{
    Q_OBJECT

public:
    explicit gestionrdv(QWidget *parent = nullptr);
    ~gestionrdv();



private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_generer_pdf_clicked();
/*
public slots:

    int on_pb_generer_pdf_clicked(); */

    void on_pb_tri_asc_clicked();

    void on_pb_tri_desc_clicked();

    void on_pb_stat_clicked();

private:
    Ui::gestionrdv *ui;
    Rdv r,r2;

};

#endif // GESTIONRDV_H