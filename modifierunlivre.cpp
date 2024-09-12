#include "modifierunlivre.h"
#include "ui_modifierunlivre.h"

modifierUnLivre::modifierUnLivre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifierUnLivre)
{
    ui->setupUi(this);
}

modifierUnLivre::~modifierUnLivre()
{
    delete ui;
}
