#include "headers/GameManager.h"
#include "headers/initWindow.h"
#include <raylib.h>
#include <iostream>


int main() {

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Breakout");
    InitAudioDevice();
    SetTargetFPS(60);


    GameManager game(screenWidth, screenHeight);

    initWindow window;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        
        game.drawGame();
        game.updateGame();

        EndDrawing();
    }
  
    CloseWindow();

    return 0;

}


