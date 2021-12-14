QT       += core gui
QT       += core gui sql
QT       += sql
QT       += printsupport
QT       += core gui  serialport
//sirine
QT +=svg
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11
CONFIG += console
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    client.cpp \
    connexion.cpp \
    domaine.cpp \
    employe.cpp \
    main.cpp \
    mainwindow.cpp \
    partenaires.cpp \
    piechartwidget.cpp \
    piechartwidget1.cpp \
    piechartwidget2.cpp \
    prime.cpp \
    qrcode.cpp \
    rdv.cpp \
    reclamation.cpp

HEADERS += \
    arduino.h \
    client.h \
    connexion.h \
    domaine.h \
    employe.h \
    mainwindow.h \
    partenaires.h \
    piechartwidget.h \
    piechartwidget1.h \
    piechartwidget2.h \
    prime.h \
    qrcode.h \
    rdv.h \
    reclamation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    sii.qrc

DISTFILES +=
