#include "Colors.h"
using namespace sf;

ColorPalette::ColorPalette()
    : paletteWindow(sf::VideoMode(300, 150), "Color Palette"), colorSelected(false) {
    Color colors[10] = {
        Color(80, 200, 120), Color(65, 105, 225), Color(238, 130, 238),
        Color(255, 127, 80), Color(0, 255, 255), Color(112, 128, 144),
        Color(255, 0, 255), Color::Black, Color(255, 165, 0),
        Color(128, 0, 128)
    };

    float boxSize = 50.0f;
    float padding = 10.0f;
    for (int i = 0; i < 10; ++i) {
        colorBoxes[i].setSize(sf::Vector2f(boxSize, boxSize));
        colorBoxes[i].setFillColor(colors[i]);
        colorBoxes[i].setPosition(padding + (i % 5) * (boxSize + padding), padding + (i / 5) * (boxSize + padding));
    }
}

bool ColorPalette::openPalette() {
    while (paletteWindow.isOpen()) {
        handleEvents();
        renderPaletteWindow();
    }
    return colorSelected;
}

sf::Color ColorPalette::getSelectedColor() const {
    return selectedColor;
}

void ColorPalette::handleEvents() {
    Event event;
    while (paletteWindow.pollEvent(event)) {
        if (event.type == Event::Closed) {
            paletteWindow.close();
            return;
        }

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            handleMouseClick();
            return;
        }
    }
}

void ColorPalette::handleMouseClick() {
    Vector2i mousePos = Mouse::getPosition(paletteWindow);
    for (int i = 0; i < 10; ++i) {
        if (colorBoxes[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
            selectedColor = colorBoxes[i].getFillColor();
            colorSelected = true;
            paletteWindow.close();
            return;
        }
    }
}

void ColorPalette::renderPaletteWindow() {
    paletteWindow.clear(Color(220, 220, 220));
    for (int i = 0; i < 10; ++i) {
        paletteWindow.draw(colorBoxes[i]);
    }
    paletteWindow.display();
}