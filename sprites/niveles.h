#ifndef NIVELES_H
#define NIVELES_H
#include <QObject>
#include <QGraphicsScene>
#include "jugador.h"

class niveles : public QObject {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    
    posicion_jugador *jugadorNivel;

public:
    niveles(QGraphicsScene *escena);
    
    void cargarNivel(int nivel);
    void cargarEscena(int escena);
    void cargarJugador(int escena);
    
    void cargarEnemigos(int escena);
    void cargarArmas(int escena);
    void cargarPeloton(int escena);
};

#endif // NIVELES_H
