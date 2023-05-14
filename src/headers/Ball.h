/*
CLASE: Ball
INTENCIÓN: Objeto que rebota sobre el paddle, los lados del tablero y los
ladrillos. ademas al pegar en los ladrillos los elimina del tablero y se anota
un punto al score del jugador.
RELACIONES: -Conoce a Brick
*/

#include "raylib.h"
#ifndef BALL_H
#define BALL_H

class Ball{
private:
    Vector2 position; // Posición de la pelota
    Vector2 speed;    // Velocidad de la pelota
    float radius;     // Radio de la pelota
    Color color;      // Color de la pelota
public:
    Ball(Vector2 position, Vector2 speed, float radius, Color color);
    void move();
    void draw();

    Vector2 getPosition();
    void setPosition(Vector2 position);
    Vector2 getSpeed();
    void setSpeed(Vector2 speed);
    float getRadius();
    void setRadius(float radius);
    Rectangle getRect();
};

#endif
