#include "supprimerunlivre.h"
#include "ui_supprimerunlivre.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

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

void supprimerUnLivre::on_pushButton_clicked()
{
    QString numLivre = ui->numLivre->text();

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

    // Vérification de l'existence du livre
    query.prepare("SELECT COUNT(*) FROM Livre WHERE numLivre = :numLivre");
    query.bindValue(":numLivre", numLivre);
    if (!query.exec()) {
        qDebug() << "Livre check error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la vérification du livre");
        database.close(); // Close the database
        return;
    }

    if (!query.next() || query.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Error", "Numéro de livre inexistant");
        database.close(); // Close the database
        return;
    }

    // Suppression du livre
    query.prepare("DELETE FROM Livre WHERE numLivre = :numLivre");
    query.bindValue(":numLivre", numLivre);
    if (!query.exec()) {
        qDebug() << "Delete livre error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la suppression du livre");
        database.close(); // Close the database
        return;
    }

    QMessageBox::information(this, "Success", "Livre supprimé avec succès");
    database.close(); // Close the database after all operations
}
