/*
CLASE: Brick
INTENCIÓN: Representa el ladrillo que deberá romper la pelota.
RELACIONES: 
- Es parecido/ hereda de GameObject.
- Conoce a Ball.
*/
#include "GameObject.h"
#include "Ball.h"
#ifndef BRICK_H
#define BRICK_H

class Brick : public GameObject {
    private: 
        Rectangle rectangle;
        Color color;
        bool active;
        Sound sonido;
      

        //! Durability - TBA 
    public: 
        //Constructor.
        Brick(Vector2 position, Vector2 size, Color color);

        //Destructor.
        ~Brick();

        //Actualiza el estado del ladrillo.
        void update();

        //Dibuja el ladrillo en pantalla.
        void draw();

        //Se encarga de las colisiones del ladrillo con la pelota.
        void collisionWith(Ball &ball);

        //Dice si el ladriilo está activo dentro del juego.
        bool getActive();

        //Permite asignarle un color al ladrillo
        void setColor(Color color);

        // Cambiar el valor de la variable active
        void setActive(bool active);

     

};


#endif
