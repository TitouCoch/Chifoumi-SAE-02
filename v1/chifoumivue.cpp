#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QDebug>

ChifoumiVue::ChifoumiVue(ChifoumiModele *m ,QWidget *parent)
    : QMainWindow(parent),
     _leModele(m), ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
    //Initialisation des scores et des coups
    _leModele->initCoups();
    _leModele->initScores();

    //Désactivation des boutons figures
    ui->boutonPierre->setEnabled(false);
    ui->boutonPapier->setEnabled(false);
    ui->boutonCiseau->setEnabled(false);

    //Connexions
    connect(ui->boutonPapier, SIGNAL(clicked()), this, SLOT(choixPapier()));
    connect(ui->boutonCiseau, SIGNAL(clicked()), this, SLOT(choixCiseau()));
    connect(ui->boutonPierre, SIGNAL(clicked()), this, SLOT(choixPierre()));
    connect(ui->boutonNvllePartie, SIGNAL(clicked()), this, SLOT(creerNvllePartie()));
}

//Destructeur
ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

//Getter
ChifoumiModele *ChifoumiVue::getModele()
{
    return _leModele;
}

//Setter
void ChifoumiVue::setModele(ChifoumiModele *m)
{
    _leModele = m;
}


//Méthodes slots
void ChifoumiVue::choixPapier(){
    //qDebug()<<"Test choix papier<<endl";
    _leModele->setCoupMachine(_leModele->genererUnCoup()); //Génère un coup pour la machine
    _leModele->setCoupJoueur(ChifoumiModele::papier);   //Attribut le papier comme coup du joueur
    _leModele->majScores(_leModele->determinerGagnant());  //Détermine le gagnant et on met à jour les scores
    this->miseAJour(_leModele->getCoupJoueur(),_leModele->getCoupMachine());    //Met à jour l'interface
}
void ChifoumiVue::choixCiseau(){
    //qDebug()<<"Test choix ciseau<<endl";
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->setCoupJoueur(ChifoumiModele::ciseau);   //Attribut le ciseau comme coup du joueur
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jour les scores
    this->miseAJour(_leModele->getCoupJoueur(),_leModele->getCoupMachine());    //Met à jour l'interface
}
void ChifoumiVue::choixPierre(){
    //qDebug()<<"Test choix pierre<<endl";
    _leModele->setCoupMachine(_leModele->genererUnCoup());  //Génère un coup pour la machine
    _leModele->setCoupJoueur(ChifoumiModele::pierre);   //Attribut le pierre comme coup du joueur
    _leModele->majScores(_leModele->determinerGagnant());   //Détermine le gagnant et on met à jour les scores
    this->miseAJour(_leModele->getCoupJoueur(),_leModele->getCoupMachine());    //Met à jour l'interface
}
void ChifoumiVue::creerNvllePartie(){
    //qDebug()<<"Test nouvelle partie<<endl";
    //Activation des boutons
    ui->boutonPierre->setEnabled(true);
    ui->boutonCiseau->setEnabled(true);
    ui->boutonPapier->setEnabled(true);
    //initialisations des coups et des scores
    _leModele->initCoups();
    _leModele->initScores();
    this->miseAJour(_leModele->getCoupJoueur(),_leModele->getCoupMachine()); //Met à jour l'interface
}

void ChifoumiVue::miseAJour(ChifoumiModele::UnCoup coupM, ChifoumiModele::UnCoup coupJ){

    //qDebug()<<"Test mise à jour<<endl";
    //Affiche le coup de la machine
    switch (coupM) {
        case ChifoumiModele::rien: ui->lChoixMachine->setPixmap(QPixmap(":/Chifoumi/images/rien.gif")); break;
        case ChifoumiModele::pierre: ui->lChoixMachine->setPixmap(QPixmap(":/Chifoumi/images/pierre.gif"));  break;
        case ChifoumiModele::papier: ui->lChoixMachine->setPixmap(QPixmap(":/Chifoumi/images/papier.gif"));break;
        case ChifoumiModele::ciseau: ui->lChoixMachine->setPixmap(QPixmap(":/Chifoumi/images/ciseau.gif")); break;
    }
    //Affiche le coup du joueur
    switch (coupJ) {
        case ChifoumiModele::rien: ui->lChoixJoueur->setPixmap(QPixmap(":/Chifoumi/images/rien.gif")); break;
        case ChifoumiModele::pierre: ui->lChoixJoueur->setPixmap(QPixmap(":/Chifoumi/images/pierre.gif"));  break;
        case ChifoumiModele::papier: ui->lChoixJoueur->setPixmap(QPixmap(":/Chifoumi/images/papier.gif"));break;
        case ChifoumiModele::ciseau: ui->lChoixJoueur->setPixmap(QPixmap(":/Chifoumi/images/ciseau.gif")); break;
    }
    //Affiche les scores du joueur et de la machine
    QString str;
    ui->lScoreMachine->setText(str.QString::setNum(_leModele->getScoreMachine()));
    ui->lScoreJoueur->setText(str.QString::setNum(_leModele->getScoreJoueur()));

}
