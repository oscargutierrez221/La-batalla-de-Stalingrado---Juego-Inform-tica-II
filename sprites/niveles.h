#ifndef NIVELES_H
#define NIVELES_H
#include <QObject>
#include <QGraphicsScene>
#include <QString>


class niveles : public QObject {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    
public:
    niveles(QGraphicsScene *escena);
    void cargarNivel(int nivel);
    void cargarEscena(int escena);
    void cargarEnemigos(int escena);
    void cargarJugador(int escena);
    void cargarObjetos(int escena);
    void cargarPeloton(int escena);
};

#endif // NIVELES_H
