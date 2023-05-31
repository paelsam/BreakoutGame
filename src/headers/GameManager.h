#ifndef _GAMEMANAGER_
#define _GAMEMANAGER_
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"


class GameManager{
    public:
    
    int score;
    Brick *bricks[5][20];
    int initialDownPosition;
    int screenWidth;
    int screenHeight;
    int ROWS,COLUMNS;

    GameManager();
    void updateGame();
    void draw();
    void unloadGame();

    

};
#endif