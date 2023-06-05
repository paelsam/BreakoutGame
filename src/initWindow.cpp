#include "headers/initWindow.h"

initWindow::initWindow(){


    buttonPressed = false;
    flag=false;
    buttonBounds.width = 200;
    buttonBounds.height = 50;
    buttonBounds.x = (GetScreenWidth()- buttonBounds.width) / 2;
    buttonBounds.y = (GetScreenHeight() - buttonBounds.height) / 2;

}

void initWindow::update(){

if (CheckCollisionPointRec(GetMousePosition(), buttonBounds))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                buttonPressed = true;
            }
            else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && buttonPressed)
            {
                flag=true;
                buttonPressed = false;
                
                
            }
        }
        else
        {
            buttonPressed = false;
        }

}

void initWindow::draw(){
    if (flag==false){
    char gameOverText[49] = "WELCOME TO BREAKOUT GAME\nPress START to continue";
    Vector2 textSize = MeasureTextEx(GetFontDefault(), gameOverText, 30, 0);
    DrawText(gameOverText, GetScreenWidth() / 2  - textSize.x / 2, GetScreenHeight() / 2 - textSize.y / 2-200,30, GREEN);
    DrawRectangleRec(buttonBounds, buttonPressed ? DARKGREEN : LIME);
    DrawText("START!", buttonBounds.x + 70, buttonBounds.y + 20, 20, buttonPressed ? DARKGRAY : WHITE);

    }
    
}

bool initWindow::getFlag(){
    return flag;
}



