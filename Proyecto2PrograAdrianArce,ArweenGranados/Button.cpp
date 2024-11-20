#include "Button.h"

sf::Font Button::font;
using namespace sf;
using namespace std;
unsigned int Button::fontSize = 15;
Color Button::defaultTextColor = Color::Black;
Color Button::defaultButtonColor = Color(255, 224, 178);
Vector2f Button::defaultSize = Vector2f(200.0f, 50.0f);

Button::Button(float x, float y, const string& text) : strategy(nullptr) {
	font.loadFromFile("Stardew Valley Regular.ttf");
	buttonShape.setSize(defaultSize);
	buttonShape.setPosition(x, y);
	buttonShape.setFillColor(Color(255, 224, 178));

	hoverColor = Color(255, 204, 204);

	buttonText.setString(text);
	buttonText.setFont(font);
	buttonText.setCharacterSize(fontSize);
	buttonText.setFillColor(defaultTextColor);
	buttonText.setStyle(Text::Bold);

	FloatRect textBounds = buttonText.getLocalBounds();
	buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	buttonText.setPosition(x + defaultSize.x / 2.0f, y + defaultSize.y / 2.0f);
}

void Button::drawButton(RenderWindow& window) {
	window.draw(buttonShape);
	window.draw(buttonText);
}

bool Button::isClicked(const Vector2i& mousePos, RenderWindow& window) {
	return buttonShape.getGlobalBounds().contains(window.mapPixelToCoords(mousePos));
}

void Button::setFillColor(const Color& color) {
	buttonShape.setFillColor(color);
}

void Button::initializeButtonShape(Color buttonColor, Vector2f sizeButton) {
	defaultButtonColor = buttonColor;
	defaultSize = sizeButton;
}

void Button::initializeButtonText(const string& fontPath, unsigned int size, Color textColor) {
	font.loadFromFile(fontPath);
	fontSize = size;
	defaultTextColor = textColor;
}

bool Button::isHovered(const RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	if (buttonShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
		buttonShape.setFillColor(hoverColor);
		return true;
	}
	else {
		buttonShape.setFillColor(defaultButtonColor);
		return false;
	}
}