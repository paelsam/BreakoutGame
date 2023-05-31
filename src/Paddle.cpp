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
    Vector2 checkBall = { ball.getPosition().x - ball.getRadius(), ball.getPosition().y - ball.getRadius() };
    checkBall.x += ball.getSpeed().x;
    checkBall.y += ball.getSpeed().y;

    // Verificar colisión entre la paleta y la pelota
    if (CheckCollisionCircleRec(checkBall, ball.getRadius(), rectangle)) {
        ball.setSpeed({ -ball.getSpeed().x, -ball.getSpeed().y });
        std::cout << "Actual Position: " << ball.getPosition().x << ", " << ball.getPosition().y << std::endl;
        std::cout << "Predit: " << checkBall.x << ", " << checkBall.y << std::endl;
    } else {
        ball.setSpeed({ ball.getSpeed().x, ball.getSpeed().y });
    }
}