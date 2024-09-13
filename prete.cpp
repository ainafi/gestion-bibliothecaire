#include "prete.h"
#include "ui_prete.h"

prete::prete(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::prete)
{
    ui->setupUi(this);
}

prete::~prete()
{
    delete ui;
}
