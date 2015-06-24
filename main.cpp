#include <iostream>
#include<string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "Texture.h"
#include "Fighter.h"
#include "ENIMY.h"
using namespace std;
string tostr(int score);

int main()
{
    sf::Clock clock;
    sf::Vector2f position;
    sf::RenderWindow window(sf::VideoMode(400, 600), "SFML works");
    //music part
    sf::Music music;
    music.openFromFile("resources/ForTheWin.ogg");
    music.play();
    //
    sf::Font font;
    font.loadFromFile("resources/STHeitiLight.ttc");
    sf::Text text("",font, 30);
    //
    sf::Time time = sf::Time::Zero;
    window.setFramerateLimit(1.f/10.f);
    time = clock.restart();
    sf::Time total=sf::Time::Zero;
    sf::Time dt=sf::seconds(1.f / 2.f);
    //
    Texture::load();
    sf::Sprite SKY(Texture::SKY);
    Fighter fighter;
    fighter.gun.setOwner(&fighter);
    sf::Sprite GAMEOVER(Texture::Gameover);
    sf::Sprite mission(Texture::MISSION);
    ENIMY enimy;
    ENIMY enimy2;
    ENIMY boss;
    boss.isboss();
    enimy2.setPosition(-500.f,400.f);
    int prod=0;
    int i=0;
    int j;
    while (window.isOpen())
    {
        if(fighter.life!=0)
        {
            window.draw(SKY);
        }
        sf::Event event;
        text.setPosition(0.f,0.f);
        text.setString(tostr(enimy.score()+enimy2.score()));
        while (window.pollEvent(event))
        {
            //open window
            if (event.type == sf::Event::Closed)                              //
            {
                window.close();
            }
            //move control
            position=fighter.getPosition();
            if(position.x<=320&&position.x>=-10)
            {
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    fighter.left();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    fighter.right();
                }
                position=fighter.getPosition();
            }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    i=i%20;
                    fighter.fire(i);
                    i++;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            if(position.x>320||position.x<-10)
            {
                fighter.stop();
                if(position.x<0)
                    fighter.leftset();
                else
                    fighter.rightset();
            }
        }
        fighter.move(fighter.movement*time.asSeconds());
        enimy.fire(total);
        enimy2.fire(total);
        if(total>dt)
        {
            total-=dt;
        }
        for(j=0;j<20;j++)
        {
            fighter.gun.bullet[j].move(0,-180*time.asSeconds());
            window.draw(fighter.gun.bullet[j]);
        }
        if(fighter.gun.bomp(enimy))
        {
            enimy.bomb();
        }
        if(fighter.gun.bomp(enimy2))
        {
            enimy2.bomb();
        }
        for(j=0;j<20;j++)
        {
            enimy.gun.bullet[j].move(0,180*time.asSeconds());
            enimy2.gun.bullet[j].move(0,180*time.asSeconds());
            window.draw(enimy.gun.bullet[j]);
            window.draw(enimy2.gun.bullet[j]);
        }
        if(enimy.gun.bomp(fighter)||enimy2.gun.bomp(fighter))
        {
            fighter.bomb();
            enimy.gun.cleanup();
            enimy2.gun.cleanup();
        }
        if(fighter.life!=0)
        {
            enimy.move(0,(enimy.speed.y)*time.asSeconds());
            enimy2.move(0,(enimy.speed.y)*time.asSeconds());
            window.draw(enimy);
            window.draw(enimy2);
            window.draw(text);
            window.draw(fighter);
            sf::sleep(sf::seconds(1.f/25.f));
        }
        else
        {
            window.clear();
            window.draw(GAMEOVER);
        }
        if((enimy.score()+enimy2.score())>99&&(enimy.score()+enimy2.score())<500)
        {
            window.clear();
            window.draw(mission);
            window.display();
            enimy.liveup();
            enimy2.liveup();
            sf::sleep(sf::seconds(1.f));
            fighter.life=3;
            prod+=1;
        }
        if(prod>=5)
        {
            window.draw(boss);
        }
        window.display();
        window.clear();
        total=total+time;
        time = clock.restart();
        enimy.reset();
        enimy2.reset();
        fighter.reset();
    }
    return 0;
}
