#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class TouristPoint {
private:
	string pointName;
	Vector2f pointCords;
	Color pointColor;
	CircleShape pointShape;

public:
	TouristPoint(const string& name, const Vector2f& cords, const Color& color, float radius = 10.0f);
	TouristPoint() = default;

	void setPosition(const Vector2f& cords);
	void setColor(const Color& color);
	void setName(const string& name);

	string getName() const;
	Vector2f getPosition() const;
	Color getColor() const;

	void drawTouristPoint(RenderWindow& window) const;
	bool isClicked(const Vector2i& mousePos, const RenderWindow& window) const;
	bool isHovered(const RenderWindow& window) const;

	string toCSV();
	static TouristPoint stringToTouristPoint(const string& name, const string& details);
};