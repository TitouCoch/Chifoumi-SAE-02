/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    Cocheril Titouan - Salle Ivan ()
 * Created:   2022-04-10
 * Description : classe métier (= modèle) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"
#include <cstdlib>
#include <ctime>


///* ---- PARTIE MODULE ---------------------------

Chifoumi::Chifoumi()
{
    initCoups();
    initScores();
}

Chifoumi::~Chifoumi()
{
    delete[]this;
}

/// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return this->coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return this->coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return this->scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return this->scoreMachine;
}
char Chifoumi::determinerGagnant(){
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

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur à retourner
    unsigned int nbAleatoire;
    nbAleatoire = randMinMax(1, 4);
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = Chifoumi::pierre;
        break;
    case 2 :
        valeurGeneree = Chifoumi::papier;
        break;
    case 3 :
        valeurGeneree = Chifoumi::ciseau;
        break;
    }
    return valeurGeneree;
}

// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    this->coupJoueur = p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    this->coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    this->scoreJoueur = p_score;
}


void Chifoumi::setScoreMachine(unsigned int p_score) {
    this->scoreMachine = p_score;
}


void Chifoumi::majScores(char p_gagnant) {
    if(p_gagnant=='J')
    {
        this->scoreJoueur +=1;
    }
    else if(p_gagnant=='M')
    {
        this->scoreMachine +=1;
    }
}

void Chifoumi::initScores() {
    setScoreJoueur(0);
    setScoreMachine(0);
}

void Chifoumi::initCoups() {
    setCoupJoueur(rien);
    setCoupMachine(rien);
}
