#include "niveles.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>

niveles::niveles(QGraphicsScene *escena) {
    scene = escena;
    jugadorNivel = nullptr;
}

void niveles::cargarNivel(int nivel) {
    QPixmap fondo(":/recursos/Fondo.jpg");
    if (!fondo.isNull()) {
        int numRepeticiones = 5;
        for (int i = 0; i < numRepeticiones; i++) {
            QGraphicsPixmapItem *fondoItem = new QGraphicsPixmapItem(fondo);
            fondoItem->setPos(i * fondo.width(), 0);
            fondoItem->setZValue(-1); 
            scene->addItem(fondoItem);
        }
        scene->setSceneRect(0, 0, fondo.width() * numRepeticiones, fondo.height());
    }
}

void niveles::cargarJugador(int escena){
    if (!scene->views().isEmpty()) {
        jugadorNivel = new posicion_jugador(scene->views().first());
        scene->addItem(jugadorNivel);
        jugadorNivel->setPos(100, 500); 
        jugadorNivel->setFocus(); 
    }
}

void niveles::cargarEscena(int escena){
    cargarNivel(escena);
    cargarJugador(escena);
}

void niveles::cargarEnemigos(int escena) {}
void niveles::cargarArmas(int escena) {}
void niveles::cargarPeloton(int escena) {}
