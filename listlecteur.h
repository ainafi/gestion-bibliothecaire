#ifndef LISTLECTEUR_H
#define LISTLECTEUR_H

#include <QDialog>

namespace Ui {
class listLecteur;
}

class listLecteur : public QDialog
{
    Q_OBJECT

public:
    explicit listLecteur(QWidget *parent = nullptr);
    ~listLecteur();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listLecteur *ui;
};

#endif // LISTLECTEUR_H
