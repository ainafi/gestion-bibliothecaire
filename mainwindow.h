#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE
//lecteur
class createLecteur;
class modifierUnLecteur;
class supprimerLecteur;
class listLecteur;
//livre
class situationLivre;
class ajouterUnLivre;
class modifierUnLivre;
class supprimerUnLivre;

//prete
class listPret;
class prete;
class modifierUnPret;
class supprimerUnPret;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajoutLecteur_clicked();

    void on_ModifLecteur_clicked();

    void on_SupprLecteur_clicked();

    void on_AjoutLivre_clicked();

    void on_SupprLivre_2_clicked();

    void on_SupprLivre_clicked();

    void on_SaisieDesPretes_clicked();

    void on_ModifPret_clicked();

    void on_SupprPret_clicked();

    void on_pushButton_clicked();

    void on_ListPret_clicked();

    void on_situation_clicked();

private:
    Ui::MainWindow *ui;
    createLecteur *ptrCreateLecteur;
    modifierUnLecteur *ptrModifierLecteur;
    supprimerLecteur *ptrSupprimerLecteur;
    listLecteur *ptrListLecteur;

    situationLivre *ptrSituaionLivre;
    ajouterUnLivre *ptrAjouterUnLivre;
    modifierUnLivre *ptrModifierUnLivre;
    supprimerUnLivre *ptrSupprimerUnLivre;

    //prete
    prete *ptrPrete;
    modifierUnPret *ptrModifierUnPret;
    supprimerUnPret *ptrSupprimerUnPret;
    listPret *ptrListPret;
};
#endif // MAINWINDOW_H
