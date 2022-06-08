#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include "connexion.h"
#include <QDebug>
#include <QMessageBox>

///* ---- PARTIE PRESENTATION ---------------------------


ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{
    //Initialise l'état du jeu sur l'état connexion
    setEtatJeu(UnEtatJeu::etatConnexion);
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

connexion *ChifoumiPresentation::getConnexion()
{
    return db;
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

void ChifoumiPresentation::setConnexion(connexion *c)
{
    db = c;
}

//Slots
void ChifoumiPresentation::choixPapier()
{
    UnEtatJeu g = getEtatJeu();
    switch(g){
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:{} //Cas impossible
    break;
    //Etat paramétrage
    case ChifoumiPresentation::etatParametrage:
    {}break;
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
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:{} //Cas impossible
    break;
    //Etat paramétrage
    case ChifoumiPresentation::etatParametrage:
    {}break;
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
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:{} //Cas impossible
    break;
    //Etat paramétrage
    case ChifoumiPresentation::etatParametrage:
    {}break;
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
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:{} //Cas impossible
    break;
    //Etat paramétrage
    case ChifoumiPresentation::etatParametrage:
    {}break;
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
    _leModele->initTemps();     //Initialisation des variables de temps
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
     //Etat Arrêt programme
     case etatArretProgramme:
     {}//Cas impossible
     //Etat connexion
     case etatConnexion:{} //Cas impossible
     break;
     //Etat paramétrage
     case ChifoumiPresentation::etatParametrage:
     {}break;
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
         setEtatJeu(etatInitial);   //Place l'état du jeu sur l'état initial
         _laVue->miseAJour(getEtatJeu());   //mise à jour de l'affichage
         _leModele->initCoups();    //Initialise les variables de coups
         _leModele->initScores();   //Initialise le scores
         _leModele->initTemps();     //Initialisation de la variable de temps
         _laVue->tempsMiseAJours(_leModele->getTemps());    //Mise à jour l'affichage du temps
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
        gagnant="Vous vous imposez dans le temps impartie avec "+ QString::number(_leModele->getScoreJoueur())+" point(s) et il restait " +QString::number(_leModele->getTemps())+" secondes!";
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
        gagnant="La machine s'impose dans le temps impartie avec "+ QString::number(_leModele->getScoreMachine())+" point(s) et il restait " +QString::number(_leModele->getTemps())+" secondes!";
        }
    }break;
    //Cas ou il n'y a pas de gagnant
    case 'N':{
        gagnant="Helas temps de jeu fini. Aucun des joueurs n'as réusssi à s'imposer dans le temps imparti !";
    }break;
    }
    return gagnant;
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
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:{} //Cas impossible
    break;
    //Etat paramétrage
    case ChifoumiPresentation::etatParametrage:
    {}break;
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


void ChifoumiPresentation::demandeParametrage()
{
    //vérifie que l'on est bien dans l'état initial
    if(getEtatJeu()==etatInitial)
    {
        //On change l'état du jeu sur état paramétrage
         setEtatJeu(etatParametrage);
    }
    UnEtatJeu g = ChifoumiPresentation::getEtatJeu();
    switch (g) {
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:{} //Cas impossible
    break;
    //Etat Paramétrage
    case etatParametrage:{
        Dialog * maDlg= new Dialog(nullptr);    //Création d'une intance de fenêtre de dialog
        maDlg->exec();  //Execute la fenêtre de dialog
        QString Nom;
        //Si la case n'est pas vide
        if (!maDlg->getNomChoisi().isEmpty())
        {
             Nom=maDlg->getNomChoisi();     //récupère la saisi dans le line edit
             _leModele->setNomJoueur(Nom);  //on place le nom dans le modèle
        }
        else
        {
            Nom="Vous";
            _leModele->setNomJoueur(Nom);   //sinon on place le nom vous dans le modèle
        }
        unsigned int scoreMaxChoisi=maDlg->getScoreChoisi();    //On récupère le score saisi
        _leModele->setScoreMax(scoreMaxChoisi); //On place la saisi dans l'attribut membre scoreMax
        unsigned int tempsMaxChoisi=maDlg->getTempsChoisi();    //On récupère le temps saisi
        _leModele->setTempsMax(tempsMaxChoisi); //On place la saisi dans l'attribut membre tempsMax
        _leModele->initTemps(); //on initialse le temps de jeu avec le temps max
        QString scoreMax = QString::number(scoreMaxChoisi); //On convertie le scoreMax en QString
        QString tempsMax =QString::number(tempsMaxChoisi);  //On convertie le tempsMax en QString
        _laVue->miseAJourVariable(Nom,scoreMax,tempsMax);   //On met à jour la vue
        setEtatJeu(etatInitial);    //on met l'état sur état initial
    }break;
    //Etat initial
    case etatInitial:
    {}break;
    //Etat jeuEnCours
    case jeuEnCours:
    {}break;//Cas impossible
    //Etat finPartie
    case etatPause:
    {}break;//Cas impossible
    //Etat finPartie
    case finPartie:
    {}break;//Cas impossible
    }
}

void ChifoumiPresentation::connexionOk()
{
    UnEtatJeu g = ChifoumiPresentation::getEtatJeu();
    switch (g) {
    //Etat Arrêt programme
    case etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case etatConnexion:
    {
        setEtatJeu(etatInitial);    //place l'état de jeu sur état initial
    }
    //Etat paramétrage
    case etatParametrage:
    {}break;
    break;
    //Etat initial
    case etatInitial:
    {}break;//Cas impossible
    //Etat jeuEnCours
    case jeuEnCours:
    {}break;
    //Etat finPartie
    case etatPause:
    {}break;
    //Etat finPartie
    case finPartie:
    {
    }break;//Cas impossible
    }
}
void ChifoumiPresentation::Sortir()
{
    setEtatJeu(etatArretProgramme); //place l'état de jeu sur etatArretProgramme
}

bool ChifoumiPresentation::testConnexion()
{
    QSqlQuery *query = new QSqlQuery;
    QString utilisateur = db->getUtilisteur();  //récupère la saisies du nom
    QString mdp = db->getPassword();    //récupère la saisies du mot de passe
    if(!query->exec("SELECT utilisateur FROM Authentification WHERE utilisateur = '"+ utilisateur +"' AND motDePasse = '"+ mdp +"' "))
    {
        //username et password incorrecte
        QString message = "Connexion impossible, problème de base de données !";
        db->messageErreur(message);  //affiche le message d'erreur
        db->clearSaisi();   //Vide les saisies de l'utilisateur
        return false;   //retourne faux
    }
    else if(!query->first())
    {
        //incorrect username o password
        QString message = "Connexion impossible, nom d'utilisateur ou mot de passe incorrect !";
        db->messageErreur(message); //affiche le message d'erreur
        db->clearSaisi();   //Vide les saisies de l'utilisateur
        return false;   //retourne faux
    }
    else
    {

        db->hide(); //Cache la fenêtre de connexion
        connexionOk(); //Appelle de la méthode connexionOk
        return true;    //retourne vrai
    }
}

bool ChifoumiPresentation::opendatabase()
{
    //Ouverture de la base de données
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName((DATABASE_NAME));
    return mydb.open();
}

void ChifoumiPresentation::closedatabase()
{
    mydb.close(); //Fermeture de la base de données
}

