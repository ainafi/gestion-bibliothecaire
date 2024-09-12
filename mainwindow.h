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

private:
    Ui::MainWindow *ui;
    createLecteur *ptrCreateLecteur;
    modifierUnLecteur *ptrModifierLecteur;
    supprimerLecteur *ptrSupprimerLecteur;

    //livre
    ajouterUnLivre *ptrAjouterUnLivre;
};
#endif // MAINWINDOW_H
