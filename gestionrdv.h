#ifndef GESTIONRDV_H
#define GESTIONRDV_H

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

private:
    Ui::gestionrdv *ui;
};

#endif // GESTIONRDV_H
