#include "supprimerlecteur.h"
#include "ui_supprimerlecteur.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
supprimerLecteur::supprimerLecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::supprimerLecteur)
{
    ui->setupUi(this);
}

supprimerLecteur::~supprimerLecteur()
{
    delete ui;
}

void supprimerLecteur::on_supprimerLecteur_2_clicked()
{
    QString numLecteur=ui->numLecteur->text();
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        database = QSqlDatabase::addDatabase("QMYSQL");
        database.setHostName("localhost");
        database.setDatabaseName("GestionBibliotecaire");
        database.setUserName("gestionuser");
        database.setPassword("password");
    }

    if (!database.open()) {
        qDebug() << "Error: connection with database failed - " << database.lastError().text();
        // QMessageBox::critical(this, "Database Connection Error", database.lastError().text());
        return;
    }
}

