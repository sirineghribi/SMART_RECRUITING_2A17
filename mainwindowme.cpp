#include "mainwindowme.h"
#include "ui_mainwindowme.h"
#include<QPixmap>
#include<QDebug>
#include<QSqlQuery>
#include "mainwindow.h"

#include"arduino.h"

MainWindowme::MainWindowme(QWidget *parent)
    : QMainWindowme(parent)
    , ui(new Ui::MainWindowme)
{
    ui->setupUi(this);

}

MainWindowme::~MainWindowme()
{
    delete ui;
}



void MainWindowme::on_menuBoutonemploye_clicked()
{
    MainWindow p;
    p.Setm            p.exec();

}
