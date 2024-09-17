#ifndef MODIFIERUNLIVRE_H
#define MODIFIERUNLIVRE_H

#include <QDialog>
#include "ajouterunlivre.h" // Include this header

namespace Ui {
class modifierUnLivre;
}

class modifierUnLivre : public QDialog
{
    Q_OBJECT

public:
    explicit modifierUnLivre(QWidget *parent = nullptr);
    ~modifierUnLivre();

private slots:
    void on_recherche_clicked();

private:
    Ui::modifierUnLivre *ui;
    ajouterUnLivre *ptrAjouterUnLivre; // Use correct class name
};

#endif // MODIFIERUNLIVRE_H
