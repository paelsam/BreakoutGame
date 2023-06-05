#include "GameObject.h"
#include "Ball.h"
#ifndef INIT_WINDOW_H
#define INIT_WINDOW_H

class initWindow : public GameObject {
    private: ;
        Color color;
        bool flag;
        Rectangle buttonBounds; 
        bool buttonPressed;
        //! Durability
    public: 
        initWindow();
        virtual void draw();
        virtual void update();
        bool getFlag();

};


#endif
