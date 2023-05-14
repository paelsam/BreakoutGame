#include "headers/Ball.h"
#include "raylib.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius, Color color)
{
    this->position = position;
    this->speed = speed;
    this->radius = radius;
    this->color = color;
}

void Ball::move()
{
    // Obtener el tamaño de la pantalla
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // Comprobar si la pelota está a punto de salir de la pantalla
    if (position.x - radius < 0 || position.x + radius > screenWidth)
        speed.x = -speed.x;
    if (position.y - radius < 0 || position.y + radius > screenHeight)
        speed.y = -speed.y;

    // Actualizar la posición de la pelota
    position.x += speed.x;
    position.y += speed.y;
}

void Ball::draw() {
    DrawCircleV(position, radius, color);
}

float Ball::getRadius() {
    return this->radius;
}

Vector2 Ball::getPosition() {
    return this->position;
}

Vector2 Ball::getSpeed() {
    return this->speed;
}

void Ball::setSpeed(Vector2 speed) {
    this->speed = speed;
}

Rectangle Ball::getRect() {
    return { position.x - radius, position.y - radius, radius * 2.0f, radius * 2.0f };
}
