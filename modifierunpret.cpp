#include "modifierunpret.h"
#include "ui_modifierunpret.h"

modifierUnPret::modifierUnPret(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifierUnPret)
{
    ui->setupUi(this);
}

modifierUnPret::~modifierUnPret()
{
    delete ui;
}
