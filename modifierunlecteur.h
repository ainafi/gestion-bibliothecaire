#ifndef MODIFIERUNLECTEUR_H
#define MODIFIERUNLECTEUR_H

#include <QDialog>
#include "createlecteur.h" // Include the header for createLecteur

namespace Ui {
class modifierUnLecteur;
}

class modifierUnLecteur : public QDialog
{
    Q_OBJECT

public:
    explicit modifierUnLecteur(QWidget *parent = nullptr);
    ~modifierUnLecteur();

private slots:
    void on_SaveModif_clicked();

private:
    Ui::modifierUnLecteur *ui;
    createLecteur *ptrCreateLecteur; // Declare the pointer to createLecteur
};

#endif // MODIFIERUNLECTEUR_H
