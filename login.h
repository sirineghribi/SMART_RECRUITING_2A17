#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_label_linkActivated(const QString &link);

    void on_pb_login_clicked();

private:
    Ui::login *ui;
};
#endif // MAINWINDOW_H

