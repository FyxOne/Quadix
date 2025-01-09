#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <cmath> 

// Global resources (textures)
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
    // Initialize of button
    Button(sf::Vector2f size, sf::Color color, sf::Vector2f position, sf::String text);

    // Mouse on button?
    bool isMouseOver(const sf::Vector2i& mousePos) const;

    // Draw it
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


// Nukchix moment
class Menu : public sf::Drawable
{
    // Button vector wtf
    std::vector<Button> buttons;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    // Hype
    Menu();
    
    // Logic? Noo...
    int button_events(sf::Event& event, sf::RenderWindow& window);

    // Draw like a pro
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
