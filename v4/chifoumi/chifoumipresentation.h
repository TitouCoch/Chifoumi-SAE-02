#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include "chifoumimodele.h"

///* ---- PARTIE PRESENTATION ---------------------------

class ChifoumiVue;
class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    //Type enuméré correspondant à l'état du jeu
    enum UnEtatJeu{etatInitial, jeuEnCours, finPartie};
    //Constructeur
    explicit ChifoumiPresentation(ChifoumiModele *m,QObject *parent = nullptr);

    //Getter
    ChifoumiModele* getModele();
    /* retourne le pointeur du modèle */
    ChifoumiVue* getVue();
    /* retourne le pointeur de la vue */
    UnEtatJeu getEtatJeu();
    /* retourne l'état du jeu */

    //Setter
    void setModele(ChifoumiModele *m);
    /* initialise le pointeur du modèle avec la valeur
       du paramètre m */
    void setVue(ChifoumiVue *v);
    /* initialise le pointeur de la vue avec la valeur
       du paramètre v */
    void setEtatJeu(UnEtatJeu e);
    /* initialise l'état du jeu avec la valeur
       du paramètre e */

    //Méthodes
    QString getScoreMax();
    //Fonction qui renvoie le score le plus élevé entre les deux joueurs
    QString recupererNomGagnant();
    //Procédure qui convertie le char retourner par la méthode determineGagnant en QString
    bool maxScoreAtteind();
    //Fonction qui retourne vrai si le score maximal de la partie est atteind sinon retourne faux
    void okClicked();
    //Procédure qui initialise les coups et scores, place l'état du jeu sur l'état initial et met
    //à jour la vue lorsque l'utilisateur clique sur le bouton OK de la message box

public slots :
    //Méthodes SLOTS
    void choixPapier();
    //Procédure qui met en œuvre le diagramme états-transition lorsque le joueur choisit le papier
    void choixPierre();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi la pierre
    void choixCiseau();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi le ciseau
    void creerNvllePartie();
    //Procédure qui initialise les scores et les coups du joueur et de la machine, donne
    // accès aux boutons de figures

private :
    //Attribut de la présentation
    ChifoumiModele *_leModele;	// pteur vers le modèle
    ChifoumiVue *_laVue;		// pteur vers la vue
    UnEtatJeu _etatJeu;         // données membre de l'état du jeu

};

#endif // CHIFOUMIPRESENTATION_H