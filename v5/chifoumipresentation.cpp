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
        monTimer->stop();
        setEtatJeu(finPartie);  //Place l'état du jeu sur finPartie
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }break;
    //Etat Pause
    case etatPause:{}//Cas impossible
        break;
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
        monTimer->stop();
        setEtatJeu(finPartie);  //Place l'état du jeu sur finPartie
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }break;
    //Etat Pause
    case etatPause:{}//Cas impossible
        break;
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
        monTimer->stop();
        setEtatJeu(finPartie);  //Place l'état du jeu sur finPartie
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'affichage avec l'état du jeu
    }
    }break;
    //Etat Pause
    case etatPause:{}//Cas impossible
        break;
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
    monTimer->start(1000); //démarre un timer de 1 secondes
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
    //Etat Pause
    case etatPause:{}//Cas impossible
        break;
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
     case etatPause:
     {}break;//Cas impossible
     //Etat finPartie
     case finPartie:
     {
         _leModele->initCoups();
         _leModele->initScores();
         setEtatJeu(etatInitial);
         _laVue->miseAJour(getEtatJeu());
         _leModele->initTemps();     //Initialisation des variables de temp
         _laVue->tempsMiseAJours(_leModele->getTemps());
         _laVue->afficherCoupJoueur(_leModele->getCoupJoueur());
         _laVue->afficherCoupMachine(_leModele->getCoupMachine());
         _laVue->afficherScoreJoueur(QString::number(_leModele->getScoreJoueur()));
         _laVue->afficherScoreMachine(QString::number(_leModele->getScoreMachine()));
     }break;
     }
}


QString ChifoumiPresentation::recupererMessage()
{
    //Affectation de la phrase de fin de partie en fonction du gagnant et du temps
    char g = _leModele->determinerGagnant();
    QString gagnant;
    switch(g){
    //Cas ou le joueur gagne la partie
    case 'J':
        {
        if (_leModele->getTemps()==0)
        {
        gagnant="Helas temps de jeu fini. Vous terminez toutefois mieux avec "+ QString::number(_leModele->getScoreJoueur())+" point(s)!";
        }
        else
        {
        gagnant="Vous vous imposez dans le temps impartie avec "+ QString::number(_leModele->getScoreJoueur())+" point(s) en " +QString::number(_leModele->getTemps())+" secondes!";
        }
        }break;
        //Cas ou la machine gagne la partie
    case 'M':
        {
        if (_leModele->getTemps()==0)
        {
        gagnant="Helas temps de jeu fini. La machine termine toutefois mieux avec "+ QString::number(_leModele->getScoreMachine())+" point(s)!";
        }
        else
        {
        gagnant="La machine s'impose dans le temps impartie avec "+ QString::number(_leModele->getScoreMachine())+" point(s) en " +QString::number(_leModele->getTemps())+" secondes!";
        }
    }break;
    //Cas ou il n'y a pas de gagnant
    case 'N':{
        gagnant="Helas temps de jeu fini. Aucun des joueurs n'as réusssi à s'imposer dans le temps imparti !";
    }break;
    }
    return gagnant;
}

QString ChifoumiPresentation::getScoreMax2()
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

void ChifoumiPresentation::decrementerTimer()
{
    //Si le temps de jeu est différent de 0
    if(_leModele->getTemps()!=0)
    {
    _leModele->setTemps(_leModele->getTemps()-1);   //On décrémente le temps de jeu dans le modèle
    _laVue->tempsMiseAJours(_leModele->getTemps()); //On met à jour l'affichage du temps dans la vue
    }
    //Si le temps de jeu est égale à 0
    else
    {
    monTimer->stop();   //Arrêt du timer
    setEtatJeu(finPartie);  //Place l'état du jeu sur fin de partie
    _laVue->miseAJour(getEtatJeu());    //On met à jour l'affichage en fonction de l'état
    }

}


void ChifoumiPresentation::demandePause()
{
    UnEtatJeu g = ChifoumiPresentation::getEtatJeu();
    switch (g) {
    //Etat initial
    case etatInitial:
    {}break;//Cas impossible
    //Etat jeuEnCours
    case jeuEnCours:
    {
        setEtatJeu(etatPause);  //Place l'état sur etat de pause
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'interface en fonction de l'état du jeu
        monTimer->stop();   //Arrêt du timer
    }break;
    //Etat finPartie
    case etatPause:
    {
        setEtatJeu(jeuEnCours); //Place l'état sur jeu en cours
        _laVue->miseAJour(getEtatJeu());    //Mise à jour de l'interface en fonction de l'état du jeu
        monTimer->start(1000);  //Relance le timer
    }break;
    //Etat finPartie
    case finPartie:
    {
    }break;//Cas impossible
    }
}
