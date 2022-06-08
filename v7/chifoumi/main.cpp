#include "chifoumivue.h"
#include "chifoumimodele.h"
#include "chifoumipresentation.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // créer le modèle
    ChifoumiModele *m = new ChifoumiModele();
    // créer la présentation et lui associer le modèle
    ChifoumiPresentation *p = new ChifoumiPresentation(m);
    // créer la vue
    ChifoumiVue v(p);
    // associer la vue à la présentation
    connexion * connec= new connexion(p);    //Création d'une intance de fenêtre de connexion
    p->opendatabase();  //ouverture de la base de données
    p->setConnexion(connec);    //Associe la présentation avec la connexion
    connec->exec();  //Execute la fenêtre de de connexion

    if(p->getEtatJeu()==ChifoumiPresentation::etatInitial)
    {
        //Si l'état de jeu est l'état initial
        p->setVue(&v);  //Affectation de la vue dans la présentation
        p->getVue()->miseAJour(p->getEtatJeu());    // initialiser la vue en conformité avec l'état initial du modèle
        // afficher la vue
        v.show();
    }
    if(p->getEtatJeu()==ChifoumiPresentation::etatArretProgramme)
    {
        //Si l'état est sur arrêt du programme
        p->closedatabase(); //Fermeture de la base de données
        exit(1);    //arrêt du programme
    }
    // Boucle d'attente des messages
    return a.exec();
}


