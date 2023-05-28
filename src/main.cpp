#include "headers/Ball.h"
#include "headers/Paddle.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Breakout");

    // Instanciando objetos
    Ball ball({screenWidth / 2 , screenHeight / 2 }, {3, 3}, 10, RED);
    Paddle paddle({screenWidth / 2 - 50, screenHeight - 20}, 100, 20, 4.5, BLUE);

    // FPS: 60
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        paddle.collisionWith(ball);
        ball.update();
        ball.draw();
        paddle.update();
        paddle.draw();

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}