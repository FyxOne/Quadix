#include "menu.h"

static sf::Font font;

Button::Button(sf::Vector2f size, sf::Color color, sf::Vector2f position, sf::String text)
{
    button_shape.setSize(size);
    button_shape.setFillColor(color);
    button_shape.setPosition(position);

    button_text.setFont(font);
    button_text.setString(text);
    button_text.setCharacterSize(size.y/2);

    button_text.setPosition(
        position.x + (size.x - button_text.getGlobalBounds().width) / 2,
        position.y + (size.y - button_text.getGlobalBounds().height) / 2
    );
}

bool Button::isMouseOver(const sf::Vector2i& mousePos) const {
    return button_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(button_shape);
    target.draw(button_text);
}

void global_resources::initialize()
{
    font.loadFromFile("resources/arial.ttf");
}

Menu::Menu()
{
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Color(100, 100, 200), sf::Vector2f(300, 200), "New Game");
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Color(100, 100, 200), sf::Vector2f(300, 300), "Continue");
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Color(100, 100, 200), sf::Vector2f(300, 400), "Settings");
    buttons.emplace_back(sf::Vector2f(200, 50), sf::Color(100, 100, 200), sf::Vector2f(300, 500), "Exit");

    backgroundTexture.loadFromFile("resources/background.png");
    backgroundTexture.setSmooth(true);

    backgroundSprite.setTexture(backgroundTexture);
}

int Menu::button_events(sf::Event &event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (size_t i = 0; i < buttons.size(); ++i) {
            if (buttons[i].isMouseOver(mousePos)) {
                switch (i) {
                    case 0: return 1;
                    case 1: return 2;
                    case 2: return 3;
                    case 3: window.close(); break;
                }
            }
        }
    }

    return 0;
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backgroundSprite);

    for (auto& button : buttons) {
        target.draw(button);
    }
}
