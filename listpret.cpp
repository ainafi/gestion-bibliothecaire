#include "listpret.h"
#include "ui_listpret.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
listPret::listPret(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listPret)
{
    ui->setupUi(this);
}

listPret::~listPret()
{
    delete ui;
}

void listPret::on_pushButton_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setDatabaseName("GestionBibliotecaire");
    database.setUserName("gestionuser");
    database.setPassword("password");

    if (!database.isOpen() && !database.open()) {
        qDebug() << "Error: connection with database failed - " << database.lastError().text();
        QMessageBox::critical(this, "Database Connection Error", database.lastError().text());
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(this, database);
    model->setTable("Pret");
    model->select();

    if (model->lastError().isValid()) {
        qDebug() << "Error: failed to query data - " << model->lastError().text();
        QMessageBox::critical(this, "Database Query Error", model->lastError().text());
        delete model;
        return;
    } else {
        qDebug() << "Data queried successfully!";
        ui->tableView->setModel(model);
    }
}

