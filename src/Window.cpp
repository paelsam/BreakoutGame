#include "headers/Window.h"

Window::Window(){
    buttonPressed = false;
    flag = false;
}

void Window::update(){

if (CheckCollisionPointRec(GetMousePosition(), buttonBounds)) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        buttonPressed = true;
    else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && buttonPressed) {
        flag = true;
        buttonPressed = false;
                
    }
} else
    buttonPressed = false;
}

void Window::drawButton(char textButton[], int width, int height){
    if ( flag == false ) {
        buttonBounds.width = width;
        buttonBounds.height = height;
        buttonBounds.x = GetScreenWidth() / 2 - buttonBounds.width / 2;
        buttonBounds.y = GetScreenHeight() /  2 - buttonBounds.height / 2;
        Vector2 buttonSize = MeasureTextEx(GetFontDefault(), textButton, 20, 0);
        DrawRectangleRec(buttonBounds, buttonPressed ? DARKGREEN : LIME);
        DrawText(textButton, buttonBounds.x + (buttonSize.x / 20) / 2 ,  buttonBounds.y + (buttonSize.y / 20) / 2 , 20, buttonPressed ? DARKGRAY : WHITE);
    }
    
}

void Window::draw() {}

bool Window::getFlag(){
    return this->flag;
}

void Window::setFlag(bool flag) {
    this->flag = flag;
}


