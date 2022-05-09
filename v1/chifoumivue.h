#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "chifoumimodele.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(ChifoumiModele *m,QWidget *parent = nullptr);
    ~ChifoumiVue();

    ///* Méthodes du Modéle
public:
    void miseAJour(ChifoumiModele::UnCoup,ChifoumiModele::UnCoup);
    //Met à jour les scores des joueurs et affiche dans les cases prévus les images de signes

//Getter
    ChifoumiModele* getModele();
//Setter
    void setModele(ChifoumiModele *m);
//Slots
public slots:
    void choixPapier();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi la feuille
    void choixPierre();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi la pierre
    void choixCiseau();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi la ciseau
    void creerNvllePartie();
    //Procédure qui initialise les scores et les coups du joueur et de la machine, donne accès  aux boutons de figures

private:
    ChifoumiModele *_leModele;	// pteur vers le modèle
    Ui::ChifoumiVue *ui;
};
#endif // CHIFOUMIVUE_H
