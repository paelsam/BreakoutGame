#include "GameObject.h"
#include "Ball.h"
#ifndef BRICK_H
#define BRICK_H

class Brick : public GameObject {
    private: 
        Rectangle rectangle;
        Color color;
        bool active;
        //! Durability
    public: 
        Brick(Vector2 position, Vector2 size, Color color);
        ~Brick();
        void checkCollision(Ball &ball);
        void draw();
        void update();
        Vector2 getPosition();
        Vector2 getSize();
        void setColor(Color color);
        bool getActive();
        void setActive(bool active);

};


#endif
