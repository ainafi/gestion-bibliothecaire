#include "supprimerunpret.h"
#include "ui_supprimerunpret.h"

supprimerUnPret::supprimerUnPret(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::supprimerUnPret)
{
    ui->setupUi(this);
}

supprimerUnPret::~supprimerUnPret()
{
    delete ui;
}
