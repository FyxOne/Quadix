#include "menu.h"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& label, sf::Font& font, unsigned int charSize) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color(100, 100, 200));

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::White);
    text.setPosition(
        position.x + (size.x - text.getGlobalBounds().width) / 2,
        position.y + (size.y - text.getGlobalBounds().height) / 2
    );
}

bool Button::isMouseOver(const sf::Vector2i& mousePos) const {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

int runMainMenu(sf::RenderWindow& window, const sf::Texture& backgroundTexture, const sf::Font& font) {
    sf::Sprite backgroundSprite(backgroundTexture);

    std::vector<Button> buttons;
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Vector2f(300, 200), "New Game", font, 24);
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Vector2f(300, 300), "Continue", font, 24);
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Vector2f(300, 400), "Settings", font, 24);
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Vector2f(300, 500), "Exit", font, 24);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (size_t i = 0; i < buttons.size(); ++i) {
                    if (buttons[i].isMouseOver(mousePos)) {
                        switch (i) {
                        case 0: std::cout << "New Game clicked" << std::endl; break;
                        case 1: std::cout << "Continue clicked" << std::endl; break;
                        case 2: std::cout << "Settings clicked" << std::endl; break;
                        case 3: window.close(); break;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        for (auto& button : buttons) {
            window.draw(button.shape);
            window.draw(button.text);
        }
        window.display();
    }
    return 0;
}
