#include "enemigos.h"
#include <QRandomGenerator>

Enemigos::Enemigos(QGraphicsView *vista) : posicion_jugador(vista)
{
    vida = 100;
    estaVivo = true;
    direccion = -1; 
    contadorMovimiento = 0;
    
    cambiarSprite(":/recursos/Idle.png");
    
    setPos(700, 450);
    
    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Enemigos::actualizarBot);
    timerMovimiento->start(50); 
}

void Enemigos::actualizarBot()
{
    if(!estaVivo) {
        timerMovimiento->stop();
        return;
    }
    
    moverAutomatico();
    
    contadorMovimiento++;
    if(contadorMovimiento > 60) { 
        dispararAutomatico();
        contadorMovimiento = 0;
    }
}

void Enemigos::moverAutomatico()
{
    int dx = direccion * 2;
    movimiento(dx, 0);
    
    if(QRandomGenerator::global()->bounded(100) < 5) {
        direccion = -direccion;
    }
}

void Enemigos::dispararAutomatico()
{
}

void Enemigos::recibirDanio(int danio)
{
    vida = vida - danio;
    if(vida <= 0) {
        vida = 0;
        estaVivo = false;
        cambiarSprite(":/recursos/Dead.png");
    }
}
