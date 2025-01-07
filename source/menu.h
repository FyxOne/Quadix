#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

// Класс кнопки
class Button {
public:
    sf::RectangleShape shape;
    sf::Text text;

    Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& label, sf::Font& font, unsigned int charSize);
    bool isMouseOver(const sf::Vector2i& mousePos) const;
};

// Функция для отображения главного меню
void runMainMenu(sf::RenderWindow& window, const sf::Texture& backgroundTexture, sf::Font& font);

#endif // MENU_H
