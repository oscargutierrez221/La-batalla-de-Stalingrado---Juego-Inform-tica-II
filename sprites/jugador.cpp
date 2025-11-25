#include "jugador.h"
#include <QKeyEvent>
#include <QGraphicsScene>

posicion_jugador::posicion_jugador(QGraphicsView *vista)
{
    x = 200;
    y = 200;
    view = vista;
    
    setFlag(QGraphicsItem::ItemIsFocusable);

    if(hojaSprite.load(":/recursos/Recharge.png")){
        spritey = 0;
        sprite_alto = hojaSprite.height();
        if (sprite_alto > 0) {
            numFrames = hojaSprite.width() / sprite_alto;
            sprite_ancho = hojaSprite.width() / numFrames;
        }
        sprite = hojaSprite.copy(spritex, spritey, sprite_ancho, sprite_alto);
        setPixmap(sprite);
    }
    
    timerAnimacion = new QTimer(this);
    connect(timerAnimacion, &QTimer::timeout, this, &posicion_jugador::actualizarAnimacion);
    timerAnimacion->start(50);
    
    if (view->scene()) {
        view->scene()->installEventFilter(this);
    }
}

void posicion_jugador::cambiarSprite(const QString &rutaSprite){
    QPixmap nuevoSprite;
    if(nuevoSprite.load(rutaSprite)){
        hojaSprite = nuevoSprite;
        
        cont = 0;
        spritex = 0;
        delay = 0;
        
        sprite_alto = hojaSprite.height();
        if (sprite_alto > 0) {
            numFrames = hojaSprite.width() / sprite_alto;
            sprite_ancho = hojaSprite.width() / numFrames;
        }
        
        sprite = hojaSprite.copy(spritex, spritey, sprite_ancho, sprite_alto);
        setPixmap(sprite);
    }
}

bool posicion_jugador::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            cambiarSprite(":/recursos/Shot_1.png");
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

void posicion_jugador::actualizarAnimacion() {
    confSprite(spritey); 
}

void posicion_jugador::keyPressEvent(QKeyEvent *event){
    bool shiftPresionado = event->modifiers() & Qt::ShiftModifier;
    int velocidad = shiftPresionado ? 10 : 5;
    
    if(event->key() == Qt::Key_W) teclaW = true;
    if(event->key() == Qt::Key_A) teclaA = true;
    if(event->key() == Qt::Key_S) teclaS = true;
    if(event->key() == Qt::Key_D) teclaD = true;
    
    if (teclaW || teclaA || teclaS || teclaD) {
        if (shiftPresionado && !estaCorriendo) {
            cambiarSprite(":/recursos/Run.png");
            estaCorriendo = true;
        } else if (!shiftPresionado) {
            if (estaCorriendo) {
                cambiarSprite(":/recursos/Walk.png");
                estaCorriendo = false;
            } else if (hojaSprite.width() != 896) {
                 cambiarSprite(":/recursos/Walk.png");
            }
        }
    }
    
    switch(event->key()){
        case Qt::Key_D:
            movimiento(velocidad, 0);
            spritey = 0;
            break;
        case Qt::Key_A:
            movimiento(-velocidad, 0);
            spritey = 0; 
            break;
        case Qt::Key_W:
            movimiento(0, -velocidad);
            spritey = 0;
            break;
        case Qt::Key_S:
            movimiento(0, velocidad);
            spritey = 0;
            break;
        default:
            QGraphicsPixmapItem::keyPressEvent(event);
            break;
    }
}

void posicion_jugador::keyReleaseEvent(QKeyEvent *event){
    if (event->isAutoRepeat()) return;
    
    if(event->key() == Qt::Key_W) teclaW = false;
    if(event->key() == Qt::Key_A) teclaA = false;
    if(event->key() == Qt::Key_S) teclaS = false;
    if(event->key() == Qt::Key_D) teclaD = false;
    
    if (event->key() == Qt::Key_Shift && estaCorriendo) {
        cambiarSprite(":/recursos/Walk.png");
        estaCorriendo = false;
    }
    
    if (!teclaW && !teclaA && !teclaS && !teclaD) {
        cambiarSprite(":/recursos/Recharge.png");
    }
    
    QGraphicsPixmapItem::keyReleaseEvent(event);
}


void posicion_jugador::movimiento(int dx, int dy){
    x += dx;
    y += dy;
    
    QRectF sceneRect = scene()->sceneRect();
    if (x < 0) x = 0;
    if (x > sceneRect.width() - sprite_ancho) x = sceneRect.width() - sprite_ancho;
    
    int suelo = 800;
    if (y < suelo - 180) y = suelo - 180;
    if (y > suelo) y = suelo;
    
    setPos(x, y);
    view->centerOn(this);
}

void posicion_jugador::confSprite(int dir, bool invertir){
    spritex_frame = cont;
    spritex = spritex_frame * sprite_ancho;
    
    if (spritex >= hojaSprite.width()) {
        cont = 0;
        spritex_frame = 0;
        spritex = 0;
    }

    if (spritex + sprite_ancho <= hojaSprite.width() && 
        spritey + sprite_alto <= hojaSprite.height()) {
        
        sprite = hojaSprite.copy(spritex, spritey, sprite_ancho, sprite_alto);
        if (invertir) {
            sprite = sprite.transformed(QTransform().scale(-1, 1));
        }
        setPixmap(sprite);
    }
    
    delay++;
    if (delay >= 4) {
        cont++;
        delay = 0;
    }
    if(cont >= numFrames){
        cont = 0;
    }
}
