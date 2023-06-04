#include "headers/GameManager.h"
#include <raylib.h>

int main() {

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Breakout");
    SetTargetFPS(60);

    GameManager game(screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        game.updateGame();
        game.drawGame();

        EndDrawing();
    }

    CloseWindow();

    return 0;

}