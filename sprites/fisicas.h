#ifndef FISICAS_H
#define FISICAS_H

class Fisicas
{
public:
    Fisicas();
    
    float vx;  
    float vy; 
    float gravedad;
    int rebotes;
    
    void aplicarGravedad();
    void moverX(float &posX);
    void moverY(float &posY);
    bool rebotarEnBordes(float posX, float posY, int anchoMundo, int altoMundo);
    void rebotarX();
    void rebotarY();
};

#endif // FISICAS_H
