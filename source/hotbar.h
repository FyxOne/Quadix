#ifndef HOTBAR_H
#define HOTBAR_H

#include <SFML/Graphics.hpp>

class Hotbar : public sf::Drawable
{
private:
    sf::Texture hotbarTexture;
    sf::Sprite hotbarSprite;

    sf::Texture selectorTexture;
    sf::Sprite selectorSprite;

    int selectedSlot = 0; // Выбранный слот (0-8)

    void updateSelectorPosition();

public:
    Hotbar();

    void handleScroll(int direction); // Обработка прокрутки колеса мыши

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // HOTBAR_H