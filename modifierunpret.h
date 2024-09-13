#ifndef MODIFIERUNPRET_H
#define MODIFIERUNPRET_H

#include <QDialog>

namespace Ui {
class modifierUnPret;
}

class modifierUnPret : public QDialog
{
    Q_OBJECT

public:
    explicit modifierUnPret(QWidget *parent = nullptr);
    ~modifierUnPret();

private:
    Ui::modifierUnPret *ui;
};

#endif // MODIFIERUNPRET_H
