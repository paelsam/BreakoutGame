#include "headers/Paddle.h"

Paddle::Paddle(Vector2 position, float width, float height, float speed, Color color){
    this->position = position;
    this->width = width;
    this->height = height;
    this->speed = speed;
    this->color = color;
}

void Paddle::draw() {
    DrawRectangleRec({ position.x - width / 2, position.y - height / 2, width, height }, color);
}

void Paddle::moveLeft() {
    position.x -= speed;
}

void Paddle::moveRight() {
    position.x += speed;
}

Rectangle Paddle::getRect() {
    return { position.x - width / 2, position.y - height / 2, width, height };
}

bool Paddle::collidesWith(Ball ball) {
    return CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(), getRect());
}

Vector2 Paddle::getPosition() {
    return this->position;
}

float Paddle::getWidth() {
    return this->width;
}