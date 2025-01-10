#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath> 

#include "menu.h"
#include "world.hpp"
#include "stats.hpp"
#include "hotbar.h"

static int game_state = 0;

int main() {
    sf::Image logo;
    logo.loadFromFile("resources/logo.png");

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Quadix", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setIcon(logo.getSize().x, logo.getSize().y, logo.getPixelsPtr());

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("resources/background.png");
    backgroundTexture.setSmooth(true);

    global_resources::initialize();
    tile_textures::initialize();
    stats_resources::initialize();

    Menu menu;
    World world;
    FpsCounter fpscounter;
    Hotbar hotbar;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {  // Цикл обработки всех событий
            if (e.type == sf::Event::Closed)
                window.close();

            if (game_state == 0) {
                int menu_ch = menu.button_events(e, window);

                switch (menu_ch) {
                    case 1:
                        game_state = 1;
                        break;

                    case 2:
                        game_state = 2;
                        break;

                    case 3:
                        game_state = 3;
                        break;

                    default:
                        break;
                }
            }

            // Обработка прокрутки колеса мыши для управления хотбаром
            if (game_state == 1) {
                if (e.type == sf::Event::MouseWheelScrolled) {
                    hotbar.handleScroll(e.mouseWheelScroll.delta > 0 ? -1 : 1);
                    std::cout << "MouseWheelScrolled delta: " << e.mouseWheelScroll.delta << std::endl;
                }
            }
        }

        window.clear(sf::Color(135, 206, 235));

        switch (game_state) {
            case 0:
                window.draw(menu);
                break;

            case 1:
                window.draw(world);

                //std::cout << "Mouse position: " << world.mouse_on(window)[0] << " : " << world.mouse_on(window)[1] << std::endl;

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    world.replace_tile(world.mouse_on(window), TEXTURE_STONE);
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    world.replace_tile(world.mouse_on(window), TEXTURE_AIR);
                }

                window.draw(hotbar); // Рисуем хотбар

                world.update();

                break;

            default:
                break;
        }

        fpscounter.update();
        window.draw(fpscounter);

        window.display();
    }

    return 0;
}
