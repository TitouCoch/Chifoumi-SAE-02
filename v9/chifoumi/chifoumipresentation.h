#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include "chifoumimodele.h"
#include <QTimer>
#include <QMainWindow>
#include "dialog.h"
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QVariant>
#include <QSqlQuery>

///* ---- PARTIE PRESENTATION ---------------------------
class connexion;
class resultat;
class ChifoumiVue;
class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    //Type enuméré correspondant à l'état du jeu
    enum UnEtatJeu{etatConnexion, etatParametrage, etatInitial, jeuEnCours,etatPause, finPartie,etatArretProgramme, etatResultat};
    //Constructeur
    explicit ChifoumiPresentation(ChifoumiModele *m,QObject *parent = nullptr);
    //Getter
    ChifoumiModele* getModele();
    /* retourne le pointeur du modèle */
    ChifoumiVue* getVue();
    /* retourne le pointeur de la vue */
    UnEtatJeu getEtatJeu();
    /* retourne l'état du jeu */
    connexion* getConnexion();

    QTimer *monTimer = new QTimer;
    //Création d'une instance de timer

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

    void setConnexion(connexion *c);
    /* initialise le pointeur de la vue avec la valeur
       du paramètre v */

    //Méthodes
    QString recupererMessage();
    //Procédure qui convertie le char retourner par la méthode determineGagnant en QString
    bool maxScoreAtteind();
    //Fonction qui retourne vrai si le score maximal de la partie est atteind sinon retourne faux
    void okClicked();
    //Procédure qui initialise les coups et scores, place l'état du jeu sur l'état initial et met
    //à jour la vue lorsque l'utilisateur clique sur le bouton OK de la message box
    void connexionOk();
    //Procédure place l'état sur état initial ce qui lance le jeu chifoumi
    bool opendatabase();
    //Procédure qui ouvre la base de données associée au jeu
    void closedatabase();
    //procédure qui ferme la base de données associée au jeu

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
    void decrementerTimer();
    //Procédure qui décremente le temps de jeu sur l'interface en fonction du temps de jeu du modèle
    //Si le temps arrive à zéro l'état du jeu est changé et l'interface est mise à jour
    void demandePause();
    //Procédure qui arrête ou relance la partie. Change l'état du jeu et met à jour l'interface
    void demandeParametrage();
    //Procédure qui récupères les informations saisient dans la fenêtre de dialog et met à jour le modèle et la vue en fonction
    void Sortir();
    //procédure qui passe l'état de jeu sur l'état d'arrêt du programme
    bool testConnexion();
    //Fonction booléenne qui vérifie la connexion entre la saisi de l'utilisateur et la base de donnée
    void demandeResultat();
    //Procédure qui affiche une tableWidget contenant les 10 meilleurs parties du joueur

private :
    //Attribut de la présentation
    ChifoumiModele *_leModele;	// pteur vers le modèle
    ChifoumiVue *_laVue;		// pteur vers la vue
    UnEtatJeu _etatJeu;         // données membre de l'état du jeu
    connexion *db;              //pteur vers la fenêtre connexion
    QSqlDatabase mydb;          //donnée membre pour accéder à la base de données
    resultat *result;           //pteur vers la fenêtre de résultat
};

#endif // CHIFOUMIPRESENTATION_H


