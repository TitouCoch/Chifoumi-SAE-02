#include "resultat.h"
#include "ui_resultat.h"

resultat::resultat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultat)
{
    ui->setupUi(this);
}

resultat::~resultat()
{
    delete ui;
}

void resultat::majTableauResultat()
{
    QSqlQuery query;
    query.exec("SELECT *,Resultat.ScoreJoueurHumain/(Resultat.scoreJoueurHumain+Resultat.ScoreJoueurMachine) as ratio FROM Resultat WHERE Resultat.ScoreJoueurHumain>Resultat.ScoreJoueurMachine ORDER BY ratio DESC LIMIT 10;");
    for(int i = 0; query.next(); i++){
       ui->tableWidget->insertRow(i);
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
       ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
       ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
    }
}
