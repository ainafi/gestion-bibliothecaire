#include "ajouterunlivre.h"
#include "ui_ajouterunlivre.h"

ajouterUnLivre::ajouterUnLivre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ajouterUnLivre)
{
    ui->setupUi(this);
}

ajouterUnLivre::~ajouterUnLivre()
{
    delete ui;
}
