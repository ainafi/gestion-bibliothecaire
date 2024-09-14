#include "createlecteur.h"
#include "ui_createlecteur.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

createLecteur::createLecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createLecteur)
{
    ui->setupUi(this);
}

createLecteur::~createLecteur()
{
    delete ui;
}

void createLecteur::setLecteurInfo(const QString &numLecteur, const QString &nomLecteur)
{
    ui->numLecteur->setText(numLecteur);
    ui->nomLecteur->setText(nomLecteur);
}

void createLecteur::on_ajouter_clicked()
{
    QString numLecteur = ui->numLecteur->text();
    QString nomLecteur = ui->nomLecteur->text();
    qDebug() << "num du lecteur:" << numLecteur << "nom du lecteur:" << nomLecteur;

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setDatabaseName("GestionBibliotecaire");
    database.setUserName("gestionuser");
    database.setPassword("password");

    if (!database.open()) {
        qDebug() << "Error: connection with database failed - " << database.lastError().text();
        QMessageBox::critical(this, "Database Connection Error", database.lastError().text());
    } else {
        qDebug() << "Connection ok";

        QSqlQuery query;
        query.prepare("INSERT INTO Lecteur (numLecteur, nom) VALUES (:numLecteur, :nom) "
                      "ON DUPLICATE KEY UPDATE nom=:nom");
        query.bindValue(":numLecteur", numLecteur);
        query.bindValue(":nom", nomLecteur);

        qDebug() << "Bound values:" << query.boundValue(":numLecteur").toString() << query.boundValue(":nom").toString();

        if (!query.exec()) {
            qDebug() << "Error: failed to insert or update data - " << query.lastError().text();
            QMessageBox::critical(this, "Database Insert/Update Error", query.lastError().text());
        } else {
            qDebug() << "Data inserted or updated successfully!";
            QMessageBox::information(this, "Success", "Lecteur information saved successfully!");
        }

        // Close the database connection
        database.close();
    }
}
