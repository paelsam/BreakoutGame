/*
CLASE : Initwindow.
INTENCIÓN: Es la pantalla de inicio para iniciar el juego.
RELACIÓN: Es parecido/ hereda de GameObject 

*/
#include "GameObject.h"
#ifndef INIT_WINDOW_H
#define INIT_WINDOW_H

class initWindow : public GameObject {
    private: ;
        Color color;
        bool flag;
        Rectangle buttonBounds; 
        bool buttonPressed;
    public: 
        //Constructor.
        initWindow();

        //Dibuja la pantalla de inicio.
        virtual void draw();

        //Actualiza la pantalla hacia la siguiente interfaz.
        virtual void update();

        //Avisa el GameManager que el botton iniciar debe desaparecer al momento de cambiar la interfaz de juego.
        bool getFlag();


};


#endif
