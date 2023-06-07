/*
CLASE: Ball
INTENCIÓN: Representa la pelota que rebota por el escenario y destruye los ladrillos 
RELACIÓN: Es parecido / hereda de la clase GameObject
*/

#include "GameObject.h"
#ifndef BALL_H
#define BALL_H

class Ball : public GameObject {
    private:
        Vector2 position;
        Vector2 speed;
        float radius;
        Color color;
        bool downCollition;
        Sound sonido;
        int brickCollitons;
        
    public: 
    
        //Constructor.
        Ball(Vector2 position, Vector2 speed, float radius, Color color);

        //Actualiza los atributos de la pelota, como su posición y colisiones.
        void update();

        //Dibuja la pelota cen pantalla.
        void draw();

        //Hace que la pelota rebote.
        void bounce();

        //Retorna la posición de la pelota.
        Vector2 getPosition();

        //Retorna la rapidez de la pelota.
        Vector2 getSpeed();

        //Retorna el radio de la pelota.
        float getRadius();

        //Dice si la pelota colisionó con la parte inferior de la pantalla.
        bool getDownCollition();

        //Permite asignarle un valor al atributo posición(position)
        void setPosition(Vector2 position);

        //Permite asignarle un valor al atributo rapidez(speed)
        void setSpeed(Vector2 speed);

        int getBrickCollitions();

        void setBrickCollitons(int brickCollitions);

};


#endif