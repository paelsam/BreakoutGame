// #include "headers/Ball.h"
// #include "headers/Paddle.h"
// #include "headers/Brick.h"
// #include <iostream>
// #include <raylib.h>

// // void gameOver(){
// //     int screenWidth=600;
// //     int screenHeight=450;

// //         InitWindow(screenWidth,screenHeight,"gameover");
// //         SetTargetFPS(60);
// //         while(!WindowShouldClose()){
// //             BeginDrawing();
// //             ClearBackground(BLACK);
// //             DrawText(TextFormat("GAME OVER"),GetScreenWidth()-20, 10, 20, GREEN);
// //             EndDrawing();

// //         }
// //         CloseWindow();

// //     }

// void drawGame(int ROWS, int COLUMNS, Brick *bricks[4][20], Ball ball, Paddle paddle)
// {
//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(BLACK);

//         if (ball.getLife() > 0)
//         {
//             for (int i = 0; i < ROWS; i++)
//             {
//                 for (int j = 0; j < COLUMNS - 2; j++)
//                 {
//                     if (bricks[i][j]->getActive())
//                     {
//                         if ((i + j) % 2 == 0)
//                             bricks[i][j]->setColor(BLUE);
//                         bricks[i][j]->collisionWith(ball);
//                         bricks[i][j]->draw();
//                     }
//                 }
//             }

//             paddle.collisionWith(ball);
//             ball.draw();
//             ball.update();
//             paddle.update();
//             paddle.draw();

//             DrawText(TextFormat("Puntos: %i", int(GetTime())), 10, 10, 20, GREEN);

//             if (ball.getLife() >= 0)
//             {
//                 DrawText(TextFormat("Vidas: %i", ball.getLife()), GetScreenWidth() - 100, 10, 20, GREEN);
//             }
//         }
//         else
//         {
//             char gameOverText[34] = "GAME OVER\nPress ENTER to continue";
//             Vector2 textSize = MeasureTextEx(GetFontDefault(), gameOverText, 20, 0);
//             DrawText(gameOverText, GetScreenWidth() / 2  - textSize.x / 2, GetScreenHeight() / 2 - textSize.y / 2, 20, GREEN);
//             if (IsKeyDown(KEY_ENTER))
//             {
//                 ball.setLife(3);
//             }
//         }

//         EndDrawing();
//     }
//     CloseWindow();
// }

// int main()
// {

//     const int screenWidth = 800;
//     const int screenHeight = 600;
//     const int ROWS = 4;
//     const int COLUMNS = 20;
//     // int life=10;

//     Brick *bricks[ROWS][COLUMNS];
//     InitWindow(screenWidth, screenHeight, "Breakout");

//     Vector2 brickSize = {screenWidth / COLUMNS, 40};
//     Ball ball({screenWidth / 2, screenHeight / 2}, {3.5, 3.5}, 10, RED);
//     Paddle paddle({screenWidth / 2, screenHeight - 50}, 100, 20, 4.5, BLUE);

//     int initialDownPosition = 50;
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLUMNS - 2; j++)
//         {
//             Vector2 positionBrick = {j * brickSize.x + brickSize.x, i * brickSize.y + initialDownPosition};
//             bricks[i][j] = new Brick(positionBrick, brickSize, GREEN);
//         }
//     }

//     // FPS: 60
//     SetTargetFPS(60);

//     drawGame(ROWS, COLUMNS, bricks, ball, paddle);

//     return 0;
// }
