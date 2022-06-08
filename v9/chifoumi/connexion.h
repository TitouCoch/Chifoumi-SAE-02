#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include <QtWidgets>
#include "chifoumipresentation.h"

#define DATABASE_NAME "chifoumiConnexion"
#define CONNECT_TYPE "QODBC"


class ChifoumiPresentation;
namespace Ui {class connexion;}


class connexion : public QDialog
{
    Q_OBJECT

public:
    //Constructeur
    explicit connexion(ChifoumiPresentation *p,QWidget *parent = nullptr);
    //Desctructeur
    ~connexion();

    void setPresentation(ChifoumiPresentation *p);
    /* initialise le pointeur de la présentation avec la valeur
       du paramètre p */


    ChifoumiPresentation* getPresentation();
    //retourne le pointeur de la présentation

    QString getUtilisteur();
    //retourne la saisi du nom de l'utilisateur
    QString getPassword();
    //retourne la saisi du mot de passe de l'utilisateur
    void messageErreur(QString);
    //Affiche le message d'erreur dans une message box
    void clearSaisi();
    //Vide les cases de saisies

private:
    Ui::connexion *ui;
    ChifoumiPresentation* _laPresentation; //poiteur vers la présentation
};

#endif // CONNEXION_H
