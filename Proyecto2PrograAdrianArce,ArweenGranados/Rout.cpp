#include "Rout.h"

Rout::Rout(const std::string& name) : name(name) {}

std::string Rout::getName() const {
	return name;
}

DoublyLinkedList<TouristPoint>& Rout::getPoints() {
	return points;
}

void Rout::setName(const std::string& name) {
	this->name = name;
}

void Rout::addPoint(const TouristPoint& point) {
	points.pushBack(point);
}

void Rout::removePoint(int index) {
	if (index >= 0 && index < points.getSize()) {
		points.remove(index);
	}
	else {
		std::cout << "Índice inválido\n";
	}
}

void Rout::editPoint(int index, const TouristPoint& newPoint) {
	if (index >= 0 && index < points.getSize()) {
	}
	else {
		std::cout << "Índice inválido\n";
	}
}

void Rout::drawRout(sf::RenderWindow& window) {

	for (int i = 0; i < points.getSize(); i++) {
		if (points.at(i)) {
			points.at(i)->drawTouristPoint(window);
		}
	}
	drawRoutName(window);

}
void Rout::drawRoutName(sf::RenderWindow& window) {
	sf::Font font;
	if (!font.loadFromFile("Stardew Valley Regular.ttf")) {
		std::cerr << "Error al cargar la fuente\n";
		return;
	}

	sf::Text routeNameText;
	routeNameText.setFont(font);
	routeNameText.setString("Route: " + name);
	routeNameText.setCharacterSize(24);
	routeNameText.setFillColor(sf::Color::White);

	sf::FloatRect textBounds = routeNameText.getLocalBounds();
	routeNameText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top);
	routeNameText.setPosition(window.getSize().x / 2.0f, 10);

	window.draw(routeNameText);

}


sf::Vector2f Rout::cubicInterpolate(float t, sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3) {
	float t2 = t * t;
	float t3 = t2 * t;

	float a0 = -0.5f * t3 + t2 - 0.5f * t;
	float a1 = 1.5f * t3 - 2.5f * t2 + 1.0f;
	float a2 = -1.5f * t3 + 2.0f * t2 + 0.5f * t;
	float a3 = 0.5f * t3 - 0.5f * t2;

	return p0 * a0 + p1 * a1 + p2 * a2 + p3 * a3;
}

void Rout::drawConnectedCurve(sf::RenderWindow& window) {
	int numPoints = points.getSize();
	if (numPoints < 2) {
		return;
	}

	std::vector<sf::Vertex> curvePoints;
	for (int i = 0; i < numPoints - 1; ++i) {
		sf::Vector2f p0 = (i > 0) ? points.at(i - 1)->getPosition() : points.at(i)->getPosition();
		sf::Vector2f p1 = points.at(i)->getPosition();
		sf::Vector2f p2 = points.at(i + 1)->getPosition();
		sf::Vector2f p3 = (i + 2 < numPoints) ? points.at(i + 2)->getPosition() : points.at(i + 1)->getPosition();

		for (float t = 0; t <= 1; t += 0.05f) {
			sf::Vector2f point = cubicInterpolate(t, p0, p1, p2, p3);
			curvePoints.push_back(sf::Vertex(point, sf::Color::White));
		}
	}

	if (!curvePoints.empty()) {
		window.draw(&curvePoints[0], curvePoints.size(), sf::LineStrip);
	}
}

std::string Rout::toCSV()
{
	std::string routeString = name + "{\n";


	for (int i = 0; i < points.getSize(); i++)
	{
		routeString += points.at(i)->toCSV() + "\n";
	}


	return routeString + "}\n";
}