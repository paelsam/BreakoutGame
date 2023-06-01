#include "headers/Brick.h"
#include <iostream>
Brick::Brick(Vector2 position, Vector2 size, Color color)
    : rectangle({position.x, position.y, size.x, size.y})
{
    this->active = true;
    this->color = color;
}

Brick::~Brick(){};

void Brick::draw()
{
    DrawRectangleRec(rectangle, color);
}

void Brick::checkCollision(Ball &ball)
{
    // Vector2 checkBall = { ball.getPosition().x - ball.getRadius(), ball.getPosition().y - ball.getRadius() };
    // checkBall.x += ball.getSpeed().x;
    // checkBall.y += ball.getSpeed().y;

    // if (CheckCollisionCircleRec(checkBall, ball.getRadius(), rectangle)) {
    //     this->active = false;
    //     ball.setSpeed({ ball.getSpeed().x, ball.getSpeed().y * -1 });
    // };

    // Hit below
    if (((ball.getPosition().y - ball.getRadius()) <= (rectangle.y + rectangle.height / 2)) &&
        ((ball.getPosition().y - ball.getRadius()) > (rectangle.y + rectangle.height / 2 + ball.getSpeed().y)) &&
        ((std::abs(ball.getPosition().x - rectangle.x)) < (rectangle.width / 2 + ball.getRadius() * 2 / 3)) && (ball.getSpeed().y < 0))
    {
        active = false;
        ball.setSpeed({ball.getSpeed().x, -ball.getSpeed().y});
    }
    // Hit above
    else if (((ball.getPosition().y + ball.getRadius()) >= (rectangle.y - rectangle.height / 2)) &&
             ((ball.getPosition().y + ball.getRadius()) < (rectangle.y - rectangle.height / 2 + ball.getSpeed().y)) &&
             ((std::abs(ball.getPosition().x - rectangle.x)) < (rectangle.width / 2 + ball.getRadius() * 2 / 3)) && (ball.getSpeed().y > 0))
    {
        active = false;
        ball.setSpeed({ball.getSpeed().x, -ball.getSpeed().y});
    }
    // Hit left
    else if (((ball.getPosition().x + ball.getRadius()) >= (rectangle.x - rectangle.width / 2)) &&
             ((ball.getPosition().x + ball.getRadius()) < (rectangle.x - rectangle.width / 2 + ball.getSpeed().x)) &&
             ((std::abs(ball.getPosition().y - rectangle.y)) < (rectangle.height / 2 + ball.getRadius() * 2 / 3)) && (ball.getSpeed().x > 0))
    {
        active = false;
        ball.setSpeed({-ball.getSpeed().x, ball.getSpeed().y});
    }
    // Hit right
    else if (((ball.getPosition().x - ball.getRadius()) <= (rectangle.x + rectangle.width / 2)) &&
             ((ball.getPosition().x - ball.getRadius()) > (rectangle.x + rectangle.width / 2 + ball.getSpeed().x)) &&
             ((std::abs(ball.getPosition().y - rectangle.y)) < (rectangle.height / 2 + ball.getRadius() * 2 / 3)) && (ball.getSpeed().x < 0))
    {
        active = false;
        ball.setSpeed({-ball.getSpeed().x, ball.getSpeed().y});
    }
}

bool Brick::getActive()
{
    return this->active;
}

void Brick::setColor(Color color)
{
    this->color = color;
}

void Brick::update(){};