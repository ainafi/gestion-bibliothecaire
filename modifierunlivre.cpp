#include "modifierunlivre.h"
#include "ui_modifierunlivre.h"
#include "ajouterunlivre.h" // Include the header file for ajouterUnLivre
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate> // Include this header

modifierUnLivre::modifierUnLivre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifierUnLivre)
    , ptrAjouterUnLivre(nullptr)
{
    ui->setupUi(this);
}

modifierUnLivre::~modifierUnLivre()
{
    delete ui;
    // Do not delete ptrAjouterUnLivre here, as it's managed by its own instance
}

void modifierUnLivre::on_recherche_clicked()
{
    QString numLivre = ui->numLivre->text(); // Adjust to correct field name
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

    if (!database.isOpen() && !database.open()) {
        qDebug() << "Error: connection with database failed - " << database.lastError().text();
        QMessageBox::critical(this, "Database Connection Error", database.lastError().text());
        return;
    } else {
        qDebug() << "Connection ok";
        QSqlQuery query;
        query.prepare("SELECT * FROM Livre WHERE numLivre = :numLivre");
        query.bindValue(":numLivre", numLivre);

        if (!query.exec() || !query.next()) {
            QMessageBox::warning(this, "Error", "Numero de livre inexistant");
            return;
        }

        QString design = query.value("design").toString();
        QString auteur = query.value("auteur").toString();
        QDate dateEdition = query.value("dateEdition").toDate();
        bool disponible = query.value("disponible").toBool();

        if (!ptrAjouterUnLivre) {
            ptrAjouterUnLivre = new ajouterUnLivre(this); // Set parent to manage memory
        }
        ptrAjouterUnLivre->setLivreInfo(numLivre, design, auteur, dateEdition, disponible);
        ptrAjouterUnLivre->show();
    }
}
