#include "headers/Ball.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius, Color color) {
    this->position = position;
    this->speed = speed;
    this->radius = radius;
    this->color = color;
    this->life=3;
};

void Ball::update() {
    // Actualizar la posición de la pelota en función de la velocidad
    position.x += speed.x;
    position.y += speed.y;

    // Rebotar la pelota cuando alcanza los límites de la pantalla
    if (((position.x + radius) >= GetScreenWidth()) || ((position.x - radius) <= 0)) speed.x *= -1;
    if ((position.y - radius) <= 0) speed.y *= -1;
    if ((position.y + radius) >= GetScreenHeight()) { 
        position.x = GetScreenWidth() / 2;
        position.y = GetScreenHeight() / 2;
        int speed_choices[2]={1,-1};
        speed.x *= speed_choices[GetRandomValue(0,1)];
        life--;
        
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

bool Ball::getDownCollition(){
    return downCollition;
}

int Ball::getLife(){
    return life;
}

void Ball::setLife(int life){
    this->life=life;
}
// void Ball::setDownCollition(bool downCollition){
//     this->downCollition = downCollition;
// }