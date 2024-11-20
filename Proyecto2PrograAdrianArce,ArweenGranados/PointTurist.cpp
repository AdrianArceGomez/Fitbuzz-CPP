#include "PointTurist.h"
#include <iostream>
using namespace sf;
using namespace std;

TouristPoint::TouristPoint(const string& name, const Vector2f& cords, const Color& color, float radius)
	: pointName(name), pointCords(cords), pointColor(color), pointShape(radius) {
	pointShape.setPosition(pointCords);
	pointShape.setFillColor(pointColor);
	pointShape.setOrigin(radius, radius);
}

void TouristPoint::setPosition(const Vector2f& cords)
{}

void TouristPoint::setColor(const Color& color) {
	pointColor = color;
	pointShape.setFillColor(pointColor);
}

void TouristPoint::setName(const std::string& name) {
	pointName = name;
}

string TouristPoint::getName() const {
	return pointName;
}

Vector2f TouristPoint::getPosition() const {
	return pointCords;
}

Color TouristPoint::getColor() const {
	return pointColor;
}


bool TouristPoint::isClicked(const Vector2i& mousePos, const RenderWindow& window) const {
	Vector2f worldPos = window.mapPixelToCoords(mousePos);

	float distance = sqrt(pow(worldPos.x - pointCords.x, 2) + pow(worldPos.y - pointCords.y, 2));

	return distance <= pointShape.getRadius();
}

bool TouristPoint::isHovered(const RenderWindow& window) const {
	Vector2i mousePos = Mouse::getPosition(window);
	FloatRect bounds = pointShape.getGlobalBounds();
	return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}


string TouristPoint::toCSV() {
	return pointName + "," +
		to_string(pointCords.x) + ";" + to_string(pointCords.y) + "," +
		to_string(pointColor.r) + ";" + to_string(pointColor.g) + ";" + to_string(pointColor.b) + ",";
}

TouristPoint TouristPoint::stringToTouristPoint(const string& name, const string& details) {
	size_t pos = 0;

	pos = details.find(";");
	float x = stof(details.substr(0, pos));
	size_t coordsPos = pos + 1;
	pos = details.find(",", coordsPos);
	float y = stof(details.substr(coordsPos, pos - coordsPos));

	size_t colorPos = pos + 1;
	pos = details.find(";", colorPos);
	int r = stoi(details.substr(colorPos, pos - colorPos));
	colorPos = pos + 1;
	pos = details.find(";", colorPos);
	int g = stoi(details.substr(colorPos, pos - colorPos));
	colorPos = pos + 1;
	int b = stoi(details.substr(colorPos));

	return TouristPoint(name, sf::Vector2f(x, y), sf::Color(r, g, b));
}

void TouristPoint::drawTouristPoint(RenderWindow& window) const {
	window.draw(pointShape);

	if (isHovered(window)) {
		Font font;
		if (!font.loadFromFile("Stardew Valley Regular.ttf")) {
			std::cerr << "Error al cargar la fuente\n";
			return;
		}

		Text nameText;
		nameText.setFont(font);
		nameText.setString(pointName);
		nameText.setCharacterSize(24);
		nameText.setFillColor(Color::White);

		FloatRect textBounds = nameText.getLocalBounds();
		nameText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height);
		nameText.setPosition(pointCords.x, pointCords.y - pointShape.getRadius() - 10);

		window.draw(nameText);
	}
}