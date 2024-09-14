#ifndef PRETE_H
#define PRETE_H

#include <QDialog>

namespace Ui {
class prete;
}

class prete : public QDialog
{
    Q_OBJECT

public:
    explicit prete(QWidget *parent = nullptr);
    ~prete();

private slots:
    void on_SaisirLePrete_clicked();

private:
    Ui::prete *ui;
};

#endif // PRETE_H
