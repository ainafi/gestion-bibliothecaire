#ifndef SUPPRIMERUNLIVRE_H
#define SUPPRIMERUNLIVRE_H

#include <QDialog>

namespace Ui {
class supprimerUnLivre;
}

class supprimerUnLivre : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerUnLivre(QWidget *parent = nullptr);
    ~supprimerUnLivre();

private:
    Ui::supprimerUnLivre *ui;
};

#endif // SUPPRIMERUNLIVRE_H
