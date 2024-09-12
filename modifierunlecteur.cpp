#include "modifierunlecteur.h"
#include "ui_modifierunlecteur.h"

modifierUnLecteur::modifierUnLecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifierUnLecteur)
{
    ui->setupUi(this);
}

modifierUnLecteur::~modifierUnLecteur()
{
    delete ui;
}
