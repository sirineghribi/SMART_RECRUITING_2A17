#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql \
multimedia
QT += core
QT += printsupport

QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
QT += widgets multimedia
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    employe.cpp \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    prime.cpp \
    qrcode.cpp \
    reclamation.cpp

HEADERS += \
    employe.h \
    login.h \
        mainwindow.h \
    connection.h \
    prime.h \
    qrcode.h \
    reclamation.h

FORMS += \
        log.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    donutbreakdown.pro

DISTFILES += \
    donutbreakdown.pro.user \
    son_click.mp3

RESOURCES += \
    res.qrc
