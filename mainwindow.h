#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <domaine.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_supp_button_clicked();

    void on_modify_button_clicked();

    void on_tab_domaine_activated(const QModelIndex &index);

    void on_search_button_clicked();

    void on_Tri_button_clicked();

    void on_pdf_generate_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_stats_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Domaine D;
};
#endif // MAINWINDOW_H
