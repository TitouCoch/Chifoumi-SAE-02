#include "chifoumivue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChifoumiModele *m = new ChifoumiModele(); // créer le modèle
    ChifoumiVue w(m); //créé la vue et lui associe le modèle
    w.show();   //Affiche la vue
    return a.exec();
}
