#ifndef MAINWINDOWME_H
#define MAINWINDOWME_H

#include <QMainWindow>

namespace Ui {
class MainWindowme;
}

class MainWindowme : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowme(QWidget *parent = nullptr);
    ~MainWindowme();


private slots:
    void on_menuBouton_Gestionpersonnels_clicked();


    void update_label();

    void on_menuBoutonemploye_clicked();

private:
    Ui::MainWindowme *ui;

};

#endif // MAINWINDOW_H
