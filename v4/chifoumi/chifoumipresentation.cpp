#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include <QDebug>

///* ---- PARTIE PRESENTATION ---------------------------

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{
    //Initialise l'état du jeu sur l'état initial
    this->setEtatJeu(UnEtatJeu::etatInitial);
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

//Slots
void ChifoumiPresentation::choixPapier()
{
    UnEtatJeu g = getEtatJeu();
    switch(g){
    //Etat initial
    case etatInitial:{} //Cas impossible
    break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->setCoupJoueur(ChifoumiModele::papier);   //Place le coup du joueur sur ciseau
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jours les scores
    _laVue->afficherCoupJoueur(_leModele->getCoupJoueur()); //Affiche le coup du joueur
    _laVue->afficherCoupMachine(_leModele->getCoupMachine());   //Affiche le coup de la machine
    _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));  //Affiche le score du joueur
    _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));    //Affiche le score de la machine
    if(maxScoreAtteind())   //Vérifie si un des joueurs à le score maximal
    {
        setEtatJeu(finPartie);  //Place l'état du jeu sur finPartie
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }break;
    case finPartie:{} //Cas impossible
    break;
    default :
            break;
    }

}
void ChifoumiPresentation::choixPierre()
{
    UnEtatJeu g = getEtatJeu();
    switch(g){
    //Etat initial
    case etatInitial:{} //Cas impossible
    break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->setCoupJoueur(ChifoumiModele::pierre);   //Place le coup du joueur sur ciseau
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jours les scores
    _laVue->afficherCoupJoueur(_leModele->getCoupJoueur()); //Affiche le coup du joueur
    _laVue->afficherCoupMachine(_leModele->getCoupMachine());   //Affiche le coup de la machine
    _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));  //Affiche le score du joueur
    _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));    //Affiche le score de la machine
    if(maxScoreAtteind())   //Vérifie si un des joueurs à le score maximal
    {
        setEtatJeu(finPartie);  //Place l'état du jeu sur finPartie
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }break;
    case finPartie:{} //Cas impossible
    break;
    default :
            break;
    }
}

void ChifoumiPresentation::choixCiseau()
{
    UnEtatJeu g = getEtatJeu();
    switch(g){
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
    if(maxScoreAtteind())   //Vérifie si un des joueurs à le score maximal
    {
        setEtatJeu(finPartie);  //Place l'état du jeu sur finPartie
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }break;
    case finPartie:{} //Cas impossible
    break;
    default :
            break;
}
}

void ChifoumiPresentation::creerNvllePartie()
{
    UnEtatJeu g = getEtatJeu();
    switch(g){
    //Etat Initial
    case etatInitial:{
    this->setEtatJeu(jeuEnCours); //Place l'état du jeu sur jeuEnCours
    _leModele->initCoups(); //Initialisation des variables de coups
    _leModele->initScores();    //Initialisation des variables de scores
    _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }break;
    //Etat jeu en cours
    case jeuEnCours:
    {
    _leModele->initCoups(); //Initialisation des variables de coups
    _leModele->initScores();    //Initialisation des variables de scores
    _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    _laVue->afficherCoupJoueur(_leModele->getCoupJoueur()); //Affiche le coup du joueur
    _laVue->afficherCoupMachine(_leModele->getCoupMachine());   //Affiche le coup de la machine
    _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));  //Affiche le score du joueur
    _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));    //Affiche le score de la machine
    }break;
    //Etat fin partie
    case finPartie:{}//Cas impossible
        break;
    default :
            break;
    }
}


bool ChifoumiPresentation::maxScoreAtteind()
{
    //Si le score maximal (5) est atteind retourne vrai sinon retourne faux
    if(_leModele->getScoreMachine()==_leModele->getScoreMax() || _leModele->getScoreJoueur()==_leModele->getScoreMax())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ChifoumiPresentation::okClicked()
{
     UnEtatJeu g = ChifoumiPresentation::getEtatJeu();
     switch (g) {
     //Etat initial
     case etatInitial:
     {}break;//Cas impossible
     //Etat jeuEnCours
     case jeuEnCours:
     {}break;//Cas impossible
     //Etat finPartie
     case finPartie:
     {
         _leModele->initCoups();
         _leModele->initScores();
         setEtatJeu(etatInitial);
         _laVue->miseAJour(getEtatJeu());
         _laVue->afficherCoupJoueur(_leModele->getCoupJoueur());
         _laVue->afficherCoupMachine(_leModele->getCoupMachine());
         _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));
         _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));
     }break;
     }
}

QString ChifoumiPresentation::recupererNomGagnant()
{
    //Affectation du nom du gagnant en fonction du résultat de la partie
    char g = _leModele->determinerGagnant();
    QString gagnant;
    switch(g){
    //Cas ou le joueur gagne la partie
    case 'J':
        {
        gagnant="vous Joueur";
        }break;
        //Cas ou la machine gagne la partie
    case 'M':
        {
        gagnant="La Machine";
    }break;
    //Cas ou il n'y a pas de gagnant
    case 'N':{}break;   //Cas impossible
    }
    return gagnant;
}

QString ChifoumiPresentation::getScoreMax()
{
    //Si le joueur à un score supérieur
    if(_leModele->getScoreJoueur()>_leModele->getScoreMachine())
    {
      return QString::number(_leModele->getScoreJoueur());
    }
    //Si la machine à un score supérieur
    else if(_leModele->getScoreJoueur()<_leModele->getScoreMachine())
    {
      return  QString::number(_leModele->getScoreMachine());
    }
    //Si la machine à un score égale au score du joueur
    else{
        return 0; //Cas impossible
    }
}


