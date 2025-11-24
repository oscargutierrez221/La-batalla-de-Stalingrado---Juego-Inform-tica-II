#include "jugador.h"
#include <QKeyEvent>

posicion_jugador::posicion_jugador(QGraphicsView *vista)
{
    x = 200;
    y = 200;
    limites = vista->size();
    setFlag(QGraphicsItem::ItemIsFocusable);
    if(hojaSprite.load(":/recursos/Walk.png")){
        spritey = 65;
        sprite_ancho = 80;
        sprite_alto = 80;
        
        sprite = hojaSprite.copy(spritex, spritey, sprite_ancho, sprite_alto);
        setPixmap(sprite);
    }
}

void posicion_jugador::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_D:
            movimiento(5,0);
            confSprite(65, false); // Normal (mirando a la derecha)
            break;
        case Qt::Key_A:
            movimiento(-5,0);
            confSprite(65, true); // Invertido (mirando a la izquierda)
            break;
        case Qt::Key_W:
            movimiento(0,-5);
            confSprite(65); 
            break;
        case Qt::Key_S:
            movimiento(0,5);
            confSprite(65); 
            break;
        default:
            QGraphicsPixmapItem::keyPressEvent(event);
            break;
    }
}

void posicion_jugador::movimiento(int dx, int dy){
    if (x + dx < 0 || x + dx > limites.width() - sprite_ancho) {
        return;
    }
    if (y + dy < 0 || y + dy > limites.height() - sprite_alto) {
        return;
    }
    else{
        x += dx;
        y += dy;
        setPos(x,y);
    }
}

void posicion_jugador::confSprite(int dir, bool invertir){
    spritey = dir;
    spritex_frame = cont;
    int ancho_casilla = 256; 
    spritex = spritex_frame * ancho_casilla;
    
    if (spritex >= hojaSprite.width()) {
        cont = 0;
        spritex = 0;
    }

    sprite = hojaSprite.copy(spritex, spritey, sprite_ancho, sprite_alto);
    
    // Si invertir es true, volteamos la imagen horizontalmente
    if (invertir) {
        sprite = sprite.transformed(QTransform().scale(-1, 1));
    }
    
    setPixmap(sprite);    
    delay++;
    if (delay >= 4) {
        cont++;
        delay = 0;
    }
    
    if(cont >= 5){
        cont = 0;
    }
}
