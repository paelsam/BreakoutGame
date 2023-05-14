#include "headers/Ball.h"
#include "headers/Paddle.h"
#include <raylib.h>


int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;

    Ball ball(Vector2{400, 300}, Vector2{ 2.5f, 2.5f }, 10.0f, RED);
    Paddle paddle(Vector2{screenWidth / 2, screenHeight - 20}, 100.0f, 20.0f, 3.0f, BLUE );


    InitWindow(screenWidth, screenHeight, "Breakout Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            ClearBackground(BLACK);
            if (paddle.collidesWith(ball)) {
                ball.setSpeed(Vector2{ball.getSpeed().x, -ball.getSpeed().y});
            }
            
            // if (CheckCollisionRecs(ball.getRect(), paddle.getRect())) {
            //     ball.setSpeed(Vector2{ball.getSpeed().x, -ball.getSpeed().y});
            // }

            // Drawing
            ball.draw();
            ball.move();
            paddle.draw();
            
            // Paddle input
            if (IsKeyDown(KEY_RIGHT)) {
                if (!(paddle.getPosition().x + paddle.getWidth() / 2 >= screenWidth))
                    paddle.moveRight();
            }
            if (IsKeyDown(KEY_LEFT)) {
                if (!(paddle.getPosition().x - paddle.getWidth() / 2 <= 0))
                    paddle.moveLeft();
            };

        EndDrawing();
    }

    CloseWindow();
    return 0;
}