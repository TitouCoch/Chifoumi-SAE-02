#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include "chifoumimodele.h"


class ChifoumiVue;
class ChifoumiPresentation : public QObject
{
    Q_OBJECT


public:
    //Type enuméré correspondant à l'état du jeu
    enum UnEtatJeu{etatInitial, jeuEnCours};
    //Constructeur
    explicit ChifoumiPresentation(ChifoumiModele *m,QObject *parent = nullptr);

    //Getter
    ChifoumiModele* getModele();
    ChifoumiVue* getVue();
    UnEtatJeu getEtatJeu();

    //Setter
    void setModele(ChifoumiModele *m);
    void setVue(ChifoumiVue *v);
    void setEtatJeu(UnEtatJeu e);

public slots :
    //Méthodes
    void choixPapier();
    //Procédure qui met en œuvre le diagramme états-transition lorsque le joueur choisit le papier
    void choixPierre();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi la pierre
    void choixCiseau();
    //Procédure qui active les différentes fonctions lorsque le joueur choisi le ciseau
    void creerNvllePartie();
    //Procédure qui initialise les scores et les coups du joueur et de la machine, donne
    // accès aux boutons de figures

private :
    //Attribut de la présentation
    ChifoumiModele *_leModele;	// pteur vers le modèle
    ChifoumiVue *_laVue;		// pteur vers la vue
    UnEtatJeu _etatJeu;

};

#endif // CHIFOUMIPRESENTATION_H
