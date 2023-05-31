#include "headers/Ball.h"
#include "headers/Paddle.h"
#include "headers/Brick.h"


int main()
{
    const int ROWS = 5;
    const int COLUMNS = 20;
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    Brick *bricks[ROWS][COLUMNS];

    InitWindow(screenWidth, screenHeight, "Breakout");

    // Instanciando objetos
    Vector2 brickSize = {  screenWidth / COLUMNS , 40 };
    Ball ball({screenWidth / 2 , screenHeight / 2 }, {3.5, 3.5}, 10, RED);
    Paddle paddle({screenWidth / 2, screenHeight - 50 }, 100, 20, 4.5, BLUE);

    int initialDownPosition = 50;
    for (int i = 0; i < ROWS; i++) {
            for (int j =0; j < COLUMNS - 2; j++) {
                Vector2 positionBrick = { j*brickSize.x + brickSize.x, i*brickSize.y + initialDownPosition };
                bricks[i][j] = new Brick(positionBrick, brickSize, GREEN);
            }
    }

    // FPS: 60
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        for (int i = 0; i < ROWS; i++) {
            for (int j =0; j < COLUMNS - 2; j++) {
                if(bricks[i][j]->getActive()) {
                    if ((i + j) % 2 == 0) bricks[i][j]->setColor(BLUE);
                    bricks[i][j]->checkCollision(ball);
                    bricks[i][j]->draw();
                }
            }
        }

        paddle.collisionWith(ball);
        ball.draw();
        ball.update();
        paddle.update();
        paddle.draw();

        
        


        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}