#ifndef AJOUTERUNLIVRE_H
#define AJOUTERUNLIVRE_H

#include <QDialog>

namespace Ui {
class ajouterUnLivre;
}

class ajouterUnLivre : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterUnLivre(QWidget *parent = nullptr);
    ~ajouterUnLivre();
    void setLivreInfo(const QString &numLivre, const QString &design, const QString &auteur, const QDate &dateEdition, const bool &disponible);

private slots:
    void on_ajouter_clicked();

private:
    Ui::ajouterUnLivre *ui;
};

#endif // AJOUTERUNLIVRE_H
