#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Texture:public sf::Texture
{
public:
    static sf::Texture Fighter;
    static sf::Texture figb;
    static sf::Texture Enemy1;
    static sf::Texture Enemy2;
    static sf::Texture Explod;
    static sf::Texture SKY;
    static sf::Texture BULLET;
    static sf::Texture Gameover;
    static sf::Texture MISSION;
    static sf::Texture BOSS;
    static void load();
};
#endif // TEXTURE_H_INCLUDED
