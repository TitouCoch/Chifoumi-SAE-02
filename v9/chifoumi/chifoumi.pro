QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chifoumimodele.cpp \
    chifoumipresentation.cpp \
    connexion.cpp \
    dialog.cpp \
    main.cpp \
    chifoumivue.cpp \
    resultat.cpp

HEADERS += \
    chifoumimodele.h \
    chifoumipresentation.h \
    chifoumivue.h \
    connexion.h \
    dialog.h \
    resultat.h

FORMS += \
    chifoumivue.ui \
    connexion.ui \
    dialog.ui \
    resultat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressourceChifoumi.qrc
