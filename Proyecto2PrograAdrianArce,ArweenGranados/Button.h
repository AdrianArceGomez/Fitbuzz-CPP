#pragma once
#include <SFML/Graphics.hpp>
#include "ButtonStrategy.h"

using namespace sf;
using namespace std;

class Button
{
private:
	RectangleShape buttonShape;
	Text buttonText;
	Color hoverColor;
	ButtonStrategy* strategy;

	static Font font;
	static unsigned int fontSize;
	static Color defaultTextColor;
	static Color defaultButtonColor;
	static Vector2f defaultSize;

public:
	Button(float x, float y, const string& text);

	void drawButton(RenderWindow& window);

	bool isClicked(const Vector2i& mousePos, RenderWindow& window);

	void setFillColor(const Color& color);

	static void initializeButtonShape(Color buttonColor, Vector2f sizeButton);

	static void initializeButtonText(const string& fontPath, unsigned int size, Color textColor);

	bool isHovered(const RenderWindow& window);

	void setButtonPosition(float x, float y) {
		buttonShape.setPosition(x, y);

		buttonText.setPosition(x + defaultSize.x / 2.0f, y + defaultSize.y / 2.0f);
	}

	Vector2f getPosition() {
		return buttonShape.getPosition();
	};

	void moveButton(Vector2f targetPos, float displacementSpeed, float deltaTime) {

		if (buttonShape.getPosition().x < targetPos.x) {
			buttonShape.move(displacementSpeed * deltaTime, 0);
			buttonText.move(displacementSpeed * deltaTime, 0);
		}
		else if (buttonShape.getPosition().x > targetPos.x) {
			buttonShape.move(-displacementSpeed * deltaTime, 0);
			buttonText.move(-displacementSpeed * deltaTime, 0);
		}

		if (buttonShape.getPosition().y < targetPos.y) {
			buttonShape.move(0, displacementSpeed * deltaTime);
			buttonText.move(0, displacementSpeed * deltaTime);
		}
		else if (buttonShape.getPosition().y > targetPos.y) {
			buttonShape.move(0, -displacementSpeed * deltaTime);
			buttonText.move(0, -displacementSpeed * deltaTime);
		}
	}


	Button() = default;
};
