#include "TextInputWindow.h"

TextInputWindow::TextInputWindow(sf::Font& font) : font(font) {}

std::string TextInputWindow::open() {
    setupWindow();
    setupInputBox();

    std::string textContent;
    while (window.isOpen()) {
        handleEvents(textContent);
        render(textContent);
    }

    return textContent;
}

void TextInputWindow::setupWindow() {
    window.create(sf::VideoMode(400, 200), "Entrada de Texto");
}

void TextInputWindow::setupInputBox() {
    inputBox.setSize(sf::Vector2f(380, 50));
    inputBox.setPosition(10, 75);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Blue);
    inputBox.setOutlineThickness(2);

    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::Red);
    inputText.setPosition(15, 85);
}

void TextInputWindow::handleEvents(std::string& textContent) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered) {
            handleTextInput(event, textContent);
        }
    }
}

void TextInputWindow::handleTextInput(const sf::Event& event, std::string& textContent) {
    if (event.text.unicode == '\b') {
        if (!textContent.empty()) textContent.pop_back();
    }
    else if (event.text.unicode == '\r') {
        window.close();
    }
    else if (event.text.unicode < 128 && textContent.size() < 12) {
        textContent += static_cast<char>(event.text.unicode);
    }
    inputText.setString(textContent);
}


void TextInputWindow::render(const std::string& textContent) {
    window.clear(sf::Color(150, 150, 150));
    window.draw(inputBox);
    window.draw(inputText);
    window.display();
}