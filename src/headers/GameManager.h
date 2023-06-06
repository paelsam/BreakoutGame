/*
CLASE: GameManager
INTENCIÓN: El GameManager se encarga de la administración del juego en general.
RELACIONES: Contiene todos los objetos de las clases (Ball, Paddle, Brick).

*/
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Window.h"
#include <string>
#include <iostream>
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
    int gameState;
    int inactiveBricks;
    int count=0;
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

    void initGame();

    bool reset();

    //Método para dibujar los ladrillos
    void initBricks();

    // Meotodo para dibujar texto
    void drawText(std::string text, int fontSize, int spacing, Color color);
};


#endif