#include "supprimerlecteur.h"
#include "ui_supprimerlecteur.h"

supprimerLecteur::supprimerLecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::supprimerLecteur)
{
    ui->setupUi(this);
}

supprimerLecteur::~supprimerLecteur()
{
    delete ui;
}
