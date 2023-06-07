#include "headers/Brick.h"
#include <iostream>
Brick::Brick(Vector2 position, Vector2 size, Color color)
    : rectangle({position.x, position.y, size.x, size.y})
{
    this->sonido = LoadSound("src/assets/music/pingpongbat.ogg");
    this->active = true;
    this->color = color;
   
}

Brick::~Brick(){};

void Brick::update(){};

void Brick::draw()
{
    DrawRectangleRec(rectangle, color);
}

void Brick::collisionWith(Ball &ball)
{
    // Sides of rectangle
    int left = rectangle.x;
    int right = rectangle.x + rectangle.width;
    int top = rectangle.y; 
    int bottom = rectangle.y + rectangle.height;

    // Previus position ball    
    int px = ball.getPosition().x - ball.getSpeed().x;
    int py = ball.getPosition().y - ball.getSpeed().y;

    if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(), rectangle)) {

        if( px < left ) {
            if ( ball.getSpeed().x > 0 )
                ball.setSpeed({ -ball.getSpeed().x, ball.getSpeed().y });
            ball.setPosition({ left - ball.getRadius(), ball.getPosition().y });
        }
        else if( px > right ) {
            if ( ball.getSpeed().x < 0)
                ball.setSpeed({ -ball.getSpeed().x, ball.getSpeed().y });
            ball.setPosition({ right + ball.getRadius(), ball.getPosition().y });
        }
        else if ( py < top ) {
            if ( ball.getSpeed().y > 0)
                ball.setSpeed({ ball.getSpeed().x, -ball.getSpeed().y });
            ball.setPosition({ ball.getPosition().x, top - ball.getRadius() });
            PlaySound(sonido);
        }
        else if ( py > bottom ) {
            if ( ball.getSpeed().y < 0 )
                ball.setSpeed({ ball.getSpeed().x, -ball.getSpeed().y });
            ball.setPosition({ ball.getPosition().x, bottom + ball.getRadius() });
        }
        this->active = false;
        ball.setBrickCollitons(ball.getBrickCollitions()+1);
        
    }
}

bool Brick::getActive()
{
    return this->active;
}

void Brick::setActive( bool active ) 
{
    this->active = active;
}

void Brick::setColor(Color color)
{
    this->color = color;
}

