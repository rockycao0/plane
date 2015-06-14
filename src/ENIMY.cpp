#include "ENIMY.h"
#include "Texture.h"
#include <cstdlib>
ENIMY::ENIMY()
{
    this->setTexture(Texture::Enemy1);
    int x;
    this->gun.setOwner(this);
    x=ENIMY::random();
    ENIMY::setPosition((float)x,0);
    this->speed.x=0;
    this->speed.y=80;
    ENIMY::stage=0;
    this->bbbb.openFromFile("resources/use_bomb.ogg");
    this->itime=sf::seconds(1.f / 10.f);
    this->life=0;
    this->num=1;
}
int ENIMY::random()
{
    int i;
    i=rand();
    i=i%300;
    return i;
}
void ENIMY::reset()
{

    this->position=this->getPosition();
    if(position.y>=620)
        ENIMY::setPosition(ENIMY::random(),0);
    if(ENIMY::stage)
    {
        this->setTexture(Texture::Enemy1);
        this->speed.y=80;
        ENIMY::setPosition(ENIMY::random(),0);
        ENIMY::stage=0;
        life++;
    }
}
void ENIMY::bomb()
{
    this->setTexture(Texture::Explod);
    this->speed.y=0;
    sf::sleep(this->itime);
    ENIMY::stage=1;
    ENIMY::bbbb.play();
}
int ENIMY::score()
{
    return (ENIMY::life)*10;
}
void ENIMY::fire(sf::Time time)
{
    if(time>sf::seconds(1.f/2.f))
    {
        num=num%10;
        gun.fire(num);
        num=num+1;
    }
}
void ENIMY::liveup()
{
    ENIMY::life=0;
}
