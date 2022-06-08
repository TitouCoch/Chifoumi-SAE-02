#ifndef RESULTAT_H
#define RESULTAT_H

#include <QDialog>
#include <QSqlQuery>
#include "chifoumipresentation.h"

namespace Ui {
class resultat;
}

class ChifoumiPresentation;
class resultat : public QDialog
{
    Q_OBJECT

public:
    explicit resultat(QWidget *parent = nullptr);
    ~resultat();
    void majTableauResultat();
private:
    Ui::resultat *ui;
};

#endif // RESULTAT_H
