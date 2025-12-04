#include "peloton.h"
#include <QRandomGenerator>

Peloton::Peloton(QGraphicsView *vista) : posicion_jugador(vista)
{
    vida = 100;
    estaVivo = true;
    direccion = 1; 
    contadorMovimiento = 0;
    
    cambiarSprite(":/recursos/Idle.png");
    
    setPos(100, 450);
    
    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Peloton::actualizarBot);
    timerMovimiento->start(50); 
}

void Peloton::actualizarBot()
{
    if(!estaVivo) {
        timerMovimiento->stop();
        return;
    }
    
    moverAutomatico();
    
    contadorMovimiento++;
    if(contadorMovimiento > 80) { 
        dispararAutomatico();
        contadorMovimiento = 0;
    }
}

void Peloton::moverAutomatico()
{
    int dx = direccion * 3;
    movimiento(dx, 0);
    
    if(QRandomGenerator::global()->bounded(100) < 3) {
        direccion = -direccion;
    }
}

void Peloton::dispararAutomatico()
{
    // Aun no la implementare, lo hare luego
}

void Peloton::recibirDanio(int danio)
{
    vida = vida - danio;
    if(vida <= 0) {
        vida = 0;
        estaVivo = false;
        cambiarSprite(":/recursos/Dead.png");
    }
}
