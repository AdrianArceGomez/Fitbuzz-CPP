#pragma once
#include "DoublyLinkedList.h"
#include "PointTurist.h"
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

class Rout {
private:
    string name;
    DoublyLinkedList<TouristPoint> points;

    Vector2f cubicInterpolate(float t, Vector2f p0, Vector2f p1, Vector2f p2, Vector2f p3);
    void drawRoutName(RenderWindow& window);

public:
    Rout() = default;
    Rout(const string& name);

    string getName() const;
    DoublyLinkedList<TouristPoint>& getPoints();


    void setName(const string& name);
    void addPoint(const TouristPoint& point);
    void removePoint(int index);
    void editPoint(int index, const TouristPoint& newPoint);

    void drawRout(RenderWindow& window);
    void drawConnectedCurve(sf::RenderWindow& window);

    string toCSV();
};