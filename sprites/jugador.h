#ifndef JUGADOR_H
#define JUGADOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

class posicion_jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    qreal x;
    qreal y;
    bool estaCorriendo = false;
    
    bool teclaW = false;
    bool teclaA = false;
    bool teclaS = false;
    bool teclaD = false;
    
    QPixmap hojaSprite;
    QPixmap sprite;
    int sprite_ancho;
    int sprite_alto;
    
    int spritex = 0;
    int spritey = 0;
    int cont = 0;
    int spritex_frame = 0;
    int delay = 0;
    int numFrames = 0;
    
    QGraphicsView *view;
    QSize limites;
    QTimer *timerAnimacion;

public:
    posicion_jugador(QGraphicsView *vista);
    
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    
    bool eventFilter(QObject *obj, QEvent *event) override;
    
    void movimiento(int dx, int dy);
    void confSprite(int dir, bool invertir = false);
    void cambiarSprite(const QString &rutaSprite);
    
public slots:
    void actualizarAnimacion();
};

#endif // JUGADOR_H
