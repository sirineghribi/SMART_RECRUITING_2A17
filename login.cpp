#include "login.h"
#include "ui_log.h"
#include "employe.h"
#include<QMessageBox>
#include<QSqlQueryModel>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString password = ui->l_password->text();
           QString name = ui->l_name->text();
           if (name=="gerant"&& password=="crud")
           { //aremplir//


           }
           else {
           QMessageBox::warning(this,"Login","name and password are incorrect");
           }
}
