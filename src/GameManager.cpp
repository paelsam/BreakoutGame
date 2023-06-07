#include "headers/GameManager.h"
#include <iostream>

GameManager::GameManager(int screenWidth, int screenHeight) : 
    screenWidth(screenWidth),
    screenHeight(screenHeight),
    ball((Vector2){ static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 }, (Vector2){4, 4}, 12, WHITE ),
    paddle((Vector2){ static_cast<float>(screenWidth) / 2 - 50, static_cast<float>(screenHeight) - 50}, 100, 20, 7, BLACK ),
    bricksRows(5),
    bricksColums(20),
    lives(3)
    
{
    this->gameOverSound = LoadSound("src/assets/music/Score.ogg");
    this->gameState = 1;
    this->flag = true;
    this->inactiveBricks = 0;
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


    DrawText(TextFormat("Score: %i", ball.getBrickCollitions()), 10, 10, 20, RAYWHITE);
    DrawText(TextFormat("Lives: %i", this->lives), GetScreenWidth() - 80, 10, 20, RAYWHITE);
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
                rowBricks.push_back(*(new Brick(positionBrick, brickSize, BLACK)));
            else
                rowBricks.push_back(*(new Brick(positionBrick, brickSize, GRAY)));
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

        Image image = LoadImage("src/assets/images/univalle.png");
        Texture2D background = LoadTextureFromImage(image);
        UnloadImage(image);

        DrawTexture(background, 10, 10, RAYWHITE);

        drawText("BREAKOUT!", 50, -100, RAYWHITE);
        drawText("      Hecho por:\nElkin Angulo\nLeonardo Cuadro\nAndres Ortega\nFelipe Figueroa", 30, 50, RAYWHITE);
        drawText("Press ENTER to start", 25, 200, RAYWHITE);

        if ( IsKeyPressed(KEY_ENTER) ) {
            UnloadTexture(background);
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
        if (this->flag) {
            PlaySound(gameOverSound);
            this->flag = false;
        }
        drawText("HAS GANADO!", 30, 0, RAYWHITE);
        drawText(("Score: " + std::to_string(ball.getBrickCollitions())), 20, 30, RAYWHITE);
        drawText("Press ENTER to try again", 25, 100, RAYWHITE);
        if ( IsKeyPressed(KEY_ENTER) ) {
            if ( reset() )
                this->gameState = 2;
        }
    } 
    
    if (this->gameState == 4){
        if (this->flag) {
            PlaySound(gameOverSound);
            this->flag = false;
        }        
        
        drawText("GAME OVER", 30, 0, RAYWHITE);
        drawText(("Score: " + std::to_string(ball.getBrickCollitions())), 20, 30, RAYWHITE);
        drawText("Press ENTER to try again", 25, 60, RAYWHITE);
        if ( IsKeyPressed(KEY_ENTER) ) {
            reset();
            this->gameState = 2;
        }
    } 
}

void GameManager::drawText(std::string text, int fontSize , int spacing, Color color) {
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), fontSize, 0);
    DrawText(text.c_str(), GetScreenWidth() / 2 - textSize.x / 2, (GetScreenHeight() / 2 - textSize.y / 2) + spacing, fontSize, color );
}

bool GameManager::reset() {
    this->lives = 3;
    this->inactiveBricks = 0;
    this->score = this->inactiveBricks;
    this->ball.setBrickCollitons(0);
    this->flag = true;

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