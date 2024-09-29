#include "supprimerunpret.h"
#include "ui_supprimerunpret.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

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

void supprimerUnPret::on_pushButton_clicked()
{
    QString numerodupret = ui->numerodupret->text();

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
        QMessageBox::critical(this, "Database Connection Error", database.lastError().text());
        return;
    }

    QSqlQuery query;

    // Vérification de l'existence du prêt
    query.prepare("SELECT numLivre FROM Pret WHERE numPret = :numerodupret");
    query.bindValue(":numerodupret", numerodupret);
    if (!query.exec()) {
        qDebug() << "Pret check error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la vérification du prêt");
        database.close(); // Close the database
        return;
    }

    QString numLivre;
    if (query.next()) {
        numLivre = query.value(0).toString();
    } else {
        QMessageBox::warning(this, "Error", "Numéro de prêt inexistant");
        database.close(); // Close the database
        return;
    }

    // Suppression du prêt
    query.prepare("DELETE FROM Pret WHERE numPret = :numerodupret");
    query.bindValue(":numerodupret", numerodupret);
    if (!query.exec()) {
        qDebug() << "Delete pret error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la suppression du prêt");
        database.close(); // Close the database
        return;
    }
    QMessageBox::information(this, "Success", "Prêt supprimé avec succès ");
    database.close(); // Close the database after all operations
}
