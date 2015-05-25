#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game
{
    public:
        int game();
        void run();
    private:
        void             processEvents();
        void             update();
        void             render();
    private:
        sf::RenderWindow window;
        sf::Texture plane;
        sf::Sprite palyer;
};

#endif // GAME_H_INCLUDED
