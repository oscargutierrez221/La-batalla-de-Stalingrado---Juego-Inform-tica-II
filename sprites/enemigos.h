#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "jugador.h"
#include <QTimer>

class Enemigos : public posicion_jugador
{
    Q_OBJECT
public:
    Enemigos(QGraphicsView *vista);
    
    int vida;
    bool estaVivo;
    
    void moverAutomatico();
    void dispararAutomatico();
    void recibirDanio(int danio);
    
private:
    QTimer *timerMovimiento;
    int direccion;
    int contadorMovimiento;
    
private slots:
    void actualizarBot();
};

#endif // ENEMIGOS_H
