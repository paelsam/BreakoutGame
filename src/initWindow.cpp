#include "headers/initWindow.h"

initWindow::initWindow(){

        //buttonBounds = { 100, 100, 200, 50 }; 
    buttonPressed = false;
    flag=false;
    buttonBounds.width = 100;
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
    DrawRectangleRec(buttonBounds, buttonPressed ? DARKGREEN : LIME);
    DrawText("INICIAR!", buttonBounds.x + 10, buttonBounds.y + 10, 20, buttonPressed ? DARKGRAY : WHITE);

    }
    
}

bool initWindow::getFlag(){
    return flag;
}



