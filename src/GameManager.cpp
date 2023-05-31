#include "headers/GameManager.h"


GameManager::Gamemanager(){
    int score=0;
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
    

}

GameManager::draw(){
    BeginDrawing();
    ClearBackground(WHITE);
    ball.draw();
    paddle.draw();

    for (int i = 0; i < ROWS; i++) {
        for (int j =0; j < COLUMNS - 2; j++) {
            if(bricks[i][j]->getActive()) {
                if ((i + j) % 2 == 0) bricks[i][j]->setColor(BLUE);
                bricks[i][j]->draw();
            }
        }
    }

    DrawFPS(10, 10);

    EndDrawing();

}

GameManager::updateGame(){

for (int i = 0; i < ROWS; i++) {
    for (int j =0; j < COLUMNS - 2; j++) {
        if(bricks[i][j]->getActive()) {
            bricks[i][j]->checkCollision(ball);
            
        }
    }
}
paddle.collisionWith(ball);
ball.update();
paddle.update();

}
