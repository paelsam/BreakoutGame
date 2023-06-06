#include "headers/GameManager.h"
#include <iostream>

GameManager::GameManager(int screenWidth, int screenHeight) : 
    screenWidth(screenWidth),
    screenHeight(screenHeight),
    ball((Vector2){ static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 }, (Vector2){4, 4}, 10, DARKPURPLE ),
    paddle((Vector2){ static_cast<float>(screenWidth) / 2 - 50, static_cast<float>(screenHeight) - 50}, 100, 20, 7, DARKGRAY),
    bricksRows(1),
    bricksColums(20),
    lives(3)
{
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
    
    // Check brick collision with ball 
    for ( std::vector<Brick> &brickRow : bricks) {
        for ( Brick &brick : brickRow ) {
            // Contará la colisión solo a los ladrillos activos
            if (brick.getActive())
                brick.collisionWith(ball);
        }
    }

    if ( ball.getPosition().y + ball.getRadius() >= GetScreenHeight() ) {
        this->lives--;
        ball.setPosition({  static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 });
        float speed_choices[2]={1.0f,-1.0f};
        float speedX = speed_choices[GetRandomValue(0,1)];
        ball.setSpeed({ static_cast<float>(speedX) * ball.getSpeed().x,  ball.getSpeed().y });
    }

    paddle.collisionWith(ball);
    ball.update();
    paddle.update();
}

void GameManager::drawGame() {
    
    ball.draw();
    paddle.draw();
    for ( std::vector<Brick> brickRow : bricks) {
        for ( Brick brick : brickRow ) {
            if (brick.getActive())
                brick.draw();
        }
    }


    DrawText(TextFormat("Score: %i", this->score), 10, 10, 20, GREEN);
    DrawText(TextFormat("Lives: %i", this->lives), GetScreenWidth() - 100, 10, 20, GREEN);
}


bool GameManager::isGameOver() {
    if ( lives == 0 ) 
        return true;
    return false;
}

bool GameManager::isGameWon() {
    int inactiveBricks = 0;
    for ( std::vector<Brick> brickRow : bricks) {
        for ( Brick brick : brickRow ) {
            if (!brick.getActive())
                inactiveBricks += 1;
        }
    } if (inactiveBricks == bricksRows * bricksColums - 2)
        return true;
    std::cout << inactiveBricks << std::endl;
    return false;
}

void GameManager::initGame() {
    

    if ( initialWindow.getFlag() ) {
        updateGame();
        this->score = GetTime();
        drawGame();
    } else {
        initialWindow.update();
        initialWindow.draw();
    }
}