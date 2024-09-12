#ifndef MODIFIERUNLECTEUR_H
#define MODIFIERUNLECTEUR_H

#include <QDialog>

namespace Ui {
class modifierUnLecteur;
}

class modifierUnLecteur : public QDialog
{
    Q_OBJECT

public:
    explicit modifierUnLecteur(QWidget *parent = nullptr);
    ~modifierUnLecteur();

private:
    Ui::modifierUnLecteur *ui;
};

#endif // MODIFIERUNLECTEUR_H
