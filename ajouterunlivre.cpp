#include "ajouterunlivre.h"
#include "ui_ajouterunlivre.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
ajouterUnLivre::ajouterUnLivre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ajouterUnLivre)
{
    ui->setupUi(this);
}

ajouterUnLivre::~ajouterUnLivre()
{
    delete ui;
}

void ajouterUnLivre::on_ajouter_clicked()
{
    QString numLivre = ui->numeroLivre->text();
    QString design = ui->design->text();
    QString auteur = ui->auteur->text();
    QDate dateEdition = ui->dateEdit->date();
    bool disponible = ui->oui->isChecked();
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setDatabaseName("GestionBibliotecaire");
    database.setUserName("gestionuser");
    database.setPassword("password");


    qDebug() << "Numero du Livre:" << numLivre
             << "Design:" << design
             << "Auteur:" << auteur
             << "Date Edition:" << dateEdition.toString("dd/MM/yyyy")
             << "Disponible:" << (disponible ? "Oui" : "Non");

    if (!database.open()) {
        qDebug() << "Error: connection with database failed - " << database.lastError().text();
        QMessageBox::critical(this, "Database Connection Error", database.lastError().text());
    }else{
        qDebug() << "Connection ok";
         QSqlQuery query;
        query.prepare("INSERT INTO Livre(numLivre,design,auteur,dateEdition,disponible)VALUES(:numLivre,:design,:auteur,:dateEdition,:disponible)");
        query.bindValue(":numLivre",numLivre);
        query.bindValue(":design",design);
        query.bindValue(":auteur",auteur);
        query.bindValue(":dateEdition",dateEdition);
        query.bindValue(":disponible",disponible);
        if (!query.exec()) {
            qDebug() << "Error: failed to insert data - " << query.lastError().text();
            QMessageBox::critical(this, "Error", "failed to insert data");
        } else {
            qDebug() << "Data inserted successfully!";
            QMessageBox::information(this, "Success", "ajout nouveau livre succes");
        }
    }
}

