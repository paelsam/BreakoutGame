#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <vector>

#ifndef GAMEMANAGER_H
#define GAMEMANGAER_H

class GameManager
{
private:
    float screenWidth;
    float screenHeight;
    Ball ball;
    Paddle paddle;
    std::vector<std::vector<Brick>> bricks;
    float bricksRows;
    float bricksColums;
    int lives;
public:
    GameManager(int screenWidth, int screenHeight);
    void updateGame();
    void drawGame();
    bool isGameOver();
    bool isGameWon();
};


#endif