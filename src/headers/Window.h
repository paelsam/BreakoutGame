/*
CLASE : Window.
INTENCIÓN: Es la pantalla de inicio y gameover
RELACIÓN: Es parecido/ hereda de GameObject 

*/
#include "GameObject.h"
#ifndef WINDOW_H
#define WINDOW_H

class Window : public GameObject {
    private: 
        Color color;
        bool flag;
        Rectangle buttonBounds; 
        bool buttonPressed;
        
    public: 
        //Constructor.
        Window();

        //Dibuja la pantalla de inicio.
        virtual void draw();
        void drawButton(char textButton[], int width, int height);

        //Actualiza la pantalla hacia la siguiente interfaz.
        virtual void update();

        //Avisa el GameManager que el botton iniciar debe desaparecer al momento de cambiar la interfaz de juego.
        bool getFlag();

        void setFlag(bool flag);


};


#endif
