/*
    ATTENTION!
    PROKLYATO!
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

struct stats_resources
{
    static sf::Font font;

    static void initialize();
};

class FpsCounter : public sf::Drawable
{
    sf::Text text;

    unsigned int mFrame, mFps;
    sf::Clock mClock;
public:
    FpsCounter();
    FpsCounter(sf::Vector2f position);

    void update();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};