#ifndef PELOTON_H
#define PELOTON_H

#include "jugador.h"
#include <QTimer>

class Peloton : public posicion_jugador
{
    Q_OBJECT
public:
    Peloton(QGraphicsView *vista);
    
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

#endif // PELOTON_H
