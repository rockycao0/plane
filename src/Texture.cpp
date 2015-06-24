#include "Texture.h"
sf::Texture Texture::Fighter;
sf::Texture Texture::Enemy1;
sf::Texture Texture::Enemy2;
sf::Texture Texture::Explod;
sf::Texture Texture::BULLET;
sf::Texture Texture::SKY;
sf::Texture Texture::figb;
sf::Texture Texture::Gameover;
sf::Texture Texture::MISSION;
sf::Texture Texture::BOSS;
void Texture::load()
{
    Texture::Fighter.loadFromFile("resources/fighter.png");
    Texture::BULLET.loadFromFile("resources/bullet.png");
    Texture::SKY.loadFromFile("resources/background.png");
    Texture::Enemy1.loadFromFile("resources/Enimy1.png");
    Texture::Explod.loadFromFile("resources/EXPLOD.png");
    Texture::figb.loadFromFile("resources/frib.png");
    Texture::Gameover.loadFromFile("resources/gameover.png");
    Texture::MISSION.loadFromFile("resources/mission.jpg");
    Texture::BOSS.loadFromFile("shoot.png",sf::IntRect(173,733,100,200));
}

