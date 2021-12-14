#include "email.h"
#include "ui_email.h"
#include "mainwindow.h"
#include "smtp.h"

Email::Email(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Email)
{
    ui->setupUi(this);
}

Email::Email(QString e,QString n,QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Email)
{
    QString contenu="Contenu";
    ui->setupUi(this);

    ui->recipient->setText(e);
    ui->username->setText("smartrecruitement2a17@gmail.com");
    ui->password->setText("SmartRecruitement217");
    ui->password->setEchoMode(QLineEdit::Password);


}
Email::~Email()
{
    delete ui;
}

void Email::on_pushButtonSend_clicked()
{
    Smtp* smtp = new Smtp(ui->username->text(), ui->password->text(), "smtp.gmail.com", 465);

    smtp->sendMail(ui->username->text(), ui->recipient->text() , ui->subject->text() ,ui->message->toPlainText());

}


void Email::on_pushButtonCancel_clicked()
{
    this->close();
}

