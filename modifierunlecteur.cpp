#include "modifierunlecteur.h"
#include "ui_modifierunlecteur.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

modifierUnLecteur::modifierUnLecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifierUnLecteur)
    , ptrCreateLecteur(nullptr) // Initialize the pointer to nullptr
{
    ui->setupUi(this);
}

modifierUnLecteur::~modifierUnLecteur()
{
    delete ui;
    delete ptrCreateLecteur; // Ensure the pointer is deleted to avoid memory leaks
}

void modifierUnLecteur::on_SaveModif_clicked()
{
    QString numLecteur = ui->NumeroLecteur->text();
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
    } else {
        qDebug() << "Connection ok";
        QSqlQuery query;
        query.prepare("SELECT * FROM Lecteur WHERE numLecteur=:numLecteur");
        query.bindValue(":numLecteur", numLecteur);
        if (!query.exec() || !query.next()) {
            QMessageBox::warning(this, "Error", "Numero de Lecteur inexistant");
            return;
        }

        QString nomLecteur = query.value("nom").toString();
        if (!ptrCreateLecteur) {
            ptrCreateLecteur = new createLecteur();
        }

        ptrCreateLecteur->setLecteurInfo(numLecteur, nomLecteur);
        ptrCreateLecteur->show();
    }
}
