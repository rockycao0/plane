#include "Fighter.h"
#include "Texture.h"
Fighter::Fighter()
{
    this->setTexture(Texture::Fighter);
    this->setPosition(200, 500);
    this->stage=0;
    this->life=3;
}
sf::Vector2f Fighter::left()
{
    Fighter::movement.x=-180;
    this->movement.y=0;
    return movement;
}

sf::Vector2f Fighter::right()
{
    Fighter::movement.x=180;
    this->movement.y=0;
    return movement;
}
sf::Vector2f Fighter::stop()
{
    Fighter::movement.x=0;
    this->movement.y=0;
    return movement;
}
void Fighter::rightset()
{
    this->setPosition(320, 500);
}
void Fighter::leftset()
{
    this->setPosition(0,500);
}
void Fighter::bomb()
{
        this->setTexture(Texture::figb);
        this->speed.x=0;
        sf::sleep(sf::seconds(1.f/5.f));
        Fighter::stage=1;
}
void Fighter::reset()
{
    if (stage==1&&Fighter::life>0)
    {
        this->life=life-1;
        this->stage=0;
        this->setTexture(Texture::Fighter);
        this->setPosition(200, 500);
    }
}
