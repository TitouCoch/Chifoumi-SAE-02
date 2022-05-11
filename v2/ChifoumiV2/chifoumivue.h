#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "chifoumimodele.h"
#include "chifoumipresentation.h"

///* ---- PARTIE VUE ---------------------------

class ChifoumiPresentation;
QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE


class ChifoumiVue : public QMainWindow
{
    Q_OBJECT
public :
    //Constructeur
    explicit ChifoumiVue(ChifoumiPresentation *p, QWidget *parent = nullptr);
    ~ChifoumiVue();

    // getter et setter de la propriété pointant sur la Présentation
    ChifoumiPresentation* getPresentation();
    void setPresentation(ChifoumiPresentation *p);

/* Ici, toutes les méthodes qui correspondent à des ORDRES donnés par la présentation à
   l’interface
*/
    void miseAJour(ChifoumiPresentation::UnEtatJeu etat);
    // Met à jour les éléments d’interface AUTRES QUE les scores et derniers coups
    // joués,
    // en fonction de l’état du jeu.

    // ordres de mise à jour des scores et derniers coups joués
    void afficherScoreJoueur(QString scoreJ) ;
     // affiche la valeur du paramètre scoreJ dans la zone d’affichage du joueur
    void afficherScoreMachine(QString scoreM) ;
     // affiche la valeur du paramètre scoreM dans la zone d’affichage de la machine
    void afficherCoupJoueur(ChifoumiModele::UnCoup coupJ) ;
     // affiche la valeur du paramètre coupJ dans la zone d’affichage du joueur
    void afficherCoupMachine(ChifoumiModele::UnCoup coupM) ;
     // affiche la valeur du paramètre coupM dans la zone d’affichage de la machine

private:
    //Attribut de la vue
    Ui::ChifoumiVue *ui;
    ChifoumiPresentation* _laPresentation; //poiteur vers la présentation
};
#endif // CHIFOUMIVUE_H
