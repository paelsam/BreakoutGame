#include "GameObject.h"
#ifndef BALL_H
#define BALL_H

class Ball : public GameObject {
    private:
        Vector2 position;
        Vector2 speed;
        float radius;
        Color color;
        bool downCollition;
        int life;
    public: 
        Ball(Vector2 position, Vector2 speed, float radius, Color color);
        void update();
        void draw();
        void bounce();
        Vector2 getPosition();
        void setPosition(Vector2 position);
        Vector2 getSpeed();
        void setSpeed(Vector2 speed);
        float getRadius();
        bool getDownCollition();
        void setDownCollition(bool downCollition);
        void resetBall();
        int getLife();
        void setLife(int life);
};


#endif