#include "chifoumivue.h"
#include "chifoumimodele.h"
#include "chifoumipresentation.h"

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
    p->setVue(&v);
    // initialiser la vue en conformité avec l'état initial du modèle
    p->getVue()->miseAJour(p->getEtatJeu());
    // afficher la vue et démarrer la boucle d'attente des messages
    v.show();
    return a.exec();
}
