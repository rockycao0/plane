#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include "plane.h"

class Bullet:public sf::Sprite
{
public:
    public:
    Bullet();
    Bullet(float,float);
    void fire();
};

#endif // BULLET_H_INCLUDED
