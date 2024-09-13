#ifndef SAISIEDESPRETES_H
#define SAISIEDESPRETES_H

#include <QDialog>

namespace Ui {
class saisieDesPretes;
}

class saisieDesPretes : public QDialog
{
    Q_OBJECT

public:
    explicit saisieDesPretes(QWidget *parent = nullptr);
    ~saisieDesPretes();

private:
    Ui::saisieDesPretes *ui;
};

#endif // SAISIEDESPRETES_H
