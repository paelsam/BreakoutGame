/*
CLASE: GameManager
INTENCIÓN: El GameManager se encarga de la administración del juego en general.
RELACIONES: Contiene todos los objetos de las clases (Ball, Paddle, Brick).

*/
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "initWindow.h"
#include <vector>

#ifndef GAMEMANAGER_H
#define GAMEMANGAER_H

class GameManager
{
private:
    // Ancho de la interfaz del juego.

    float screenWidth;
    
    // Alto de la interfaz del juego.
    float screenHeight;

    Ball ball;
    Paddle paddle;
    std::vector<std::vector<Brick>> bricks;
    float bricksRows;
    float bricksColums;
    int lives;
    int score;

    initWindow initialWindow;
public:
    //Constructor.
    GameManager(int screenWidth, int screenHeight);
    
    //Actualiza el estado del juego en tiempo real.
    void updateGame();

    //Dibuja todas la caracteristicas de la interfaz.
    void drawGame();

    //Saber si el jugador pierde el juego.
    bool isGameOver();

    //Saber si el jugador completa el objetivo.
    bool isGameWon();
};


#endif