#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextInputWindow {
public:
    TextInputWindow(sf::Font& font);

    std::string open();

private:
    sf::RenderWindow window;
    sf::Font& font;
    sf::RectangleShape inputBox;
    sf::Text inputText;

    void setupWindow();
    void setupInputBox();
    void handleEvents(std::string& textContent);
    void handleTextInput(const sf::Event& event, std::string& textContent);
    void render(const std::string& textContent);
};