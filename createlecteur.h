#ifndef CREATELECTEUR_H
#define CREATELECTEUR_H

#include <QDialog>

namespace Ui {
class createLecteur;
}

class createLecteur : public QDialog
{
    Q_OBJECT

public:
    explicit createLecteur(QWidget *parent = nullptr);
    ~createLecteur();

private:
    Ui::createLecteur *ui;
};

#endif // CREATELECTEUR_H
