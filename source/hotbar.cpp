#include "hotbar.h"

Hotbar::Hotbar()
    : selectedSlot(0)
{
    // Загрузка текстур
    if (!hotbarTexture.loadFromFile("resources/hotbar.png") || 
        !selectorTexture.loadFromFile("resources/hotbar_selector.png")) {
        throw std::runtime_error("Failed to load hotbar textures!");
    }

    // Установка текстур для спрайтов
    hotbarSprite.setTexture(hotbarTexture);
    selectorSprite.setTexture(selectorTexture);

    // Увеличиваем масштаб
    float scaleFactor = 7.0f; // Увеличиваем размер в 3 раза
    hotbarSprite.setScale(scaleFactor, scaleFactor);
    selectorSprite.setScale(scaleFactor, scaleFactor);

    // Центрируем хотбар
    float cellWidth = (hotbarTexture.getSize().x / 9.0f) * hotbarSprite.getScale().x;
    hotbarSprite.setPosition(1280 / 2 - (cellWidth * 4.5f), 650);

    // Устанавливаем позицию селектора
    updateSelectorPosition();
}

void Hotbar::updateSelectorPosition()
{
    float cellWidth = (hotbarTexture.getSize().x / 9.0f) * hotbarSprite.getScale().x;
    selectorSprite.setPosition(
        hotbarSprite.getPosition().x + selectedSlot * cellWidth,
        hotbarSprite.getPosition().y
    );
}

void Hotbar::handleScroll(int direction)
{
    selectedSlot = (selectedSlot + direction + 9) % 9; // Переключаемся между 0 и 8
    updateSelectorPosition();
}

void Hotbar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(hotbarSprite);
    target.draw(selectorSprite);
}
