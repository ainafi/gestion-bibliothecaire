#include "prete.h"
#include "ui_prete.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

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

void prete::on_SaisirLePrete_clicked()
{
    QString numPret = ui->numeroDePret->text();
    QString numLecteur = ui->numeroLecteur->text();
    QString numLivre = ui->numeroLivre->text();
    QDate datePret = ui->datePret->date();
    QDate dateRetour = ui->dateRetour->date();

    qDebug() << "num pret:" << numPret
             << "numLecteur:" << numLecteur
             << "numLivre:" << numLivre
             << "datePret:" << datePret.toString("dd/MM/yyyy")
             << "dateRetour:" << dateRetour.toString("dd/MM/yyyy");

    // Vérifier si la connexion par défaut existe déjà
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
        return;
    }

    QSqlQuery query;

    // Vérification de l'existence et de la disponibilité du livre
    query.prepare("SELECT COUNT(*) FROM Livre WHERE numLivre = :numLivre AND disponible = '1'");
    query.bindValue(":numLivre", numLivre);
    if (!query.exec()) {
        qDebug() << "Livre check error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la vérification du livre");
        return;
    }
    if (!query.next() || query.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Error", "Numero de Livre inexistant ou indisponible");
        return;
    }

    // Vérification du nombre de prêts pour le même lecteur et la même date
    query.prepare("SELECT COUNT(*) FROM Pret WHERE numLecteur = :numLecteur AND datePret = :datePret");
    query.bindValue(":numLecteur", numLecteur);
    query.bindValue(":datePret", datePret);
    if (!query.exec()) {
        qDebug() << "Loan count check error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Erreur lors de la vérification des prêts");
        return;
    }
    if (query.next() && query.value(0).toInt() >= 3) {
        QMessageBox::warning(this, "Error", "Un lecteur ne peut pas prêter plus de 3 livres à la même date.");
        return;
    }

    // Insertion des données du prêt
    query.prepare("INSERT INTO Pret(numPret, numLecteur, numLivre, datePret, dateRetour) "
                  "VALUES (:numPret, :numLecteur, :numLivre, :datePret, :dateRetour)");
    query.bindValue(":numPret", numPret);
    query.bindValue(":numLecteur", numLecteur);
    query.bindValue(":numLivre", numLivre);
    query.bindValue(":datePret", datePret);
    query.bindValue(":dateRetour", dateRetour);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to insert loan data");
        return;
    }

    // Mise à jour de la disponibilité du livre
    query.prepare("UPDATE Livre SET disponible = '0', nbrPrete = COALESCE(nbrPrete, 0) + 1 WHERE numLivre = :numLivre");
    query.bindValue(":numLivre", numLivre);
    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to update book availability");
        return;
    }

    QMessageBox::information(this, "Success", "Loan recorded and book availability updated");
}
