/*
CLASE: GameManager
INTENCIÓN: El GameManager se encarga de la administración del juego en general.
RELACIONES: Contiene todos los objetos de las clases (Ball, Paddle, Brick).

*/
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
    int score;
public:
    //Constructor.
    GameManager(int screenWidth, int screenHeight);
    
    //
    void updateGame();
    void drawGame();
    bool isGameOver();
    bool isGameWon();
};


#endif