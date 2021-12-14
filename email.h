#ifndef EMAIL_H
#define EMAIL_H

#include <QFile>
#include <QDialog>
#include "smtp.h"
#include "ui_email.h"
#include <QtWidgets/QMessageBox>

namespace Ui {
class Email;
}

class Email : public QDialog
{
    Q_OBJECT

public:
    explicit Email(QWidget *parent = nullptr);
    explicit Email(QString,QString,QString,QWidget *parent = nullptr);
    void set_tmpemail(QString e){tmpemail=e;}
    ~Email();

private slots:
    void on_pushButtonSend_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::Email *ui;
    QString tmpemail;
};

#endif // EMAIL_H
