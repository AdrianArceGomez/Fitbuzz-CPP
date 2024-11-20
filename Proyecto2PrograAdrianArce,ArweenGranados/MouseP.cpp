#include "MouseP.h"

sf::Vector2f MousePositionProvider::getMousePosition(const sf::RenderWindow& window) {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    return window.mapPixelToCoords(pixelPos);
}