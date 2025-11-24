#ifndef JUGADOR_H
#define JUGADOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsView>


class posicion_jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    qreal x = 200;
    qreal y = 200;
    int spritex = 0;
    int spritey = 0;
    int sprite_ancho = 64;
    int sprite_alto = 64;
    QPixmap hojaSprite;
    QPixmap sprite;
    int cont = 0;
    int spritex_frame = 0;
    int delay = 0;
    QSize limites;

public:
    posicion_jugador(QGraphicsView *vista);
    void keyPressEvent(QKeyEvent *event) override;
    void movimiento(int dx, int dy);
    void confSprite(int dir, bool invertir = false);
};

class jugador:public QObject{
    Q_OBJECT
private:
    int vida = 100;
    int energia = 100;
    int experiencia = 0;
    int nivel = 1;
    
    posicion_jugador *posicion;
public:
    jugador(QGraphicsView *vista);
    
}

#endif // JUGADOR_H
