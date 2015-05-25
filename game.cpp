#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
Game::game()
: Window(sf::VideoMode(640, 480), "SFML work") ,
Player()
{
    sf::Texture plane;
    plane.loadFromFile("icon72x72.png");
    sf::Sprite palyer(plane);
}
