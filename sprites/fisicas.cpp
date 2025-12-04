#include "fisicas.h"

Fisicas::Fisicas() {
    vx = 0;
    vy = 0;
    gravedad = 2;
    rebotes = 0;
}

void Fisicas::aplicarGravedad() {
    vy = vy + gravedad;
}

void Fisicas::moverX(float &posX) {
    posX = posX + vx;
}

void Fisicas::moverY(float &posY) {
    posY = posY + vy;
}

bool Fisicas::rebotarEnBordes(float posX, float posY, int anchoMundo, int altoMundo) {
    bool reboto = false;
    
    if(posX < 0 || posX > anchoMundo) {
        vx = -vx;
        rebotes++;
        reboto = true;
    }
    
    if(posY < 0 || posY > altoMundo) {
        vy = -vy;
        rebotes++;
        reboto = true;
    }
    
    return reboto;
}

void Fisicas::rebotarX() {
    vx = -vx * 0.8;
    rebotes++;
}

void Fisicas::rebotarY() {
    vy = -vy * 0.8;
    rebotes++;
}
