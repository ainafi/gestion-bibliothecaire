#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "createlecteur.h"
#include "modifierunlecteur.h"
#include "supprimerlecteur.h"
#include "ajouterunlivre.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
//lecteur
    ptrCreateLecteur(nullptr),
    ptrModifierLecteur(nullptr),
    ptrSupprimerLecteur(nullptr),

//livre
    ptrAjouterUnLivre(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrCreateLecteur;
    delete ptrModifierLecteur;
    delete ptrSupprimerLecteur;

    //livre
    delete ptrAjouterUnLivre;
}

//lecteur
void MainWindow::on_ajoutLecteur_clicked()
{
    if(!ptrCreateLecteur){
        ptrCreateLecteur=new createLecteur();
    }
    ptrCreateLecteur->show();
}


void MainWindow::on_ModifLecteur_clicked()
{
    if(!ptrModifierLecteur){
        ptrModifierLecteur=new modifierUnLecteur();
    }
    ptrModifierLecteur->show();
}


void MainWindow::on_SupprLecteur_clicked()
{
    if(!ptrSupprimerLecteur){
        ptrSupprimerLecteur=new supprimerLecteur();
    }
    ptrSupprimerLecteur->show();
}

//livre



void MainWindow::on_AjoutLivre_clicked()
{
    if(!ptrAjouterUnLivre){
        ptrAjouterUnLivre=new ajouterUnLivre();
    }
    ptrAjouterUnLivre->show();
}

