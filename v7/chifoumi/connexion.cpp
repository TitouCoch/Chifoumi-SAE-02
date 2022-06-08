#include "connexion.h"
#include "ui_connexion.h"

connexion::connexion(ChifoumiPresentation *p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connexion), _laPresentation(p)
{
    ui->setupUi(this);
    //La saisi est placé comme un password
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    //Connexion des boutons
    connect(ui->boutonConnexion, SIGNAL(clicked()), p,SLOT(testConnexion()));
    connect(this,SIGNAL(rejected()),p,SLOT(Sortir()));
}

connexion::~connexion()
{
    delete ui;
}


ChifoumiPresentation* connexion::getPresentation()
{
    return _laPresentation;
}
void connexion::setPresentation(ChifoumiPresentation *p)
{

    _laPresentation = p;
}

QString connexion::getUtilisteur()
{
    //récupère le nom d'utilisateur
    return ui->lineEditUtilisateur->text();
}

QString connexion::getPassword()
{
    //récupère le password
    return ui->lineEditPassword->text();
}

void connexion::messageErreur(QString message)
{
    //affichage du message d'erreur
    QMessageBox::information(this, "Erreur", message);
}

void connexion::clearSaisi()
{
    //vides les cases de saisies
    ui->lineEditUtilisateur->setText("");
    ui->lineEditPassword->setText("");
}
