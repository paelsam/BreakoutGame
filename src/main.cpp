#include "headers/GameManager.h"
#include <raylib.h>
#include <iostream>


int main() {

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Breakout");
    InitAudioDevice();
    SetTargetFPS(60);

    Image image = LoadImage("src/assets/images/background.png");
    Texture2D background = LoadTextureFromImage(image);
    UnloadImage(image);



    GameManager game(screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTexture(background, screenWidth/2 - background.width / 2, screenHeight/2 - background.height / 2, WHITE);

            game.initGame();

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;

}


