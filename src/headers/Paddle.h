#include "raylib.h"
#include "Ball.h"
#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
private:
    Vector2 position;
    float width;
    float height;
    float speed;
    Color color;

public:
    Paddle(Vector2 position, float width, float height, float speed, Color color);
    void draw();
    void moveLeft();
    void moveRight();
    Rectangle getRect();
    bool collidesWith(Ball ball);
    Vector2 getPosition();
    float getWidth();
};

#endif