#include "chifoumimodele.h"

///* ---- PARTIE MODULE ---------------------------


ChifoumiModele::ChifoumiModele()
{
    initCoups();
    initScores();
}



/// Getters

ChifoumiModele::UnCoup ChifoumiModele::getCoupJoueur() {
    return this->coupJoueur;
}

ChifoumiModele::UnCoup ChifoumiModele::getCoupMachine() {
    return this->coupMachine;
}

unsigned int ChifoumiModele::getScoreJoueur() {
    return this->scoreJoueur;
}

unsigned int ChifoumiModele::getScoreMachine() {
    return this->scoreMachine;
}
char ChifoumiModele::determinerGagnant(){
    char gagnantARetourner;
    // avant de commencer : match nul
    gagnantARetourner = 'N';
    //Joueur choisi pierre
    if (getCoupJoueur() == pierre) {
        //Machine choisi pierre
        if (getCoupMachine() == pierre) {
            //Egalité
            gagnantARetourner = 'N';
        }
        //Machine choisi papier
        else if (getCoupMachine() == papier) {
            //Machine gagne
            gagnantARetourner = 'M';
        }
        //Machine choisi ciseau
        else if (getCoupMachine() == ciseau) {
            // Joueur gagne
            gagnantARetourner = 'J';
        }
    }
    // Joueur choisi papier
    else if (getCoupJoueur() == papier) {
        // Machine choisi pierre
        if (getCoupMachine() == pierre) {
            //Joueur gagne
            gagnantARetourner = 'J';
        }
        //Machine choisi papier
        else if (getCoupMachine() == papier) {
            //Egalite
            gagnantARetourner = 'N';
        }
        //Machine choisi ciseau
        else if (getCoupMachine() == ciseau) {
            //Machine gagne
            gagnantARetourner = 'M';
        }
    }
    //Joueur choisi ciseau
    else if (getCoupJoueur() == ciseau) {
        //Machine choisi pierre
        if (getCoupMachine() == pierre) {
            //Machine gagne
            gagnantARetourner = 'M';
        }
        //Machine choisi papier
        else if (getCoupMachine() == papier) {
            //Joueur gagne
            gagnantARetourner = 'J';
        }
        //Machine choisi ciseau
        else if (getCoupMachine() == ciseau) {
            //Egalite
            gagnantARetourner = 'N';
        }
    }

    return gagnantARetourner;
}

///* Méthodes utilitaires du Module

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
    return rand()%(max-min) + min;
}

ChifoumiModele::UnCoup ChifoumiModele::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur à retourner
    unsigned int nbAleatoire;
    nbAleatoire = randMinMax(1, 4);
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = ChifoumiModele::pierre;
        break;
    case 2 :
        valeurGeneree = ChifoumiModele::papier;
        break;
    case 3 :
        valeurGeneree = ChifoumiModele::ciseau;
        break;
    }
    return valeurGeneree;
}

// Setters

void ChifoumiModele::setCoupJoueur(UnCoup p_coup) {
    this->coupJoueur = p_coup;
}

void ChifoumiModele::setCoupMachine(UnCoup p_coup) {
    this->coupMachine = p_coup;
}

void ChifoumiModele::setScoreJoueur(unsigned int p_score) {
    this->scoreJoueur = p_score;
}


void ChifoumiModele::setScoreMachine(unsigned int p_score) {
    this->scoreMachine = p_score;
}


void ChifoumiModele::majScores(char p_gagnant) {
    if(p_gagnant=='J')
    {
        this->scoreJoueur +=1;
    }
    else if(p_gagnant=='M')
    {
        this->scoreMachine +=1;
    }
}

void ChifoumiModele::initScores() {
    setScoreJoueur(0);
    setScoreMachine(0);
}

void ChifoumiModele::initCoups() {
    setCoupJoueur(rien);
    setCoupMachine(rien);
}
