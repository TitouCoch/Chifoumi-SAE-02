/********************************************************************************
** Form generated from reading UI file 'chifoumivue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIFOUMIVUE_H
#define UI_CHIFOUMIVUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChifoumiVue
{
public:
    QWidget *fenetrePrincipalH;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *fenetreSecondaireV;
    QGridLayout *grilleTop;
    QVBoxLayout *vLayout_MachineScore;
    QLabel *lMachine;
    QLabel *lScoreMachine;
    QVBoxLayout *vLayout_JoueurScore;
    QLabel *label_Vous;
    QLabel *lScoreJoueur;
    QHBoxLayout *hLayout_ChoixJoueur;
    QSpacerItem *hSpacerG_ChoixJoueur;
    QLabel *lChoixJoueur;
    QSpacerItem *hSpacerD_ChoixJoueur;
    QHBoxLayout *hLayout_Versus;
    QSpacerItem *hSpacerG_Versus;
    QLabel *lVersus;
    QSpacerItem *hSpacerD_Versus;
    QHBoxLayout *hLayout_ChoixMachine;
    QSpacerItem *hSpacerG_ChoixMachine;
    QLabel *lChoixMachine;
    QSpacerItem *hSpacerD_ChoixMachine;
    QSpacerItem *vSpacerMiddle;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *hSpacerG_GroupBox;
    QPushButton *boutonPierre;
    QPushButton *boutonPapier;
    QPushButton *boutonCiseau;
    QSpacerItem *hSpacerD_GroupBox;
    QGridLayout *grilleBottom;
    QPushButton *boutonNvllePartie;
    QSpacerItem *hSpacerNvllePartie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChifoumiVue)
    {
        if (ChifoumiVue->objectName().isEmpty())
            ChifoumiVue->setObjectName(QString::fromUtf8("ChifoumiVue"));
        ChifoumiVue->resize(550, 491);
        fenetrePrincipalH = new QWidget(ChifoumiVue);
        fenetrePrincipalH->setObjectName(QString::fromUtf8("fenetrePrincipalH"));
        fenetrePrincipalH->setMinimumSize(QSize(550, 450));
        horizontalLayout_2 = new QHBoxLayout(fenetrePrincipalH);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fenetreSecondaireV = new QVBoxLayout();
        fenetreSecondaireV->setObjectName(QString::fromUtf8("fenetreSecondaireV"));
        grilleTop = new QGridLayout();
        grilleTop->setObjectName(QString::fromUtf8("grilleTop"));
        vLayout_MachineScore = new QVBoxLayout();
        vLayout_MachineScore->setObjectName(QString::fromUtf8("vLayout_MachineScore"));
        lMachine = new QLabel(fenetrePrincipalH);
        lMachine->setObjectName(QString::fromUtf8("lMachine"));
        lMachine->setAlignment(Qt::AlignCenter);

        vLayout_MachineScore->addWidget(lMachine);

        lScoreMachine = new QLabel(fenetrePrincipalH);
        lScoreMachine->setObjectName(QString::fromUtf8("lScoreMachine"));
        lScoreMachine->setAlignment(Qt::AlignCenter);

        vLayout_MachineScore->addWidget(lScoreMachine);


        grilleTop->addLayout(vLayout_MachineScore, 0, 2, 1, 1);

        vLayout_JoueurScore = new QVBoxLayout();
        vLayout_JoueurScore->setObjectName(QString::fromUtf8("vLayout_JoueurScore"));
        label_Vous = new QLabel(fenetrePrincipalH);
        label_Vous->setObjectName(QString::fromUtf8("label_Vous"));
        label_Vous->setAlignment(Qt::AlignCenter);

        vLayout_JoueurScore->addWidget(label_Vous);

        lScoreJoueur = new QLabel(fenetrePrincipalH);
        lScoreJoueur->setObjectName(QString::fromUtf8("lScoreJoueur"));
        lScoreJoueur->setAlignment(Qt::AlignCenter);

        vLayout_JoueurScore->addWidget(lScoreJoueur);


        grilleTop->addLayout(vLayout_JoueurScore, 0, 0, 1, 1);

        hLayout_ChoixJoueur = new QHBoxLayout();
        hLayout_ChoixJoueur->setObjectName(QString::fromUtf8("hLayout_ChoixJoueur"));
        hSpacerG_ChoixJoueur = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_ChoixJoueur->addItem(hSpacerG_ChoixJoueur);

        lChoixJoueur = new QLabel(fenetrePrincipalH);
        lChoixJoueur->setObjectName(QString::fromUtf8("lChoixJoueur"));
        lChoixJoueur->setMinimumSize(QSize(110, 110));
        lChoixJoueur->setMaximumSize(QSize(110, 110));
        lChoixJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/rien.gif")));

        hLayout_ChoixJoueur->addWidget(lChoixJoueur);

        hSpacerD_ChoixJoueur = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_ChoixJoueur->addItem(hSpacerD_ChoixJoueur);


        grilleTop->addLayout(hLayout_ChoixJoueur, 1, 0, 1, 1);

        hLayout_Versus = new QHBoxLayout();
        hLayout_Versus->setObjectName(QString::fromUtf8("hLayout_Versus"));
        hSpacerG_Versus = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_Versus->addItem(hSpacerG_Versus);

        lVersus = new QLabel(fenetrePrincipalH);
        lVersus->setObjectName(QString::fromUtf8("lVersus"));
        lVersus->setMinimumSize(QSize(78, 78));
        lVersus->setMaximumSize(QSize(78, 78));
        lVersus->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/versus_70.png")));

        hLayout_Versus->addWidget(lVersus);

        hSpacerD_Versus = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_Versus->addItem(hSpacerD_Versus);


        grilleTop->addLayout(hLayout_Versus, 1, 1, 1, 1);

        hLayout_ChoixMachine = new QHBoxLayout();
        hLayout_ChoixMachine->setObjectName(QString::fromUtf8("hLayout_ChoixMachine"));
        hSpacerG_ChoixMachine = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_ChoixMachine->addItem(hSpacerG_ChoixMachine);

        lChoixMachine = new QLabel(fenetrePrincipalH);
        lChoixMachine->setObjectName(QString::fromUtf8("lChoixMachine"));
        lChoixMachine->setMinimumSize(QSize(110, 110));
        lChoixMachine->setMaximumSize(QSize(110, 110));
        lChoixMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/rien.gif")));

        hLayout_ChoixMachine->addWidget(lChoixMachine);

        hSpacerD_ChoixMachine = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_ChoixMachine->addItem(hSpacerD_ChoixMachine);


        grilleTop->addLayout(hLayout_ChoixMachine, 1, 2, 1, 1);


        fenetreSecondaireV->addLayout(grilleTop);

        vSpacerMiddle = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        fenetreSecondaireV->addItem(vSpacerMiddle);

        groupBox = new QGroupBox(fenetrePrincipalH);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hSpacerG_GroupBox = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacerG_GroupBox);

        boutonPierre = new QPushButton(groupBox);
        boutonPierre->setObjectName(QString::fromUtf8("boutonPierre"));
        boutonPierre->setMinimumSize(QSize(110, 110));
        boutonPierre->setMaximumSize(QSize(110, 110));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/chifoumi/images/pierre.gif"), QSize(), QIcon::Normal, QIcon::Off);
        boutonPierre->setIcon(icon);
        boutonPierre->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(boutonPierre);

        boutonPapier = new QPushButton(groupBox);
        boutonPapier->setObjectName(QString::fromUtf8("boutonPapier"));
        boutonPapier->setMinimumSize(QSize(110, 110));
        boutonPapier->setMaximumSize(QSize(110, 110));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/chifoumi/images/papier.gif"), QSize(), QIcon::Normal, QIcon::Off);
        boutonPapier->setIcon(icon1);
        boutonPapier->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(boutonPapier);

        boutonCiseau = new QPushButton(groupBox);
        boutonCiseau->setObjectName(QString::fromUtf8("boutonCiseau"));
        boutonCiseau->setMinimumSize(QSize(110, 110));
        boutonCiseau->setMaximumSize(QSize(110, 110));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/chifoumi/images/ciseau.gif"), QSize(), QIcon::Normal, QIcon::Off);
        boutonCiseau->setIcon(icon2);
        boutonCiseau->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(boutonCiseau);

        hSpacerD_GroupBox = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacerD_GroupBox);


        fenetreSecondaireV->addWidget(groupBox);

        grilleBottom = new QGridLayout();
        grilleBottom->setObjectName(QString::fromUtf8("grilleBottom"));
        boutonNvllePartie = new QPushButton(fenetrePrincipalH);
        boutonNvllePartie->setObjectName(QString::fromUtf8("boutonNvllePartie"));

        grilleBottom->addWidget(boutonNvllePartie, 1, 1, 1, 1);

        hSpacerNvllePartie = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        grilleBottom->addItem(hSpacerNvllePartie, 1, 0, 1, 1);


        fenetreSecondaireV->addLayout(grilleBottom);


        horizontalLayout_2->addLayout(fenetreSecondaireV);

        ChifoumiVue->setCentralWidget(fenetrePrincipalH);
        menubar = new QMenuBar(ChifoumiVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 550, 21));
        ChifoumiVue->setMenuBar(menubar);
        statusbar = new QStatusBar(ChifoumiVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChifoumiVue->setStatusBar(statusbar);

        retranslateUi(ChifoumiVue);

        QMetaObject::connectSlotsByName(ChifoumiVue);
    } // setupUi

    void retranslateUi(QMainWindow *ChifoumiVue)
    {
        ChifoumiVue->setWindowTitle(QCoreApplication::translate("ChifoumiVue", "ChifoumiVue", nullptr));
        lMachine->setText(QCoreApplication::translate("ChifoumiVue", "Machine", nullptr));
        lScoreMachine->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        label_Vous->setText(QCoreApplication::translate("ChifoumiVue", "Vous", nullptr));
        lScoreJoueur->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        lChoixJoueur->setText(QString());
        lVersus->setText(QString());
        lChoixMachine->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("ChifoumiVue", "Choisissez une figure :", nullptr));
        boutonPierre->setText(QString());
        boutonPapier->setText(QString());
        boutonCiseau->setText(QString());
        boutonNvllePartie->setText(QCoreApplication::translate("ChifoumiVue", "Nouvelle partie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChifoumiVue: public Ui_ChifoumiVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIFOUMIVUE_H
