#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <cmath> 

struct global_resources
{
    static void initialize();
};

// Full Recreation of button :D
class Button : public sf::Drawable
{
    sf::RectangleShape button_shape;
    sf::Text button_text;

public:
    Button(sf::Vector2f size, sf::Color color, sf::Vector2f position, sf::String text);

    bool isMouseOver(const sf::Vector2i& mousePos) const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class Menu : public sf::Drawable
{
    std::vector<Button> buttons;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    Menu();
    
    int button_events(sf::Event& event, sf::RenderWindow& window);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
