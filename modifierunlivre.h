#ifndef MODIFIERUNLIVRE_H
#define MODIFIERUNLIVRE_H

#include <QDialog>

namespace Ui {
class modifierUnLivre;
}

class modifierUnLivre : public QDialog
{
    Q_OBJECT

public:
    explicit modifierUnLivre(QWidget *parent = nullptr);
    ~modifierUnLivre();

private:
    Ui::modifierUnLivre *ui;
};

#endif // MODIFIERUNLIVRE_H
