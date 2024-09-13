#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "createlecteur.h"
#include "modifierunlecteur.h"
#include "supprimerlecteur.h"
#include "ajouterunlivre.h"
#include "modifierunlivre.h"
#include "supprimerunlivre.h"
#include "prete.h"
#include "modifierunpret.h"
#include "supprimerunpret.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //lecteur
    , ptrCreateLecteur(nullptr)
    , ptrModifierLecteur(nullptr)
    , ptrSupprimerLecteur(nullptr)
    //livre
    , ptrAjouterUnLivre(nullptr)
    , ptrModifierUnLivre(nullptr)
    , ptrSupprimerUnLivre(nullptr)
    //prete
    , ptrPrete(nullptr)
    , ptrModifierUnPret(nullptr)
    ,ptrSupprimerUnPret(nullptr)
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
    delete ptrModifierUnLivre;
    delete ptrSupprimerUnLivre;

    //prete
    delete ptrPrete;
    delete ptrModifierUnPret;
    delete ptrSupprimerUnPret;
}

//lecteur
void MainWindow::on_ajoutLecteur_clicked()
{
    if(!ptrCreateLecteur){
        ptrCreateLecteur = new createLecteur();
    }
    ptrCreateLecteur->show();
}

void MainWindow::on_ModifLecteur_clicked()
{
    if(!ptrModifierLecteur){
        ptrModifierLecteur = new modifierUnLecteur();
    }
    ptrModifierLecteur->show();
}

void MainWindow::on_SupprLecteur_clicked()
{
    if(!ptrSupprimerLecteur){
        ptrSupprimerLecteur = new supprimerLecteur();
    }
    ptrSupprimerLecteur->show();
}

//livre
void MainWindow::on_AjoutLivre_clicked()
{
    if(!ptrAjouterUnLivre){
        ptrAjouterUnLivre = new ajouterUnLivre();
    }
    ptrAjouterUnLivre->show();
}

void MainWindow::on_SupprLivre_2_clicked()
{
    if(!ptrModifierUnLivre){
        ptrModifierUnLivre = new modifierUnLivre();
    }
    ptrModifierUnLivre->show();
}

void MainWindow::on_SupprLivre_clicked()
{
    if(!ptrSupprimerUnLivre){
        ptrSupprimerUnLivre = new supprimerUnLivre();
    }
    ptrSupprimerUnLivre->show();
}

void MainWindow::on_SaisieDesPretes_clicked()
{
    if(!ptrPrete){
        ptrPrete = new prete();
    }
    ptrPrete->show();
}

void MainWindow::on_ModifPret_clicked()
{
    if(!ptrModifierUnPret){
        ptrModifierUnPret=new modifierUnPret();
    }
    ptrModifierUnPret->show();
}


void MainWindow::on_SupprPret_clicked()
{
    if(!ptrSupprimerUnPret){
        ptrSupprimerUnPret=new supprimerUnPret();
    }
    ptrSupprimerUnPret->show();
}

