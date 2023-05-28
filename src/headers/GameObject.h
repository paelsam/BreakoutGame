#include "raylib.h"
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
    protected:
        Color color;
    public:
        GameObject();
        virtual ~GameObject();
        virtual void update() = 0;
        virtual void draw() = 0;
};


#endif