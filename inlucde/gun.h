#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED
#include "plane.h"
class Plane;
class GUN
{
public:
    GUN();
    void setOwner(Plane * owner);
    sf::Sprite fire(int i);
    sf::Sprite bullet[20];
    void clean(int i);
    void update(sf::Time dt);
    int bomp(sf::Sprite plane);
    void cleanup();
private:
    sf::Vector2f getPosition();
    Plane* owner;
    sf::Time time;
};
#endif // GUN_H_INCLUDED
