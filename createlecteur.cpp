#include "createlecteur.h"
#include "ui_createlecteur.h"

createLecteur::createLecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createLecteur)
{
    ui->setupUi(this);
}

createLecteur::~createLecteur()
{
    delete ui;
}
