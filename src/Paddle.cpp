#include <iostream>
#include "headers/Paddle.h"

Paddle::Paddle(Vector2 position, float width, float height, float speed, Color color) 
    : rectangle({position.x, position.y, width, height}), speed(speed), color(color) {};

void Paddle::update() {
    // Mover la paleta hacia la izquierda
    if (IsKeyDown(KEY_LEFT)) {
        if (!(rectangle.x < 0))
            rectangle.x -= speed;
    }

    // Mover la paleta hacia la derecha
    if (IsKeyDown(KEY_RIGHT)) {
        if (!(rectangle.x + rectangle.width > GetScreenWidth()))
            rectangle.x += speed;
    }
};

void Paddle::draw() {
    DrawRectangleRec(rectangle, color);
}

void Paddle::collisionWith(Ball &ball) {
    // Sides of rectangle
    int left = rectangle.x;
    int right = rectangle.x + rectangle.width;
    int top = rectangle.y; 
    int bottom = rectangle.y + rectangle.height;

    // Previus position ball
    int px = ball.getPosition().x - ball.getSpeed().x;
    int py = ball.getPosition().y - ball.getSpeed().y;

    if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(), rectangle)) {
        if( px < left ) {
            if ( ball.getSpeed().x > 0 )
                ball.setSpeed({ -ball.getSpeed().x, ball.getSpeed().y });
            ball.setPosition({ left - ball.getRadius(), ball.getPosition().y });
        }
        else if( px > right ) {
            if ( ball.getSpeed().x < 0)
                ball.setSpeed({ -ball.getSpeed().x, ball.getSpeed().y });
            ball.setPosition({ right + ball.getRadius(), ball.getPosition().y });
        }
        else if ( py < top ) {
            if ( ball.getSpeed().y > 0)
                ball.setSpeed({ ball.getSpeed().x, -ball.getSpeed().y });
            ball.setPosition({ ball.getPosition().x, top - ball.getRadius() });
        }
        else if ( py > bottom ) {
            if ( ball.getSpeed().y < 0 )
                ball.setSpeed({ ball.getSpeed().x, -ball.getSpeed().y });
            ball.setPosition({ ball.getPosition().x, bottom + ball.getRadius() });
        }
    }
}