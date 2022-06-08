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
    connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(aProposDe()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));

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
        //Désactivation des boutons figures
        ui->boutonPierre->setEnabled(false);
        ui->boutonPapier->setEnabled(false);
        ui->boutonCiseau->setEnabled(false);
        ui->boutonNvllePartie->setFocus();  //Placement du focus sur le bouton nouvelle partie
    }break;
    case ChifoumiPresentation::jeuEnCours:
    {
        //Initialisation des scores et des coups
        ui->lScoreJoueur->setText("0");
        ui->lScoreMachine->setText("0");
        ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/rien.gif"));
        ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/rien.gif"));
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
    default :
            qDebug() << "mise à jour problème" << Qt::endl;
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
    default:
        break;
    }
}

void ChifoumiVue::aProposDe()
{
    //qDebug() << "A propos de cliqué" << Qt::endl;
    QMessageBox::information(this, "A propos de cette application", "Version : 3 \n Date de création : 29/04/2022 \n Auteurs : Titouan Cocheril, Ivan Salle, Kepa Eyherabide ");
}
