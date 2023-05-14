#include "raylib.h"
#include "Ball.h"
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{

private:
    int screenWidth;
    int screenHeight;
    int score;
    int bricksLeft;

public:
    GameManager(int screendWidth, int screenHeight);
    void update();
    void draw();
    void win();
    void gameOver();
};

#endif