#ifndef LISTPRET_H
#define LISTPRET_H

#include <QDialog>

namespace Ui {
class listPret;
}

class listPret : public QDialog
{
    Q_OBJECT

public:
    explicit listPret(QWidget *parent = nullptr);
    ~listPret();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listPret *ui;
};

#endif // LISTPRET_H
