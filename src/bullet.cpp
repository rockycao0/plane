#include "bullet.h"
#include "Texture.h"
Bullet::Bullet(float x,float y)
{
    this->setTexture(Texture::BULLET);
    this->setPosition(x, y);
}

void Bullet::fire()
{
    this->move(0,-10);
}
