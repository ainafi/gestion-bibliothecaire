#ifndef SITUATIONLIVRE_H
#define SITUATIONLIVRE_H

#include <QDialog>

namespace Ui {
class situationLivre;
}

class situationLivre : public QDialog
{
    Q_OBJECT

public:
    explicit situationLivre(QWidget *parent = nullptr);
    ~situationLivre();

private slots:
    void on_pushButton_clicked();

private:
    Ui::situationLivre *ui;
};

#endif // SITUATIONLIVRE_H
