#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "arduino.h"

//sirine
#include "employe.h"
#include "reclamation.h"
#include "prime.h"

//abderrahim

#include "domaine.h"

//amine


#include <QMainWindow>
#include "rdv.h"
#include <QDialog>

// zina

#include "partenaires.h"




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



    void on_ING_clicked();
     void on_bibi_clicked();
    void update_label();
//sirine
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

//abderrahim


        void on_pb_ajouterab_clicked();

        void on_suppab_button_clicked();

        void on_modifyab_button_clicked();

       // void on_tab_domaine_activated(const QModelIndex &index);

        void on_searchab_button_clicked();

        void on_Triab_button_clicked();

        void on_pdf_generateab_clicked();

       // void on_comboBoxab_activated(const QString &arg1);

        void on_statsab_button_clicked();

        void on_pushButtonab_clicked();

        void on_partnerab_button_clicked();


    //amine
        void on_pb_ajoutera_clicked();



                void on_pb_suppa_clicked();



                void on_pb_modifiera_clicked();



                void on_pb_recherchera_clicked();



                void on_pb_generer_pdfa_clicked();



                void on_pb_tri_asca_clicked();



                void on_pb_tri_desca_clicked();



                void on_pb_stata_clicked();



                void on_pb_aff_partenaia_clicked();

  //zina

                void on_pb_ajouter_clicked();

                   void on_pb_supprimer_clicked();
                   void on_pb_modif_clicked();
                    void on_pb_rechercher_clicked();
                    void on_pb_excel_clicked();
                     void on_lineEditRech_returnPressed();

private:
    Ui::MainWindow *ui;
    Client C;
      QByteArray data;
    Arduino A;

//sirine
    Employe Etmp;
    reclamation R;
    prime p;

    Rdv r;
    Rdv r2;
    //abderrahim

     Domaine D;
     //zina
partenaires tmp_partenaire;
partenaires pa;

};
#endif // MAINWINDOW_H
