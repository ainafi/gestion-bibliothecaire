#include "saisiedespretes.h"
#include "ui_saisiedespretes.h"

saisieDesPretes::saisieDesPretes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saisieDesPretes)
{
    ui->setupUi(this);
}

saisieDesPretes::~saisieDesPretes()
{
    delete ui;
}
