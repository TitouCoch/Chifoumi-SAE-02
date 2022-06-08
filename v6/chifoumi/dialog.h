#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    unsigned int getScoreChoisi();
    //Retourne le score choisi par le joueur
    unsigned int getTempsChoisi();
    //Retourne le temp choisi par le joueur
    QString getNomChoisi();
    //Retourne le nom choisi par l'utilisateur
public slots:
    void changeZoneTexte(int);
    //Change le texte du label lSecondeDialog en fonction de la position du slider


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
