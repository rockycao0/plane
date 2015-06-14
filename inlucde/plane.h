#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED
#include "Texture.h"
#include "gun.h"

class Plane:public sf::Sprite
{
public:
    void fire(int i);
    GUN gun;
    sf::Vector2f speed;

};
#endif // PLANE_H_INCLUDED
