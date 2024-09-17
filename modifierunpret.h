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

    void setPretInfo(const QString &numPret, const QString &numLecteur, const QString &numLivre, const QDate &datePret, const QDate &dateRetour);

private slots:
    void on_Recherche_clicked();
    void on_Modifier_clicked(); // Slot for the update button

private:
    Ui::modifierUnPret *ui;
};

#endif // MODIFIERUNPRET_H
