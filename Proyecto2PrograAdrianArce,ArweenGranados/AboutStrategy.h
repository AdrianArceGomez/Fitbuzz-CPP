#pragma once
#include "ButtonStrategy.h"
#include <SFML/Graphics.hpp>

class AboutStrategy : public ButtonStrategy {
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text infoText;
    sf::RectangleShape infoBox;

public:
    AboutStrategy(sf::RenderWindow& window);
    void execute() override;

private:
    void setupAboutInfoBox();
    void closePalette(sf::RenderWindow& window, sf::Event event);
};