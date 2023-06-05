/*
CLASE: GameObject.
INTENCIÓN: Es la base para las demás clases
RELACIONES: Esta es la clase padre de (Brick, Ball, Padle)

*/
#include "raylib.h"
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
    protected:
        Color color;
    public:
        //Constructor. 
        GameObject();

        //Destructor.
        virtual ~GameObject();

        //Metodos virtuales puras, serán reescritas en los metodos de las clases derivadas.
        virtual void update() = 0;
        virtual void draw() = 0;
};


#endif