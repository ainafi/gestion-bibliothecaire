#ifndef SUPPRIMERLECTEUR_H
#define SUPPRIMERLECTEUR_H

#include <QDialog>

namespace Ui {
class supprimerLecteur;
}

class supprimerLecteur : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerLecteur(QWidget *parent = nullptr);
    ~supprimerLecteur();

private slots:
    void on_supprimerLecteur_2_clicked();

private:
    Ui::supprimerLecteur *ui;
};

#endif // SUPPRIMERLECTEUR_H
