#include "plane.h"
#include "gun.h"
#include "texture.h"
GUN::GUN()
{
    for(int i=0;i<20;i++)
    {
        this->bullet[i].setTexture(Texture::BULLET);
    }
    this->time=sf::seconds(2.0f);
}
sf::Sprite GUN::fire(int i)
{
    sf::Vector2f pos = ((this->owner)->getPosition());
    this->bullet[i].setPosition(pos.x+18,pos.y+30);
    return bullet[i];
}
sf::Vector2f GUN::getPosition()
{
    sf::Vector2f position;
    return position;
}

void GUN::setOwner(Plane * owner)
{
    this->owner = owner;
}
void GUN::clean(int i)
{
    this->bullet[i].setPosition(800.f,1000.f);
}
void GUN::update(sf::Time dt)
{
    this->time=dt;
}
int GUN::bomp(sf::Sprite plane)
{
    int num,x,y;
    num=0;
    sf::Vector2f pos1;
    sf::Vector2f pos2;
    pos2=plane.getPosition();
    for(int i=0;i<20;i++)
    {
        pos1=this->bullet[i].getPosition();
        x=pos1.x-pos2.x;
        y=pos1.y-pos2.y;
        if(x>0&&x<80&&y<40&&y>0)
        {
            num=1;
            GUN::clean(i);
        }
    }
    if(num>0)
        return 1;
    else
        return 0;
}
void GUN::cleanup()
{
    for(int i=0;i<20;i++)
    {
        GUN::clean(i);
    }
}
