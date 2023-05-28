#include "Ball.h"
#ifndef PADDLE_H
#define PADDLE_H

class Paddle : public GameObject {
    private: 
        Rectangle rectangle; 
        float speed;
        Color color; 
    public:
        Paddle(Vector2 position, float width, float height, float speed, Color color);
        void update();
        void draw();
        void collisionWith(Ball &ball);
        
};


#endif