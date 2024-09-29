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
    QString numLecteur = ui->numLecteur->text();
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

    // Vérification de l'existence du lecteur
    query.prepare("SELECT COUNT(*) FROM Lecteur WHERE numLecteur = :numLecteur");
    query.bindValue(":numLecteur", numLecteur);
    if (!query.exec()) {
        qDebug() << "Lecteur check error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la vérification du lecteur");
        return;
    }

    if (!query.next() || query.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Error", "Numéro de lecteur inexistant ou indisponible");
        return;
    }

    // Suppression du lecteur
    query.prepare("DELETE FROM Lecteur WHERE numLecteur = :numLecteur");
    query.bindValue(":numLecteur", numLecteur);
    if (!query.exec()) {
        qDebug() << "Lecteur delete error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la suppression du lecteur");
        return;
    }

    QMessageBox::information(this, "Success", "Lecteur supprimé avec succès");

    database.close();
}
