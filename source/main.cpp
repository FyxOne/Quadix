#include <SFML/Graphics.hpp>
#include <iostream>

#include "menu.h"

int main() {
    sf::Image logo;
    logo.loadFromFile("resources/logo.png");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Quadix", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setIcon(logo.getSize().x, logo.getSize().y, logo.getPixelsPtr());

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("resources/background.png");
    backgroundTexture.setSmooth(true);

    global_resources::initialize();

    Menu menu;

    while (window.isOpen()) {
        sf::Event e;
        if(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                window.close();

            int menu_ch = menu.button_events(e, window);

            switch (menu_ch)
            {
            case 1:
                std::cout << "ASd" << std::endl; break;
                break;
            case 2:
                std::cout << "ASD" << std::endl; break;
            case 3:
                std::cout << "ASDKJHA" << std::endl; break;
            default:
                break;
            }
        }

        window.clear();

        window.draw(menu);

        window.display();
    }

    return 0;
}
