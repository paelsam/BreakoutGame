#include "headers/GameManager.h"
#include <raylib.h>
#include <iostream>


// int main() {

//     const int screenWidth = 800;
//     const int screenHeight = 600;

//     InitWindow(screenWidth, screenHeight, "Breakout");
    
//     SetTargetFPS(60);


//     GameManager game(screenWidth, screenHeight);

//     while (!WindowShouldClose()) {
//         BeginDrawing();
//         ClearBackground(BLACK);
        
//         game.initGame();

//         EndDrawing();
//     }

//     CloseWindow();

//     return 0;

// }

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    //InitAudioDevice();  

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");
    InitAudioDevice();
    Sound sound = LoadSound("src/assets/music/stranger.wav");

     

    PlaySound(sound);

    // NOTE: Be careful, background width must be equal or bigger than screen width
    // if not, texture should be draw more than two times for scrolling effect
    Texture2D background = LoadTexture("src/assets/images/cyberpunk_street_background.png");
    Texture2D midground = LoadTexture("src/assets/images/cyberpunk_street_midground.png");
    Texture2D foreground = LoadTexture("src/assets/images/cyberpunk_street_foreground.png");

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    GameManager game(screenWidth, screenHeight);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 0.1f;
        scrollingMid -= 0.5f;
        scrollingFore -= 1.0f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.width*2) scrollingBack = 0;
        if (scrollingMid <= -midground.width*2) scrollingMid = 0;
        if (scrollingFore <= -foreground.width*2) scrollingFore = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(0x052c46ff));

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

            // Draw midground image twice
            DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

            // Draw foreground image twice
            DrawTextureEx(foreground, (Vector2){ scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(foreground, (Vector2){ foreground.width*2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);

            DrawText("BACKGROUND SCROLLING & PARALLAX", 10, 10, 20, RED);
            DrawText("(c) Cyberpunk Street Environment by Luis Zuno (@ansimuz)", screenWidth - 330, screenHeight - 20, 10, RAYWHITE);
            
            game.initGame();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture
    UnloadTexture(midground);   // Unload midground texture
    UnloadTexture(foreground);  // Unload foreground texture
    UnloadSound(sound);    // Texture unloading
    
//                     // Close window and OpenGL context
    CloseAudioDevice();

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// int main(void)
// {
//     // Initialization
//     //--------------------------------------------------------------------------------------
//     const int screenWidth = 1110;
//     const int screenHeight = 850;

//     InitWindow(screenWidth, screenHeight, "raylib [textures] example - texture loading and drawing");

//     // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
//     Texture2D texture = LoadTexture("src/assets/images/cat.png");        // Texture loading
//     //---------------------------------------------------------------------------------------
//      InitAudioDevice();
//      Sound sound = LoadSound("src/assets/music/stranger.wav");

     

//     PlaySound(sound);

//     // Main game loop
//     while (!WindowShouldClose())    // Detect window close button or ESC key
//     {
//         // Update
//         //----------------------------------------------------------------------------------
//         // TODO: Update your variables here
//         //----------------------------------------------------------------------------------

//         // Draw
//         //----------------------------------------------------------------------------------
        
//         BeginDrawing();

//             ClearBackground(RAYWHITE);

//             DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);

//             DrawText("this IS a texture!", 360, 370, 10, GRAY);

//         EndDrawing();
//         //----------------------------------------------------------------------------------
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     UnloadTexture(texture);   
//     UnloadSound(sound);    // Texture unloading
    
//                     // Close window and OpenGL context
//     CloseAudioDevice();
//     CloseWindow();                
    
//     // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }