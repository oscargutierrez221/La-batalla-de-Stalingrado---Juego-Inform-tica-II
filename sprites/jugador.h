#ifndef JUGADOR_H
#define JUGADOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>


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

public:
    posicion_jugador();
};

#endif // JUGADOR_H
