#include "supprimerunlivre.h"
#include "ui_supprimerunlivre.h"

supprimerUnLivre::supprimerUnLivre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::supprimerUnLivre)
{
    ui->setupUi(this);
}

supprimerUnLivre::~supprimerUnLivre()
{
    delete ui;
}
