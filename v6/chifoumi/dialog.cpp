#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //Placement des valeurs dans le spin box et le slider
    ui->slider->setRange(10, 120);
    ui->slider->setValue(60);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setValue(5);

    //Connexion des boutons et slider de la fenêtre de dialog
    connect (ui->buttonBox, SIGNAL(clicked()),this, SLOT(accept()));
    connect (ui->buttonBox, SIGNAL(clicked()),this, SLOT(reject()));
    connect(ui->slider,SIGNAL(sliderMoved(int)),this,SLOT(changeZoneTexte(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getNomChoisi()
{
    return ui->lineEdit->text();
}

unsigned int Dialog::getScoreChoisi()
{

    return ui->spinBox->value();
}

unsigned int Dialog::getTempsChoisi()
{
    return ui->lSecondeDialog->text().toInt();
}

void Dialog::changeZoneTexte(int valeur)
{
    //Modifie la variable de temps en fonction de la position du slider
    QString valeurCurseur= QString::number(valeur);
    ui->lSecondeDialog->setText(valeurCurseur);
}


