#ifndef CHIFOUMIMODELE_H
#define CHIFOUMIMODELE_H

#include <QObject>

///* ---- PARTIE MODELE ---------------------------

class ChifoumiModele : public QObject
{
    Q_OBJECT
public:
    enum UnCoup {pierre, papier, ciseau, rien };
    // Méthodes du Modéle
    ChifoumiModele();
    // Getters
    QString getNomJoueur();
    //Retourne le nom du joueur
    unsigned int getTemps();
    //Retourne le temps de la partie
    unsigned int getScoreMax();
    //Retourne le score maximal de la partie
    UnCoup getCoupJoueur();
        /* retourne le dernier coup joué par le joueur */
    UnCoup getCoupMachine();
        /* retourne le dernier coup joué par le joueur */
    unsigned int getScoreJoueur();
        /* retourne le score du joueur */
    unsigned int getScoreMachine();
        /* retourne le score de la machine */
    char determinerGagnant();
        /* détermine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
           en fonction du dernier coup joué par chacun d'eux */
    UnCoup genererUnCoup();
    /* retourne une valeur aléatoire = pierre, papier ou ciseau.
   Utilisée pour faire jouer la machine */

    // Setters
public slots:
    void  setTempsMax(unsigned int);
    //initialise le temp maximal du jeu
    void setNomJoueur(QString);
    //initialise le nom du joueur
    void setTemps(unsigned int);
    //Initialise le temps de jeu courant de la partie
    void setScoreMax(unsigned int);
    //Initialise le score maximal de la partie
    void setCoupJoueur(UnCoup p_coup);
        /* initialise l'attribut coupJoueur avec la valeur
           du paramètre p_coup */
    void setCoupMachine(UnCoup p_coup);
         /* initialise l'attribut coupmachine avec la valeur
           du paramètre p_coup */
    void setScoreJoueur(unsigned int p_score);
        /* initialise l'attribut scoreJoueur avec la valeur
           du paramètre p_score */
    void setScoreMachine(unsigned int p_score);
         /* initialise l'attribut coupMachine avec la valeur
           du paramètre p_score */

    // Autres modificateurs
     void majScores(char p_gagnant);
        /* Mise à jour des scores en fonction des règles de gestion actuelles :
            - 1 point pour le gagnant lorsqu'il y a un gagnant
            - 0 point en cas de match nul
        */
    void initScores();
        /* initialise à 0 les attributs scoreJoueur et scoreMachine
           NON indispensable */
    void initCoups();
        /* initialise à rien les attributs coupJoueur et coupMachine
           NON indispensable */
    void initTemps();
        /* initialise le temps de jeu avec la paramétre tempsMax */


 private:
    // Attributs du Modèle
    QString nomJoueur="Vous";   //Nom du joueur initialisé à vous
    unsigned int temps; //temps de jeu courant de la partie
    unsigned int tempsMax=30;   //temps de jeu maximale de la partie initialisé à 30
    unsigned int scoreMax=5;  //score maximal de la partie initilisé à 5
    unsigned int scoreJoueur;   // score actuel du joueur
    unsigned int scoreMachine;  // score actuel de la Machine
    UnCoup coupJoueur;          // dernier coup joué par le joueur
    UnCoup coupMachine;         // dernier coup joué par la machine
};

#endif // CHIFOUMIMODELE_H
