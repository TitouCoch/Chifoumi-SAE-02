#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include <QDebug>

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{

}
//Getter
ChifoumiModele *ChifoumiPresentation::getModele()
{
    return _leModele;
}

ChifoumiVue *ChifoumiPresentation::getVue()
{
    return _laVue;
}

ChifoumiPresentation::UnEtatJeu ChifoumiPresentation::getEtatJeu()
{
    return _etatJeu;
}

//Setter
void ChifoumiPresentation::setModele(ChifoumiModele *m)
{
    _leModele = m;
}

void ChifoumiPresentation::setVue(ChifoumiVue *v)
{
    _laVue = v;
}

void ChifoumiPresentation::setEtatJeu(UnEtatJeu e)
{
    this->_etatJeu = e;
}

void ChifoumiPresentation::choixPapier()
{
    UnEtatJeu e=getEtatJeu();
    switch(e){
    //Etat initial
    case etatInitial:{} //Cas impossible
    break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->setCoupJoueur(ChifoumiModele::papier);   //Place le coup du joueur sur papier
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jours les scores
    _laVue->afficherCoupJoueur(_leModele->getCoupJoueur()); //Affiche le coup du joueur
    _laVue->afficherCoupMachine(_leModele->getCoupMachine());   //Affiche le coup de la machine
    _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));  //Affiche le score du joueur
    _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));    //Affiche le score de la machine
    }
    }
}
void ChifoumiPresentation::choixPierre()
{
    UnEtatJeu e=getEtatJeu();
    switch(e){
    //Etat initial
    case etatInitial:{} //Cas impossible
    break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->setCoupJoueur(ChifoumiModele::pierre);   //Place le coup du joueur sur pierre
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jours les scores
    _laVue->afficherCoupJoueur(_leModele->getCoupJoueur()); //Affiche le coup du joueur
    _laVue->afficherCoupMachine(_leModele->getCoupMachine());   //Affiche le coup de la machine
    _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));  //Affiche le score du joueur
    _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));    //Affiche le score de la machine
    }
    }
}

void ChifoumiPresentation::choixCiseau()
{
    UnEtatJeu e=getEtatJeu();
    switch(e){
    //Etat initial
    case etatInitial:{} //Cas impossible
    break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->setCoupJoueur(ChifoumiModele::ciseau);   //Place le coup du joueur sur ciseau
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jours les scores
    _laVue->afficherCoupJoueur(_leModele->getCoupJoueur()); //Affiche le coup du joueur
    _laVue->afficherCoupMachine(_leModele->getCoupMachine());   //Affiche le coup de la machine
    _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));  //Affiche le score du joueur
    _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));    //Affiche le score de la machine
    }
    }
}

void ChifoumiPresentation::creerNvllePartie()
{
    UnEtatJeu e=getEtatJeu();
    switch(e){
    //Etat initial
    case etatInitial:{
    this->setEtatJeu(jeuEnCours); //Place l'état du jeu sur jeuEnCours
    _leModele->initCoups(); //Initialisation des variables de coups
    _leModele->initScores();    //Initialisation des variables de scores
    _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->initCoups(); //Initialisation des variables de coups
    _leModele->initScores();    //Initialisation des variables de scores
    _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }
}
