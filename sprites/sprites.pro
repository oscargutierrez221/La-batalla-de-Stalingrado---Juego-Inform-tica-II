QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemigos.cpp \
    fisicas.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    niveles.cpp \
    peloton.cpp

HEADERS += \
    enemigos.h \
    fisicas.h \
    jugador.h \
    mainwindow.h \
    niveles.h \
    peloton.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sprite.qrc

DISTFILES += \
    Attack.png \
    Dead.png \
    Explosion.png \
    Fondo.jpg \
    Grenade.png \
    Hurt.png \
    Idle.png \
    Recharge.png \
    Run.png \
    Shot_1.png \
    Shot_2.png \
    Walk.png
