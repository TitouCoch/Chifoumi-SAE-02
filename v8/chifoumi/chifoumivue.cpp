#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QDebug>

///* ---- PARTIE VUE ---------------------------

ChifoumiVue::ChifoumiVue(ChifoumiPresentation *p ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue), _laPresentation(p)
{
    ui->setupUi(this);

    //Connexion avec les actions de menu
    connect(ui->action_a_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));
    connect(ui->action_Quitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_Parametrer, SIGNAL(triggered()), p, SLOT(demandeParametrage()));

    //Connexions avec les boutons
    connect(ui->boutonPapier, SIGNAL(clicked()), p, SLOT(choixPapier()));
    connect(ui->boutonCiseau, SIGNAL(clicked()), p, SLOT(choixCiseau()));
    connect(ui->boutonPierre, SIGNAL(clicked()), p, SLOT(choixPierre()));
    connect(ui->boutonNvllePartie, SIGNAL(clicked()), p, SLOT(creerNvllePartie()));

    //Connexions timer
    connect(p->monTimer, SIGNAL(timeout()), p ,SLOT(decrementerTimer()));
    connect(ui->boutonPause, SIGNAL(clicked()), p, SLOT(demandePause()));
}


//Destructeur
ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}


ChifoumiPresentation* ChifoumiVue::getPresentation()
{
    return _laPresentation;
}
void ChifoumiVue::setPresentation(ChifoumiPresentation *p)
{
    _laPresentation = p;
}

void ChifoumiVue::miseAJour(ChifoumiPresentation::UnEtatJeu etat)
{
    switch(etat){
    //Etat Arrêt programme
    case ChifoumiPresentation::etatArretProgramme:
    {}//Cas impossible
    //Etat connexion
    case ChifoumiPresentation::etatConnexion:
    {}break;
    //Etat paramétrage
    case ChifoumiPresentation::etatParametrage:
    {}break;
    case ChifoumiPresentation::etatInitial:
        {
        //Récupère le score maximal dans l'interface
        ui->lScoreGagnant->setText(QString::number(_laPresentation->getModele()->getScoreMax()));
        //Désactivation des boutons figures
        ui->boutonPierre->setEnabled(false);
        ui->boutonPapier->setEnabled(false);
        ui->boutonCiseau->setEnabled(false);
        ui->boutonPause->setEnabled(false);
        //Mise en couleur des labels de noms et scores
        ui->lScoreJoueur->setStyleSheet("color: black;");
        ui->lScoreMachine->setStyleSheet("color: black;");
        ui->label_Vous->setStyleSheet("color: black;");
        ui->lMachine->setStyleSheet("color: black;");
        ui->boutonNvllePartie->setFocus();  //Placement du focus sur le bouton nouvelle partie

    }break;
    case ChifoumiPresentation::jeuEnCours:
    {
        qDebug()<<"TestVue";
        //Activation des boutons figures
        ui->boutonPause->setText("Pause");
        ui->boutonNvllePartie->setEnabled(true);
        ui->boutonPierre->setEnabled(true);
        ui->boutonPapier->setEnabled(true);
        ui->boutonCiseau->setEnabled(true);
        ui->boutonPause->setEnabled(true);
        //Mise en couleur des labels de noms et scores
        ui->lScoreJoueur->setStyleSheet("color: blue;");
        ui->lScoreMachine->setStyleSheet("color: blue;");
        ui->label_Vous->setStyleSheet("color: blue;");
        ui->lMachine->setStyleSheet("color: blue;");
        ui->boutonNvllePartie->setFocus();  //Placement du focus sur le bouton nouvelle partie
    }break;
    //Etat Pause
    case ChifoumiPresentation::etatPause:{
            ui->boutonPause->setText("Reprise Jeu");
            ui->boutonNvllePartie->setEnabled(false);
            ui->boutonPierre->setEnabled(false);
            ui->boutonPapier->setEnabled(false);
            ui->boutonCiseau->setEnabled(false);
    }break;
    //Etat Fin de partie
    case ChifoumiPresentation::finPartie:
    {
        //Appel de la fonction qui affiche la fin de partie dans une message box
        notifierGagnant(_laPresentation->recupererMessage());
        //Notifie la présentation que l'utilisateur a cliqué sur le bouton OK de la Message Box
        _laPresentation->okClicked();
        }break;
    default :
            break;
    }
}

void ChifoumiVue::afficherScoreJoueur(QString scoreJ)
{
   ui->lScoreJoueur->setText(scoreJ); //Affichage score joueur
}

void ChifoumiVue::afficherScoreMachine(QString scoreM)
{
    ui->lScoreMachine->setText(scoreM); //Affichage score machine
}

void ChifoumiVue::afficherCoupJoueur(ChifoumiModele::UnCoup coupJ)
{
    //Affichage du signe du joueur
    switch (coupJ) {
    case ChifoumiModele::pierre:
    {
        ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre.gif"));
    }break;
    case ChifoumiModele::papier:
    {
        ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/papier.gif"));
    }break;
    case ChifoumiModele::ciseau:
    {
        ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau.gif"));
    }break;
    case ChifoumiModele::rien:
    {
        ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/rien.gif"));
    }break;
    default:
        break;
    }
}

void ChifoumiVue::afficherCoupMachine(ChifoumiModele::UnCoup coupM)
{
    //Affichage du signe de la machine
    switch (coupM) {
    case ChifoumiModele::pierre:
    {
        ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/pierre.gif"));
    }break;
    case ChifoumiModele::papier:
    {
        ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/papier.gif"));
    }break;
    case ChifoumiModele::ciseau:
    {
        ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau.gif"));
    }break;
    case ChifoumiModele::rien:
    {
        ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/rien.gif"));
    }break;
    default:
        break;
    }
}

void ChifoumiVue::aProposDe()
{
    //Affichage d'une box message indiquant les auteurs, la date de création et la version
    QMessageBox::information(this, "A propos de cette application", "Version : 8 \n Date de création : 29/04/2022 \n Auteurs : Titouan Cocheril, Ivan Salle, Kepa Eyherabide ");
}

void ChifoumiVue::notifierGagnant(QString message)
{
    //Affichage d'une box message indiquant le gagnant son score et le temps de jeu
    QMessageBox::information(this, "Fin de partie", message);

}

void ChifoumiVue::tempsMiseAJours(int t)
{
    //Affichage du temps dans l'interface
    ui->lSeconde->setText(QString::number(t));
}

void ChifoumiVue::miseAJourVariable(QString nom, QString score, QString temps)
{
    //Mise à jour des variables modifié lors du paramétrage
    ui->label_Vous->setText(nom);
    ui->lScoreGagnant->setText(score);
    ui->lSeconde->setText(temps);
}
