/*
CLASE: Paddle
INTENCIÓN: Es la plataforma manejada por el jugador, 
no permite que la pelota caiga por el escenario haciendo que rebote.
RELACIONES:
    -Es parecido/ hereda de GameObject.
    -Conoce a Ball.
*/
#include "Ball.h"
#ifndef PADDLE_H
#define PADDLE_H

class Paddle : public GameObject {
    private: 
        Rectangle rectangle; 
        float speed;
        Color color; 
        Sound sonido;
    public:
        //Constructor
        Paddle(Vector2 position, float width, float height, float speed, Color color);

        //Actualiza la posición de la plataforma.
        void update();

        //Dibuja la plataforma en pantalla.
        void draw();

        //Se encarga de las colisiones de la plataforma con la pelota.
        void collisionWith(Ball &ball);
        
};


#endif