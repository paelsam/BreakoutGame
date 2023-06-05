/*
CLASE: GameObject
INTENCIÓN: Representa el objeto más básico del juego.
RELACIONES: Es la clase base/padre de las clases ball, brick y paddle.
*/

#include "raylib.h"
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
    protected:
        Color color;
    public:
        //Constructor
        GameObject();

        //Destructor
        virtual ~GameObject();

        //Funciones virtuales puras, serán sobreescritas en los metodos de las clases derivadas.
        virtual void update() = 0;
        virtual void draw() = 0;
};


#endif