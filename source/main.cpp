#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath> 

#include "menu.h"
#include "world.hpp"

int main() {
    sf::Image logo;
    logo.loadFromFile("resources/logo.png");

    sf::RenderWindow window(sf::VideoMode(1200, 700), "Quadix", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setIcon(logo.getSize().x, logo.getSize().y, logo.getPixelsPtr());

    //sf::Texture backgroundTexture;
    //backgroundTexture.loadFromFile("resources/background.png");
    //backgroundTexture.setSmooth(true);

    //global_resources::initialize();
    tile_textures::initialize();

    //Menu menu;
    World world;

    while (window.isOpen()) {
        sf::Event e;
        if(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                window.close();

            //int menu_ch = menu.button_events(e, window);

            //switch (menu_ch)
            //{
            //case 1:
            //    std::cout << "ASd" << std::endl; break;
            //    break;
            //case 2:
            //    std::cout << "ASD" << std::endl; break;
            //case 3:
            //    std::cout << "ASDKJHA" << std::endl; break;
            //default:
            //    break;
            //}
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            world.set_position(-2, 0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            world.set_position(2, 0);
        }

        window.clear(sf::Color(135, 206, 235));

        //window.draw(menu);

        window.draw(world);

        window.display();
    }

    return 0;
}
