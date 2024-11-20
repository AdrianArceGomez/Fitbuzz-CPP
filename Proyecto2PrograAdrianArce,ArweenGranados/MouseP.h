#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class MousePositionProvider {
public:
    static sf::Vector2f getMousePosition(const sf::RenderWindow& window);
};