#include "menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("resources/background.png")) {
        std::cerr << "Error: Could not load resources/background.png" << std::endl;
        return -1;
    }
    backgroundTexture.setSmooth(true);

    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Error: Could not load resources/arial.ttf" << std::endl;
        return -1;
    }

    runMainMenu(window, backgroundTexture, font);
    return 0;
}

