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

//livre

class ajouterUnLivre;
class modifierUnLivre;
class supprimerUnLivre;

//prete
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

private:
    Ui::MainWindow *ui;
    createLecteur *ptrCreateLecteur;
    modifierUnLecteur *ptrModifierLecteur;
    supprimerLecteur *ptrSupprimerLecteur;

    ajouterUnLivre *ptrAjouterUnLivre;
    modifierUnLivre *ptrModifierUnLivre;
    supprimerUnLivre *ptrSupprimerUnLivre;

    //prete
    prete *ptrPrete;
    modifierUnPret *ptrModifierUnPret;
    supprimerUnPret *ptrSupprimerUnPret;
};
#endif // MAINWINDOW_H
