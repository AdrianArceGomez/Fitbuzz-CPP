#pragma once
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class ColorPalette {
private:
    RenderWindow paletteWindow;
    RectangleShape colorBoxes[10];
    Color selectedColor;
    bool colorSelected;

public:
    ColorPalette();
    bool openPalette();
    Color getSelectedColor() const;
    void handleEvents();
    void handleMouseClick();
    void renderPaletteWindow();
};