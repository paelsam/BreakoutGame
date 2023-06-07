#include "headers/GameManager.h"
#include <iostream>

GameManager::GameManager(int screenWidth, int screenHeight) : 
    screenWidth(screenWidth),
    screenHeight(screenHeight),
    ball((Vector2){ static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 }, (Vector2){4, 4}, 15, DARKPURPLE ),
    paddle((Vector2){ static_cast<float>(screenWidth) / 2 - 50, static_cast<float>(screenHeight) - 50}, 100, 20, 7, DARKGRAY),
    bricksRows(5),
    bricksColums(20),
    lives(3)
    
{
    this->gameOverSound = LoadSound("src/assets/music/Score.ogg");
    this->gameState = 1;
    inactiveBricks=0;
    initBricks();
}

void GameManager::updateGame() {

    // Check brick collision with ball 
    for ( std::vector<Brick> &brickRow : bricks) {
        for ( Brick &brick : brickRow ) {
            // Contará la colisión solo a los ladrillos activos
            if (brick.getActive()){
                brick.collisionWith(ball);
            }
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


    DrawText(TextFormat("Score: %i", ball.getBrickCollitions()), 10, 10, 20, GREEN);
    DrawText(TextFormat("Lives: %i", this->lives), GetScreenWidth() - 100, 10, 20, GREEN);
}

void GameManager::initBricks() {
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


bool GameManager::isGameOver() {
    if ( lives <= 0 ) 
        return true;
    return false;
}

bool GameManager::isGameWon() {
    if (this->ball.getBrickCollitions() == bricksRows * bricksColums-2 * bricksRows)
        return true;
    return false;
}


void GameManager::initGame() {



    if ( this->gameState == 1 ) {
        this->score = inactiveBricks;
        drawText("BREAKOUT!", 50, 0, RAYWHITE);
        drawText("Juego hecho a las carreras XD", 30, 10, RAYWHITE);
        drawText("Hecho por:", 20, 10, RAYWHITE);
        if ( IsKeyPressed(KEY_ENTER) ) {
            this->gameState = 2;
        }
    } 
    
    if ( this->gameState == 2 ) {
        updateGame();
        drawGame();
        if ( isGameWon() ) {
            this->gameState = 3;
        }
        else if ( isGameOver() )
            this->gameState = 4;
    }

    if ( this->gameState == 3 ) {
        PlaySound(gameOverSound);
        drawText("HAZ GANADO!", 30, 0, RAYWHITE);
        if ( IsKeyPressed(KEY_ENTER) ) {
            if ( reset() )
                this->gameState = 2;
        }
    } 
    
    if (this->gameState == 4){
        PlaySound(gameOverSound);
        drawText("GAME OVER", 30, 0, RAYWHITE);
        if ( IsKeyPressed(KEY_ENTER) ) {
            reset();
            this->gameState = 2;
        }
    } 
}

void GameManager::drawText(std::string text, int fontSize , int spacing, Color color) {
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), fontSize, spacing);
    DrawText(text.c_str(), GetScreenWidth() / 2 - textSize.x / 2, (GetScreenHeight() / 2 - textSize.y / 2), fontSize, color );
}

bool GameManager::reset() {
    this->lives = 3;
    this->inactiveBricks = 0;
    this->score = this->inactiveBricks;
    this->ball.setBrickCollitons(0);

    ball.setPosition({ static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 });
    float speed_choices[2]={1.0f,-1.0f};
    float speedX = speed_choices[GetRandomValue(0,1)];
    ball.setSpeed({ static_cast<float>(speedX) * ball.getSpeed().x,  ball.getSpeed().y });
    
    paddle.setPosition({ static_cast<float>(screenWidth) / 2 - 50, static_cast<float>(screenHeight) - 50 });

    for ( std::vector<Brick> &brickRow : this->bricks) {
        for ( Brick &brick : brickRow ) {
            brick.setActive(true);
            std::cout << brick.getActive() << std::endl;
        }
    }
    return true;
}