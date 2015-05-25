#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 600), "SFML works");
    sf::Texture plane;
    sf::Music music;
    if (!music.openFromFile("game_music.ogg"))
        return -1;
    music.play();
    if (!plane.loadFromFile("fighter.png"))
        return EXIT_FAILURE;
    sf::Texture background;
    background.loadFromFile("background.png");
    sf::Sprite BG(background);
    BG.setPosition(0,0);
    sf::Sprite sprite(plane);
    sprite.setPosition(200,500);
            window.draw(BG);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)                              //
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                sprite.move(-10, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                sprite.move(10, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        window.clear();
          // Draw the sprite
        window.draw(BG);
        window.draw(sprite);
        // Draw the string
        window.display();                                                     //
    }//end while

    return 0;
 }
