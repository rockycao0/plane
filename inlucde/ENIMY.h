#ifndef ENIMY_H_INCLUDED
#define ENIMY_H_INCLUDED
#include "plane.h"
class ENIMY:public Plane
{
public:
    ENIMY();
    GUN gun;
    void reset();
    void bomb();
    int stage;
    int score();
    void fire(sf::Time time);
    void liveup();
private:
    int random();
    sf::Vector2f position;
    sf::Music bbbb;
    sf::Time itime;
    int life;
    int num;
};
#endif // ENIMY_H_INCLUDED
