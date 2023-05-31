#include "headers/Brick.h"

Brick::Brick(Vector2 position, Vector2 size, Color color) 
    : rectangle({position.x, position.y, size.x, size.y}) {
    this->active = true;
    this->color = color;
}

Brick::~Brick() {};

void Brick::draw() {
    DrawRectangleRec(rectangle, color);
} 

void Brick::checkCollision(Ball &ball) {
    Vector2 checkBall = { ball.getPosition().x - ball.getRadius(), ball.getPosition().y - ball.getRadius() };
    checkBall.x += ball.getSpeed().x;
    checkBall.y += ball.getSpeed().y;

    if (CheckCollisionCircleRec(checkBall, ball.getRadius(), rectangle)) {
        this->active = false;
        ball.setSpeed({ ball.getSpeed().x, ball.getSpeed().y * -1 });        
    };
}

bool Brick::getActive() {
    return this->active;
}


void Brick::setColor(Color color) {
    this->color = color;
}

void Brick::update() {};