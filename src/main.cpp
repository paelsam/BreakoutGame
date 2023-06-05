#include "headers/GameManager.h"
#include "headers/initWindow.h"
#include <raylib.h>


int main() {

    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Breakout");
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


