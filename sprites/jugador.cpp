#include "jugador.h"

posicion_jugador::posicion_jugador()
{
    x = 200;
    y = 200;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprite.load(":/recursos/Walk.png");
    // sprite = hojaSprite.copy(spritex, spritey, sprite_ancho, sprite_alto);
    sprite = hojaSprite;
    setPixmap(sprite);
}
