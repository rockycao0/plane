#ifndef FIGHTER_H_INCLUDED
#define FIGHTER_H_INCLUDED
#include "plane.h"
class Fighter:public Plane
{
 public:
    Fighter();
    sf::Vector2f left();
    sf::Vector2f right();
    sf::Vector2f stop();
    sf::Vector2f movement;
    void rightset();
    void leftset();
    void bomb();
    int life;
    void reset();
    int stage;
};
#endif // FIGHTER_H_INCLUDED
