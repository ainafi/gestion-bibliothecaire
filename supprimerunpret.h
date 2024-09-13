#ifndef SUPPRIMERUNPRET_H
#define SUPPRIMERUNPRET_H

#include <QDialog>

namespace Ui {
class supprimerUnPret;
}

class supprimerUnPret : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerUnPret(QWidget *parent = nullptr);
    ~supprimerUnPret();

private:
    Ui::supprimerUnPret *ui;
};

#endif // SUPPRIMERUNPRET_H
