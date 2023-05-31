#include "headers/Ball.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius, Color color) {
    this->position = position;
    this->speed = speed;
    this->radius = radius;
    this->color = color;
};

void Ball::update() {
    // Actualizar la posición de la pelota en función de la velocidad
    position.x += speed.x;
    position.y += speed.y;

    // Rebotar la pelota cuando alcanza los límites de la pantalla
    if (position.x < 0 || position.x + radius > GetScreenWidth()) {
        speed.x = -speed.x;
    }
    if (position.y < 0 || position.y + radius > GetScreenHeight()) {
        speed.y = -speed.y;
    }
}

void Ball::draw() {
    DrawCircleV(position, radius, color);
}

void Ball::bounce() {
    speed.y *= -1;
}

Vector2 Ball::getPosition() {
    return this->position;
}

float Ball::getRadius() {
    return this->radius;
}

Vector2 Ball::getSpeed() {
    return this->speed;
}

void Ball::setPosition(Vector2 position) {
    this->position = position;
}

void Ball::setSpeed(Vector2 speed) {
    this->speed = speed;
}