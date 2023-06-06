#include "headers/Ball.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius, Color color) {
    this->position = position;
    this->speed = speed;
    this->radius = radius;
    this->color = color;
    this->brickCollitons=0;
    // Sonido cuando colisiona con el paddle
    this->sonido = LoadSound("src/assets/music/Pop.ogg");
};

void Ball::update() {
    // Actualizar la posición de la pelota en función de la velocidad
    position.x += speed.x;
    position.y += speed.y;

    // Rebotar la pelota cuando alcanza los límites de la pantalla
    if (((position.x + radius) >= GetScreenWidth()) || ((position.x - radius) <= 0)) {
        speed.x *= -1;
        PlaySound(sonido);
    }
    if ((position.y - radius) <= 0) {
        speed.y *= -1;
        PlaySound(sonido);
    }
    if ((position.y + radius) >= GetScreenHeight()) { 
        PlaySound(sonido);
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

Vector2 Ball::getSpeed() {
    return this->speed;
}

float Ball::getRadius() {
    return this->radius;
}

bool Ball::getDownCollition(){
    return downCollition;
}

void Ball::setPosition(Vector2 position) {
    this->position = position;
}

void Ball::setSpeed(Vector2 speed) {
    this->speed = speed;
}

int Ball::getBrickCollitions(){
    return this->brickCollitons;
}

void Ball::setBrickCollitons(int brickCollitons){
        this->brickCollitons=brickCollitons;
}

