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

    //Connexions avec les boutons
    connect(ui->boutonPapier, SIGNAL(clicked()), p, SLOT(choixPapier()));
    connect(ui->boutonCiseau, SIGNAL(clicked()), p, SLOT(choixCiseau()));
    connect(ui->boutonPierre, SIGNAL(clicked()), p, SLOT(choixPierre()));
    connect(ui->boutonNvllePartie, SIGNAL(clicked()), p, SLOT(creerNvllePartie()));
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
    case ChifoumiPresentation::etatInitial:
        {
        //Récupère le score maximal dans l'interface
        ui->lScoreGagnant->setText(QString::number(_laPresentation->getModele()->getScoreMax()));
        //Désactivation des boutons figures
        ui->boutonPierre->setEnabled(false);
        ui->boutonPapier->setEnabled(false);
        ui->boutonCiseau->setEnabled(false);
        //Mise en couleur des labels de noms et scores
        ui->lScoreJoueur->setStyleSheet("color: black;");
        ui->lScoreMachine->setStyleSheet("color: black;");
        ui->label_Vous->setStyleSheet("color: black;");
        ui->lMachine->setStyleSheet("color: black;");
        ui->boutonNvllePartie->setFocus();  //Placement du focus sur le bouton nouvelle partie
    }break;
    case ChifoumiPresentation::jeuEnCours:
    {
        //Activation des boutons figures
        ui->boutonPierre->setEnabled(true);
        ui->boutonPapier->setEnabled(true);
        ui->boutonCiseau->setEnabled(true);
        //Mise en couleur des labels de noms et scores
        ui->lScoreJoueur->setStyleSheet("color: blue;");
        ui->lScoreMachine->setStyleSheet("color: blue;");
        ui->label_Vous->setStyleSheet("color: blue;");
        ui->lMachine->setStyleSheet("color: blue;");
        ui->boutonNvllePartie->setFocus();  //Placement du focus sur le bouton nouvelle partie
    }break;
    case ChifoumiPresentation::finPartie:
    {
        //Appel de la fonction qui affiche la fin de partie dans une message box
        notifierGagnant(_laPresentation->recupererNomGagnant(),_laPresentation->getScoreMax());
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
    QMessageBox::information(this, "A propos de cette application", "Version : 4 \n Date de création : 29/04/2022 \n Auteurs : Titouan Cocheril, Ivan Salle, Kepa Eyherabide ");
}

void ChifoumiVue::notifierGagnant(QString nom,QString pts)
{
    //Affichage d'une box message indiquant le gagnant et son score
    QMessageBox::information(this, "Fin de partie", "Bravo à " + nom + ". Vous gagnez la partie avec "+pts+" points !");
}
