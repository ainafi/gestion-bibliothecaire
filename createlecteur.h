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

    void setLecteurInfo(const QString &numLecteur, const QString &nomLecteur);

private slots:
    void on_ajouter_clicked();

private:
    Ui::createLecteur *ui;

};

#endif // CREATELECTEUR_H
