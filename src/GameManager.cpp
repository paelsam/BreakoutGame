#include "headers/GameManager.h"
#include <iostream>

GameManager::GameManager(int screenWidth, int screenHeight) : 
    screenWidth(screenWidth),
    screenHeight(screenHeight),
    ball((Vector2){ static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 }, (Vector2){3.5, 3.5}, 10, DARKPURPLE ),
    paddle((Vector2){ static_cast<float>(screenWidth) / 2 - 50, static_cast<float>(screenHeight) - 50}, 100, 20, 4.5, DARKGRAY),
    bricksRows(4),
    bricksColums(20),
    lives(3)
{

    this->score = 0;
    // Bricks initialization
    int initialDownPosition = 80;
    Vector2 brickSize = { screenWidth / bricksColums, 40};

    for (int i = 0; i < bricksRows; i++) {
        std::vector<Brick> rowBricks;
        for (int j = 0; j < bricksColums - 2; j++) {
            Vector2 positionBrick = {j * brickSize.x + brickSize.x, i * brickSize.y + initialDownPosition};
            if ((i + j) % 2 == 0)
                rowBricks.push_back(*(new Brick(positionBrick, brickSize, DARKGREEN)));
            else
                rowBricks.push_back(*(new Brick(positionBrick, brickSize, DARKBLUE)));
        }
        bricks.push_back(rowBricks);
    }
}

void GameManager::updateGame() {
    for ( std::vector<Brick> &brickRow : bricks) {
        for ( Brick &brick : brickRow ) {
            // Contará la colisión solo a los ladrillos activos
            if (brick.getActive())
                brick.collisionWith(ball);
        }
    }

    paddle.collisionWith(ball);
    ball.update();
    paddle.update();
}

void GameManager::drawGame() {

initialWindow.draw();
initialWindow.update();
if(initialWindow.getFlag()){
    if(ball.getLife()>0)
    {
    
    this->score += 1;
    
    ball.draw();
    paddle.draw();
    for ( std::vector<Brick> brickRow : bricks) {
        for ( Brick brick : brickRow ) {
            if (brick.getActive())
                brick.draw();
        }
    }

   
    DrawText(TextFormat("Score: %i", this->score), 10, 10, 20, GREEN);
    DrawText(TextFormat("Lives: %i", ball.getLife()), GetScreenWidth() - 100, 10, 20, GREEN);
    }
    else{
      char gameOverText[34] = "GAME OVER\nPress ENTER to continue";
        Vector2 textSize = MeasureTextEx(GetFontDefault(), gameOverText, 30, 0);
        DrawText(gameOverText, GetScreenWidth() / 2  - textSize.x / 2, GetScreenHeight() / 2 - textSize.y / 2,30, GREEN);
        if (IsKeyDown(KEY_ENTER))
        {
            ball.setLife(3);
        }  
    }

}


 }