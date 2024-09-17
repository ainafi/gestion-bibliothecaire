#include "modifierunpret.h"
#include "ui_modifierunpret.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>

modifierUnPret::modifierUnPret(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifierUnPret)
{
    ui->setupUi(this);
}

modifierUnPret::~modifierUnPret()
{
    delete ui;
}

void modifierUnPret::setPretInfo(const QString &numPret, const QString &numLecteur, const QString &numLivre, const QDate &datePret, const QDate &dateRetour)
{
    ui->numeroDuPrete->setText(numPret);
    ui->numeroLecteur->setText(numLecteur);
    ui->numeroLivre->setText(numLivre);
    ui->datePret->setDate(datePret);
    ui->dateRetour->setDate(dateRetour);
}

void modifierUnPret::on_Recherche_clicked()
{
    QString numPret = ui->numeroDuPrete->text();

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
    query.prepare("SELECT numLecteur, numLivre, datePret, dateRetour FROM Pret WHERE numPret = :numPret");
    query.bindValue(":numPret", numPret);
    if (!query.exec()) {
        qDebug() << "Select error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to retrieve loan data");
        return;
    }

    if (query.next()) {
        QString numLecteur = query.value("numLecteur").toString();
        QString numLivre = query.value("numLivre").toString();
        QDate datePret = query.value("datePret").toDate();
        QDate dateRetour = query.value("dateRetour").toDate();

        setPretInfo(numPret, numLecteur, numLivre, datePret, dateRetour);
    } else {
        QMessageBox::warning(this, "Error", "Loan number not found");
    }
}

void modifierUnPret::on_Modifier_clicked()
{
    QString numPret = ui->numeroDuPrete->text();
    QString numLecteur = ui->numeroLecteur->text();
    QString numLivre = ui->numeroLivre->text();
    QDate datePret = ui->datePret->date();
    QDate dateRetour = ui->dateRetour->date();

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
    query.prepare("UPDATE Pret SET numLecteur = :numLecteur, numLivre = :numLivre, datePret = :datePret, dateRetour = :dateRetour WHERE numPret = :numPret");
    query.bindValue(":numPret", numPret);
    query.bindValue(":numLecteur", numLecteur);
    query.bindValue(":numLivre", numLivre);
    query.bindValue(":datePret", datePret);
    query.bindValue(":dateRetour", dateRetour);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to update loan data");
        return;
    }

    QMessageBox::information(this, "Success", "Loan data updated successfully");
}
