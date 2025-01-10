#include "stats.hpp"

sf::Font stats_resources::font;

FpsCounter::FpsCounter()
{
    text.setFont(stats_resources::font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(10, 10);

    mFps = 0;
    mFrame = 0;
}

FpsCounter::FpsCounter(sf::Vector2f position)
{
    text.setFont(stats_resources::font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(position);
}

void FpsCounter::update()
{
    if(mClock.getElapsedTime().asSeconds() >= 1.f)
    {
        mFps = mFrame;
        mFrame = 0;
        mClock.restart();

        std::ostringstream ss;
        ss << mFps;

        text.setString("Frames per seconds: " + ss.str());
    }

    ++mFrame;
}

void FpsCounter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text);
}

void stats_resources::initialize()
{
    font.loadFromFile("resources/arial.ttf");
}
