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
    //Constructeur
    explicit Dialog(QWidget *parent = nullptr);
    //Destructeur
    ~Dialog();

    unsigned int getScoreChoisi();
    //retourne le score choisi par l'utilisateur
    unsigned int getTempsChoisi();
    //retourne le temps choisi par l'utilisateur
    QString getNomChoisi();
    //retourne le nom choisi par l'utilisateur
public slots:
    void changeZoneTexte(int);
    //Change le texte du label en fonction de la position du slider


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
